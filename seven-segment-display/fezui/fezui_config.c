/*
 * fezui_config.c
 *
 *  Created on: 2023年6月19日
 *      Author: xq123
 */

#include "fezui.h"
#include "fezui_var.h"
#include "lefl.h"
#include "display.h"


uint8_t tempuint;


void fezui_init()
{
    MD_OLED_RST_Set();
    u8g2_Setup_ssd1306_128x64_noname_f(&(fezui.u8g2), U8G2_R0, u8x8_byte_4wire_hw_spi,
            u8x8_stm32_gpio_and_delay);
    u8g2_InitDisplay(&(fezui.u8g2));
    u8g2_SetPowerSave(&(fezui.u8g2), 0);
    //u8g2_SetBitmapMode(&(fezui.u8g2), 1);
    u8g2_SetFontMode(&(fezui.u8g2), 1);
    u8g2_ClearBuffer(&(fezui.u8g2));
    u8g2_DrawLine(&(fezui.u8g2), 15, 15, 20, 18);
    u8g2_DrawLine(&(fezui.u8g2), 15, 22, 20, 18);
    u8g2_DrawLine(&(fezui.u8g2), 26, 16, 20, 18);
    u8g2_DrawLine(&(fezui.u8g2), 26, 26, 20, 18);
    u8g2_DrawLine(&(fezui.u8g2), 26, 16, 31, 12);
    u8g2_DrawLine(&(fezui.u8g2), 21, 8, 31, 12);
    u8g2_DrawLine(&(fezui.u8g2), 39, 4, 31, 12);
    u8g2_DrawLine(&(fezui.u8g2), 42, 21, 31, 12);
    u8g2_DrawLine(&(fezui.u8g2), 26, 26, 33, 30);
    u8g2_DrawLine(&(fezui.u8g2), 46, 39, 33, 30);
    u8g2_DrawLine(&(fezui.u8g2), 26, 26, 26, 38);
    u8g2_DrawLine(&(fezui.u8g2), 42, 44, 26, 38);
    u8g2_DrawLine(&(fezui.u8g2), 42, 21, 52, 27);
    u8g2_DrawLine(&(fezui.u8g2), 55, 26, 52, 27);
    u8g2_DrawLine(&(fezui.u8g2), 42, 21, 50, 32);
    u8g2_SendBuffer(&(fezui.u8g2));

    menupage_init();
    settingspage_init();
    datesetpage_init();
    timesetpage_init();
    homepage_load(&homepage);
    /*
    for (int i = 0; i < 10000; i++)
    {
        homepage_logic(&homepage);
    }
    */
    mainframe.current_page=&homepage;
    //lefl_link_frame_navigate(&mainframe, &homepage);
    fezui.speed=0.1;
    fezui.invert=true;

    //fezui_reset();
}

void fezui_timer_handler()
{
    HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);
    lefl_key_update(&key, HAL_GPIO_ReadPin(KNOB_GPIO_Port, KNOB_Pin));
    lefl_link_frame_logic(&mainframe);
    fezui_cursor_move(&fezui ,&cursor, &target_cursor);
}


void fezui_render_handler()
{
    u8g2_ClearBuffer(&(fezui.u8g2));
    if(fezui.invert)
    {
        u8g2_SendF(&(fezui.u8g2), "c", 0xA7);
    }
    else
    {

    }
    u8g2_SetDrawColor(&(fezui.u8g2),1);
    lefl_link_frame_draw(&mainframe);
    if(fezui.screensaver_timeout)
    {
        if(fezui.invert)
        {
            fezui_veil(&(fezui),0,0,128,64,(7-fezui.screensaver_countdown)>256?0:7-fezui.screensaver_countdown,1);
        }
        else
        {
            fezui_veil(&(fezui),0,0,128,64,(7-fezui.screensaver_countdown)>256?0:7-fezui.screensaver_countdown,0);
        }
        u8g2_SetPowerSave(&(fezui.u8g2),!fezui.screensaver_countdown);
    }
#ifdef _FPS_ON
    u8g2_SetDrawColor(&(fezui.u8g2), 2);
    u8g2_SetFont(&(fezui.u8g2), fez_font_6x10_m);
    u8g2_DrawStr(&(fezui.u8g2),95+15,10,fpsstr);
#endif
    u8g2_SendBuffer(&(fezui.u8g2));
    fezui_fps++;
}


