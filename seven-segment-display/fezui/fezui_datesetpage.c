/*
 * fezui_datesetpage.c
 *
 *  Created on: Nov 27, 2023
 *      Author: xq123
 */
#include "fezui.h"
#include "fezui_var.h"

lefl_menu_t datemenu;
const char* datemenu_items[] = {"<Back","Year","Month","Day"};
lefl_page_t datesetpage={datesetpage_logic,datesetpage_draw,datesetpage_load};

#define ROW_HEIGHT 16

static float start_animation=0;
static bool configing;
void datemenu_cb(void *menu);
void datesetpage_init()
{
    lefl_menu_init(&datemenu, datemenu_items, sizeof(datemenu_items)/sizeof(const char*), datemenu_cb);
}

void datesetpage_logic(void *page)
{
    if(configing)
    {
        fezui_cursor_set(
            &target_cursor ,
            WIDTH-4*6-2,
            datemenu.selected_index*ROW_HEIGHT,
            4*6+2,
            ROW_HEIGHT);
    }
    else
    {
        fezui_cursor_set(
            &target_cursor ,
            0,
            datemenu.selected_index*ROW_HEIGHT,
            strlen(datemenu.items[datemenu.selected_index])*6+6,
            ROW_HEIGHT);
    }
    CONVERGE_TO(start_animation, 1, fezui.speed);
}
void datesetpage_draw(void *page)
{
    u8g2_SetFont(&(fezui.u8g2), u8g2_font_6x13_mf);
    for(uint8_t i=0;i<datemenu.len;i++)
    {
        u8g2_DrawStr(&(fezui.u8g2),3,ROUND((ROW_HEIGHT*(i+1) - 3)*start_animation),datemenu.items[i]);
    }
    sprintf(fezui_buffer,"%04d",2000+date.Year);
    u8g2_DrawStr(&fezui.u8g2, WIDTH-6*4-1, ROUND((ROW_HEIGHT*(2) - 3)*start_animation), fezui_buffer);
    sprintf(fezui_buffer,"%02d",date.Month);
    u8g2_DrawStr(&fezui.u8g2, WIDTH-6*2-1, ROUND((ROW_HEIGHT*(3) - 3)*start_animation), fezui_buffer);
    sprintf(fezui_buffer,"%02d",date.Date);
    u8g2_DrawStr(&fezui.u8g2, WIDTH-6*2-1, ROUND((ROW_HEIGHT*(4) - 3)*start_animation), fezui_buffer);
    fezui_draw_cursor(&fezui, &cursor);
}
void datemenu_cb(void *menu)
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
        switch (datemenu.selected_index)
        {
        case 0:
            break;
        case 1:
            VAR_LOOP_INCREMENT(date.Year,0,99,1);
            HAL_RTC_SetDate(&hrtc, &date, RTC_FORMAT_BIN);
            break;
        case 2:
            VAR_LOOP_INCREMENT(date.Month,1,12,1);
            HAL_RTC_SetDate(&hrtc, &date, RTC_FORMAT_BIN);
            break;
        case 3:
            VAR_LOOP_INCREMENT(date.Date,0,31,1);
            HAL_RTC_SetDate(&hrtc, &date, RTC_FORMAT_BIN);
            break;
        default:
            break;
        }
    }
    else
    {
        lefl_menu_index_increase(&datemenu, 1);
    }
}
static void key_down_cb(void*k)
{
    if(configing)
    {
        switch (datemenu.selected_index)
        {
        case 0:
            break;
        case 1:
            VAR_LOOP_DECREMENT(date.Year,0,99,1);
            HAL_RTC_SetDate(&hrtc, &date, RTC_FORMAT_BIN);
            break;
        case 2:
            VAR_LOOP_DECREMENT(date.Month,1,12,1);
            HAL_RTC_SetDate(&hrtc, &date, RTC_FORMAT_BIN);
            break;
        case 3:
            VAR_LOOP_DECREMENT(date.Date,0,31,1);
            HAL_RTC_SetDate(&hrtc, &date, RTC_FORMAT_BIN);
            break;
        default:
            break;
        }
    }
    else
    {
        lefl_menu_index_increase(&datemenu, -1);
    }
}
void datesetpage_load(void *page)
{
    fezui_cursor_set(
            &cursor ,
            0,
            0,
            0,
            0);
    key.key_cb[0]=LAMBDA(void,(void*k){lefl_menu_click(&datemenu);});
    key_up.key_cb[0]=key_up_cb;
    key_down.key_cb[0]=key_down_cb;
    datemenu.selected_index=0;
    start_animation=0;
}
