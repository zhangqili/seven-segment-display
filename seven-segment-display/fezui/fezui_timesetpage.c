/*
 * fezui_timesetpage.c
 *
 *  Created on: Nov 27, 2023
 *      Author: xq123
 */
#include "fezui.h"
#include "fezui_var.h"

lefl_menu_t timemenu;
const char* timemenu_items[] = {"<Back","Hours","Minutes","Seconds"};
lefl_page_t timesetpage={timesetpage_logic,timesetpage_draw,timesetpage_load};

#define ROW_HEIGHT 16

RTC_TimeTypeDef temptime;

static float start_animation=0;
static bool configing;
void timemenu_cb(void *menu);
void timesetpage_init()
{
    lefl_menu_init(&timemenu, timemenu_items, sizeof(timemenu_items)/sizeof(const char*), timemenu_cb);
}

void timesetpage_logic(void *page)
{
    if(configing)
    {
        fezui_cursor_set(
            &target_cursor ,
            WIDTH-2*6-2,
            timemenu.selected_index*ROW_HEIGHT,
            2*6+2,
            ROW_HEIGHT);
    }
    else
    {
        fezui_cursor_set(
            &target_cursor ,
            0,
            timemenu.selected_index*ROW_HEIGHT,
            strlen(timemenu.items[timemenu.selected_index])*6+6,
            ROW_HEIGHT);
    }
    CONVERGE_TO(start_animation, 1, fezui.speed);
}
void timesetpage_draw(void *page)
{
    u8g2_SetFont(&(fezui.u8g2), u8g2_font_6x13_mf);
    for(uint8_t i=0;i<timemenu.len;i++)
    {
        u8g2_DrawStr(&(fezui.u8g2),3,ROUND((ROW_HEIGHT*(i+1) - 3)*start_animation),timemenu.items[i]);
    }
    sprintf(fezui_buffer,"%02d",temptime.Hours);
    u8g2_DrawStr(&fezui.u8g2, WIDTH-6*2-1, ROUND((ROW_HEIGHT*(2) - 3)*start_animation), fezui_buffer);
    sprintf(fezui_buffer,"%02d",temptime.Minutes);
    u8g2_DrawStr(&fezui.u8g2, WIDTH-6*2-1, ROUND((ROW_HEIGHT*(3) - 3)*start_animation), fezui_buffer);
    sprintf(fezui_buffer,"%02d",temptime.Seconds);
    u8g2_DrawStr(&fezui.u8g2, WIDTH-6*2-1, ROUND((ROW_HEIGHT*(4) - 3)*start_animation), fezui_buffer);
    fezui_draw_cursor(&fezui, &cursor);
}
void timemenu_cb(void *menu)
{

    switch (((lefl_menu_t*)menu)->selected_index)
    {
    case 0:
        lefl_link_frame_go_back(&mainframe);
        break;
    case 1:
    case 2:
    case 3:
        configing=!configing;
        break;
    default:
        break;
    }
}

static void key_up_cb(void*k)
{
    if(configing)
    {
        switch (timemenu.selected_index)
        {
        case 0:
            break;
        case 1:
            VAR_LOOP_INCREMENT(temptime.Hours,0,23,1);
            HAL_RTC_SetTime(&hrtc, &temptime, RTC_FORMAT_BIN);
            break;
        case 2:
            VAR_LOOP_INCREMENT(temptime.Minutes,0,59,1);
            HAL_RTC_SetTime(&hrtc, &temptime, RTC_FORMAT_BIN);
            break;
        case 3:
            VAR_LOOP_INCREMENT(temptime.Seconds,0,59,1);
            HAL_RTC_SetTime(&hrtc, &temptime, RTC_FORMAT_BIN);
            break;
        default:
            break;
        }
    }
    else
    {
        lefl_menu_index_increase(&timemenu, 1);
    }
}
static void key_down_cb(void*k)
{
    if(configing)
    {
        switch (timemenu.selected_index)
        {
        case 0:
            break;
        case 1:
            VAR_LOOP_DECREMENT(temptime.Hours,0,23,1);
            HAL_RTC_SetTime(&hrtc, &temptime, RTC_FORMAT_BIN);
            break;
        case 2:
            VAR_LOOP_DECREMENT(temptime.Minutes,0,59,1);
            HAL_RTC_SetTime(&hrtc, &temptime, RTC_FORMAT_BIN);
            break;
        case 3:
            VAR_LOOP_DECREMENT(temptime.Seconds,0,59,1);
            HAL_RTC_SetTime(&hrtc, &temptime, RTC_FORMAT_BIN);
            break;
        default:
            break;
        }
    }
    else
    {
        lefl_menu_index_increase(&timemenu, -1);
    }
}
void timesetpage_load(void *page)
{
    fezui_cursor_set(
            &cursor ,
            0,
            0,
            0,
            0);
    key.key_cb[0]=LAMBDA(void,(void*k){lefl_menu_click(&timemenu);});
    key_up.key_cb[0]=key_up_cb;
    key_down.key_cb[0]=key_down_cb;
    timemenu.selected_index=0;
    start_animation=0;
    HAL_RTC_GetTime(&hrtc, &temptime, RTC_FORMAT_BIN);
}


