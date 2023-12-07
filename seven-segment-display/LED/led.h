/*
 * led.h
 *
 *  Created on: Nov 26, 2023
 *      Author: xq123
 */

#ifndef LED_H_
#define LED_H_
#include "stdint.h"
extern uint8_t Current_Channel;
void Segment_Select(uint8_t s);
void Char_Select(char c);
void Show_String(const char* str);

#endif /* LED_H_ */
