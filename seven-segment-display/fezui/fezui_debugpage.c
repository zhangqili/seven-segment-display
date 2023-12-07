/*
 * fezui_debugpage.c
 *
 *  Created on: 2023年6月24日
 *      Author: xq123
 */
#include "fezui.h"
#include "fezui_var.h"

lefl_page_t debugpage={debugpage_logic,debugpage_draw,debugpage_load};
static float target_ordinate=0;
static float target_abscissa=0;

static float targetnum = 50;
fezui_slider_t slider =
{
	.interval=1,
	.max=256,
	.min=0,
	.f_ptr=&targetnum,
	.orientation=ORIENTATION_VERTICAL
};

static fezui_scrollview_t scrollview =
{
    .content_height=120,
    .content_width=250,
    .abscissa=0,
    .ordinate=0
};

static fezui_rolling_number_t rolling_number=
{
    .digit=5,
    .number=0,
    .font = u8g2_font_micro_mn,
};

void debugpage_logic(void *page)
{
    CONVERGE_TO_ROUNDED(scrollview.abscissa, target_abscissa,fezui.speed);
    CONVERGE_TO_ROUNDED(scrollview.ordinate, target_ordinate,fezui.speed);
    fezui_rolling_number_update(&fezui, &rolling_number);
}
void debugpage_draw(void *page)
{

    sprintf(fezui_buffer,"%#x",fezui_debug);
    u8g2_DrawStr(&(fezui.u8g2),64,16,fezui_buffer);

    u8g2_DrawStr(&(fezui.u8g2),64,32,fezui_buffer);
}

void debugpage_load(void *page)
{

}

