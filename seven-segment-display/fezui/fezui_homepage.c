/*
 * fezui_homepage.c
 *
 *  Created on: 2023年6月19日
 *      Author: xq123
 */

#include "fezui.h"
#include "fezui_var.h"
#include "rtc.h"

#define MARGIN_LEFT           65
#define PADDING_UP            0
#define MARGIN_UP             11
#define MARGIN_DOWN           12
#define HALF_WIDTH            64
#define TILE_WIDTH            10
#define CHART_HEIGHT          (HEIGHT-MARGIN_DOWN-MARGIN_UP)
#define CHART_WIDTH           64
#define TILE1                 1
#define TILE2                 11
#define TILE3                 21
#define TILE4                 31

lefl_page_t homepage={homepage_logic,homepage_draw,homepage_load};
extern float zoom;
fezui_rolling_number_t hour_num=
{
    .number=0,
    .font=u8g2_font_7_Seg_33x19_mn,
    .digit=2
};

fezui_rolling_number_t minute_num=
{
    .number=0,
    .font=u8g2_font_7_Seg_33x19_mn,
    .digit=2
};

fezui_rolling_number_t second_num=
{
    .number=0,
    .font=u8g2_font_7_Seg_33x19_mn,
    .digit=2
};

fezui_rolling_number_t year_num=
{
    .number=0,
    .font=u8g2_font_10x20_mn,
    .digit=4
};

fezui_rolling_number_t month_num=
{
    .number=0,
    .font=u8g2_font_10x20_mn,
    .digit=2
};

fezui_rolling_number_t day_num=
{
    .number=0,
    .font=u8g2_font_10x20_mn,
    .digit=2
};
void fezui_rolling_number_update1(fezui_t *fezui_ptr, fezui_rolling_number_t* rolling_number)
{
    const uint8_t *temp_font=(fezui_ptr->u8g2).font;
    u8g2_SetFont(&(fezui_ptr->u8g2), rolling_number->font);
    u8g2_long_t num=rolling_number->number;
    CONVERGE_TO_ROUNDED(rolling_number->offsets[0], (num%10+1)*u8g2_GetMaxCharHeight(&(fezui_ptr->u8g2)),fezui_ptr->speed);
    for (uint8_t i = 1; i < rolling_number->digit; i++)
    {
        num/=10;
        CONVERGE_TO_ROUNDED(rolling_number->offsets[i], (num%10+1)*(u8g2_GetMaxCharHeight(&(fezui_ptr->u8g2))),fezui_ptr->speed);
    }
    u8g2_SetFont(&(fezui_ptr->u8g2), temp_font);
}

void fezui_rolling_number_update2(fezui_t *fezui_ptr, fezui_rolling_number_t* rolling_number)
{
    const uint8_t *temp_font=(fezui_ptr->u8g2).font;
    u8g2_SetFont(&(fezui_ptr->u8g2), rolling_number->font);
    u8g2_long_t num=rolling_number->number;
    CONVERGE_TO_ROUNDED(rolling_number->offsets[0], num%10*u8g2_GetMaxCharHeight(&(fezui_ptr->u8g2)),fezui_ptr->speed);
    for (uint8_t i = 1; i < rolling_number->digit; i++)
    {
        num/=10;
        CONVERGE_TO_ROUNDED(rolling_number->offsets[i], num%10*(u8g2_GetMaxCharHeight(&(fezui_ptr->u8g2))),fezui_ptr->speed);
    }
    u8g2_SetFont(&(fezui_ptr->u8g2), temp_font);
}

void homepage_logic(void *page)
{
    fezui_rolling_number_set(&hour_num,time.Hours);
    fezui_rolling_number_set(&minute_num,time.Minutes);
    fezui_rolling_number_set(&second_num,time.Seconds);
    fezui_rolling_number_set(&year_num,2000+date.Year);
    fezui_rolling_number_set(&month_num,date.Month);
    fezui_rolling_number_set(&day_num,date.Date);
    //sprintf(fezui_buffer,"%2d",KPS_history_max);
    fezui_rolling_number_update1(&fezui, &hour_num);
    fezui_rolling_number_update1(&fezui, &minute_num);
    fezui_rolling_number_update1(&fezui, &second_num);
    fezui_rolling_number_update2(&fezui, &year_num);
    fezui_rolling_number_update2(&fezui, &month_num);
    fezui_rolling_number_update2(&fezui, &day_num);

    CONVERGE_TO(zoom,1,fezui.speed);
}
void homepage_draw(void *page)
{
    u8g2_SetFont(&(fezui.u8g2), u8g2_font_7_Seg_33x19_mn);
    fezui_draw_rolling_number(&fezui, 0, 32, &hour_num);
    fezui_draw_rolling_number(&fezui, 19*3-12, 32, &minute_num);
    fezui_draw_rolling_number(&fezui, 19*6-24, 32, &second_num);
    u8g2_DrawStr(&(fezui.u8g2), 19*2, 0, ":");
    u8g2_DrawStr(&(fezui.u8g2), 19*5-12, 0, ":");
    u8g2_SetFont(&fezui.u8g2, u8g2_font_10x20_mn);
    u8g2_DrawXBMP(&fezui.u8g2, 2+4*10, 32, 16, 16, year_font);
    u8g2_DrawXBMP(&fezui.u8g2, 2+16+10*6, 32, 16, 16, month_font);
    u8g2_DrawXBMP(&fezui.u8g2, 2+32+10*8, 32, 16, 16, day_font);
    fezui_draw_rolling_number(&fezui, 2+0, 48, &year_num);
    fezui_draw_rolling_number(&fezui, 2+16+10*4, 48, &month_num);
    fezui_draw_rolling_number(&fezui, 2+32+10*6, 48, &day_num);

    if(fabsf(zoom-1)>1e-3)
    {

        uint8_t*p= u8g2_GetBufferPtr(&fezui.u8g2);
        memset(temp_buffer,0,1024);
        for (uint8_t i = 0; i < 8; i++)
        {
            for (uint8_t j = 0; j < 128; j++)
            {
                for (uint8_t k = 0; k < 8; k++)
                {
                    if(abs(j-64)*zoom<=64&&abs(i*8+k-32)*zoom<=32)
                    {
                        uint8_t x=64+(int8_t)((j-64)*zoom);
                        uint8_t y=32+(int8_t)((i*8+k-32)*zoom);
                        temp_buffer[i*128+j]|=p[y/8*128+x]&BIT(y%8)?BIT(k):0;
                    }
                }
            }
        }
        memset(p,0,1024);
        memcpy(p,temp_buffer,1024);
    }
}

void homepage_load(void *page)
{
    key.key_cb[0]=LAMBDA(void,(void*k){lefl_link_frame_navigate(&mainframe, &menupage);});
    key_up.key_cb[0]=LAMBDA(void,(void*k){showdate=!showdate;});;
    key_down.key_cb[0]=LAMBDA(void,(void*k){showdate=!showdate;});;
}
