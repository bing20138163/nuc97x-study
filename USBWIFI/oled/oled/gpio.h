/*
 * @Description: gpio接口头文�?
 * @Author: Niceshow
 * @Email: xiaoxincomeon@qq.com
 * @Date: 2020-09-07 16:11:52
 * @LastEditTime: 2020-09-07 16:16:20
 * @LastEditors: Niceshow
 */

#ifndef _DLL_GPIO_
#define _DLL_GPIO_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
 /**
 * GPIO_DIRECTION_IN: gpio input
 * GPIO_DIRECTION_OUT: gpio output
 */
typedef enum GPIODIR{
    GPIODIR_IN=0,
    GPIODIR_OUT,
}IOdir;

/**
 * 0:none
 * 1:rising
 * 2:falling
 * 3:both
 */
typedef enum GPIOEDGE{
    GPIO_EDGE_NONE=0,
    GPIO_EDGE_RISING,
    GPIO_EDGE_FALLING,
    GPIO_EDGE_BOTH,
    GPIO_EDGE_NUM
}IOedge;

int dll_gpio_export(int pin);
int dll_gpio_unexport(int pin);
int dll_gpio_direction(int pin, IOdir direction);
int dll_gpio_setvalue(int pin, int value);
unsigned char dll_gpio_getvalue(int pin);
void dll_gpio_tigger(int pin);

#endif