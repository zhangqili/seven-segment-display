/*
 * fezui_config.h
 *
 *  Created on: 2023年6月19日
 *      Author: xq123
 */

#ifndef FEZUI_CONFIG_H_
#define FEZUI_CONFIG_H_

#define WIDTH                 128
#define HEIGHT                64
#define BUFFER_LENGTH         64
#define NUMBER_STRING_LENGTH  BUFFER_LENGTH
#define REFRESH_RATE          168
#define KPS_HISTORY_LENGTH    65
#define ADVANCED_KEY_NUM      4
#define KEY_NUM               8
#define ITEM_HEIGHT           14
#define HISTORY_LENGTH        129

#define _FPS_ON

#define roll()                rand()%2;


void Keyboard_ID_Save();
void Keyboard_ID_Recovery();
void keyid_prase(uint16_t id,char* str,uint16_t str_len);
void Analog_Read();
void Analog_Save();
void fezui_read_counts();
void fezui_save_counts();
void fezui_read();
void fezui_save();
void fezui_reset();


extern lefl_link_frame_t mainframe;

extern lefl_page_t homepage;
void homepage_logic(void *page);
void homepage_draw(void *page);
void homepage_load(void *page);

extern lefl_page_t menupage;
void menupage_init();
void menupage_logic(void *page);
void menupage_draw(void *page);
void menupage_load(void *page);
void main_menu_cb(void *menu);

extern lefl_page_t settingspage;
void settingspage_init();
void settingspage_logic(void *page);
void settingspage_draw(void *page);
void settingspage_load(void *page);
void settings_menu_cb(void *menu);

extern lefl_page_t oscilloscopepage;
void oscilloscopepage_logic(void *page);
void oscilloscopepage_draw(void *page);
void oscilloscopepage_load(void *page);

extern lefl_page_t debugpage;
void debugpage_logic(void *page);
void debugpage_draw(void *page);
void debugpage_load(void *page);

extern lefl_page_t aboutpage;
void aboutpage_logic(void *page);
void aboutpage_draw(void *page);
void aboutpage_load(void *page);

extern lefl_page_t datesetpage;
void datesetpage_init();
void datesetpage_logic(void *page);
void datesetpage_draw(void *page);
void datesetpage_load(void *page);

extern lefl_page_t timesetpage;
void timesetpage_init();
void timesetpage_logic(void *page);
void timesetpage_draw(void *page);
void timesetpage_load(void *page);
#endif /* FEZUI_CONFIG_H_ */
