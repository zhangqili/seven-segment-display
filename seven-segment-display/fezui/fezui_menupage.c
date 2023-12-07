/*
 * fezui_menupage.c
 *
 *  Created on: 2023年6月19日
 *      Author: xq123
 */

#include "fezui.h"
#include "fezui_var.h"

lefl_page_t menupage={menupage_logic,menupage_draw,menupage_load};

lefl_menu_t mainmenu;
const char* mainmenu_items[] = {"Home","Set Time","Set Date"};

float zoom;

float menu_offset;
float offset;

void menupage_init()
{
    lefl_menu_init(&mainmenu, mainmenu_items, sizeof(mainmenu_items)/sizeof(const char*), main_menu_cb);
}

void menupage_logic(void *page)
{
    homepage_logic(&homepage);
    //lefl_animation_tick(&menuanimation);
    fezui_cursor_set(
            &target_cursor ,
            64-strlen(mainmenu.items[mainmenu.selected_index])*3,
            62,
            strlen(mainmenu.items[mainmenu.selected_index])*6,
            2);
    CONVERGE_TO(zoom,2,fezui.speed);
    CONVERGE_TO(offset,0,fezui.speed);
    CONVERGE_TO_ROUNDED(menu_offset,64*(mainmenu.selected_index)+strlen(mainmenu.items[mainmenu.selected_index])*3,fezui.speed);
}
void menupage_draw(void *page)
{
    homepage_draw(&homepage);
    u8g2_SetFont(&(fezui.u8g2), u8g2_font_6x13_tf);
    for(uint8_t i=0;i<mainmenu.len;i++)
    {
        u8g2_DrawStr(&(fezui.u8g2),64*(i+1)-(int16_t)menu_offset,60+(int16_t)offset,mainmenu.items[i]);
    }
    u8g2_DrawBox(&(fezui.u8g2), cursor.x,cursor.y,cursor.w,cursor.h);
}

void main_menu_cb(void *menu)
{

    switch (((lefl_menu_t*)menu)->selected_index)
    {
    case 0:
        lefl_link_frame_go_back(&mainframe);
        break;
    case 1:
        lefl_link_frame_navigate(&mainframe, &timesetpage);
        break;
    case 2:
        lefl_link_frame_navigate(&mainframe, &datesetpage);
        break;
    default:
        break;
    }
}

void menupage_load(void *page)
{
    fezui_cursor_set(
            &cursor ,
            0,
            62,
            WIDTH,
            2);
    offset=14;
    key.key_cb[0]=LAMBDA(void,(void*k){lefl_menu_click(&mainmenu);;});
    key_up.key_cb[0]=LAMBDA(void,(void*k){lefl_menu_index_increase(&mainmenu, 1);});
    key_down.key_cb[0]=LAMBDA(void,(void*k){lefl_menu_index_increase(&mainmenu, -1);});
    //lefl_animation_begin(&menuanimation);

}

