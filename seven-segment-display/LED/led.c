/*
 * led.c
 *
 *  Created on: Nov 26, 2023
 *      Author: xq123
 */
#include "led.h"
#include "main.h"
#include "string.h"
#include "gpio.h"

uint8_t Current_Channel;

void Segment_Select(uint8_t s)
{
    switch (s)
    {
        case 0:
            HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
            break;
        case 3:
            HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
            break;
        case 4:
            HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
            break;
        case 5:
            HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
            break;
        case 6:
            HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_SET);
            break;
        case 7:
            HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void Show_String(const char* str)
{
    uint8_t len = strlen(str);
    for (uint8_t i = 0; i < 8&&i<len; i++)
    {
        Segment_Select(i);
        Char_Select(str[i]);
        delayMicroseconds(100);
        //HAL_Delay(1);
    }
}

void Char_Select(char c)
{
    switch (c)
    {
        case '0':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '1':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '2':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '3':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '4':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '5':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '6':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '7':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '8':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '9':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        case '.':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_RESET);
            break;
        case '-':
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
        default:
            HAL_GPIO_WritePin(LEDA_GPIO_Port, LEDA_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDB_GPIO_Port, LEDB_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDD_GPIO_Port, LEDD_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDE_GPIO_Port, LEDE_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDF_GPIO_Port, LEDF_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LEDH_GPIO_Port, LEDH_Pin, GPIO_PIN_SET);
            break;
    }
}
