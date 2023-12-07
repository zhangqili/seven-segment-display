/*
 * fezui_var.h
 *
 *  Created on: Jul 21, 2023
 *      Author: xq123
 */

#ifndef FEZUI_VAR_H_
#define FEZUI_VAR_H_
#include "fezui.h"
#include "rtc.h"

#define KEYBOARD_CHILD_NUM 4
#define KEYBOARD_CHILD_KEY_MAX_NUM 32
#define KEYBOARD_TREE_BUFFER_MAX_SIZE 256
extern char fpsstr[8];
extern const uint8_t fez_font_6x10_m[204] U8G2_FONT_SECTION("fez_font_6x10_m");
extern fezui_t fezui;
extern uint8_t key_triggered_count;
extern uint8_t key_buffer[ADVANCED_KEY_NUM+KEY_NUM];


extern uint32_t fezui_fps;
extern uint8_t fezui_kps;

extern uint8_t fezui_debug;
extern float fezui_debug_float;
extern uint8_t current_key_index;
extern uint8_t current_function_key;
extern uint8_t fezui_adc_conversion_count;

extern uint32_t fezui_run_time;
extern uint32_t fezui_temp_raw;

extern lefl_key_t key_up;
extern lefl_key_t key_down;
extern lefl_key_t key;

extern const uint8_t year_font[];
extern const uint8_t month_font[];
extern const uint8_t day_font[];

extern RTC_TimeTypeDef time;
extern RTC_DateTypeDef date;

extern uint8_t temp_buffer[1024];
extern bool showdate;
#endif /* FEZUI_VAR_H_ */
