/*
 * fezui_settingspage.c
 *
 *  Created on: 2023年6月19日
 *      Author: xq123
 */
#include "fezui.h"
#include "fezui_var.h"
#include "main.h"
#include "tim.h"
lefl_menu_t settingsmenu;
const char* settingsmenu_items[] = {"Keys Configuration","RGB","Calibration","Display", "Debug", "Reboot", "About"};
lefl_page_t settingspage={settingspage_logic,settingspage_draw,settingspage_load};

#define ROW_HEIGHT 16

static fezui_scrollview_t scrollview={.content_height=ROW_HEIGHT*7};
static float target_ordinate=0;
static float start_animation=0;
static float settingsmenu_item_offsets[7];

void settingspage_init()
{
    lefl_menu_init(&settingsmenu, settingsmenu_items, sizeof(settingsmenu_items)/sizeof(const char*), settings_menu_cb);
}

void settingspage_logic(void *page)
{
    fezui_cursor_set(
        &target_cursor ,
        0,
        settingsmenu.selected_index*ROW_HEIGHT - (u8g2_int_t)scrollview.ordinate,
        strlen(settingsmenu.items[settingsmenu.selected_index])*6+6,
        ROW_HEIGHT);
    if((settingsmenu.selected_index+1)*ROW_HEIGHT-target_ordinate>64)
    {
        target_ordinate = (settingsmenu.selected_index+1)*ROW_HEIGHT-64;
    }
    if((settingsmenu.selected_index)*ROW_HEIGHT<target_ordinate)
    {
        target_ordinate = (settingsmenu.selected_index)*ROW_HEIGHT;
    }
    for(uint8_t i=0;i<settingsmenu.len;i++)
    {
        CONVERGE_TO_ROUNDED(settingsmenu_item_offsets[i],i==settingsmenu.selected_index?3:0,fezui.speed);
    }
    CONVERGE_TO_ROUNDED(scrollview.ordinate, target_ordinate, fezui.speed);
    CONVERGE_TO(start_animation, 1, fezui.speed);
}
void settingspage_draw(void *page)
{
    u8g2_SetFont(&(fezui.u8g2), u8g2_font_6x13_tf);
    for(uint8_t i=0;i<settingsmenu.len;i++)
    {
        u8g2_DrawStr(&(fezui.u8g2),settingsmenu_item_offsets[i],ROUND((ROW_HEIGHT*(i+1) - 3 - scrollview.ordinate)*start_animation),settingsmenu.items[i]);
    }
    fezui_draw_scrollview(&fezui, 0, 0, WIDTH, ROUND(HEIGHT*start_animation), &scrollview);
    fezui_draw_cursor(&fezui, &cursor);
}
void settings_menu_cb(void *menu)
{

    switch (((lefl_menu_t*)menu)->selected_index)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        __set_FAULTMASK(1);
        HAL_NVIC_SystemReset();
        //lefl_link_frame_navigate(&mainframe, &debugpage);
        break;
    case 6:
        lefl_link_frame_navigate(&mainframe, &aboutpage);
        break;
    default:
        break;
    }
}
void settingspage_load(void *page)
{
    start_animation=0;
}
