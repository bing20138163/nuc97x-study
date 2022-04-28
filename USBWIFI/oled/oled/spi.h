#ifndef __SPI_H
#define __SPI_H

//#include <reg52.H>
//#include "led.h"
#include "gpio.h"

// sbit OLED_SCLK=P1^7;     /*接口定义:OLED_SCLK就是D0*/
// sbit OLED_SDIN=P1^6;     /*接口定义:OLED_SDIN就是D1*/
// sbit OLED_DC=P1^5;       /*接口定义:OLED_DC就是DC*/
// sbit OLED_CS=P1^4;       /*接口定义:OLED_CS就是OLED的片选CS1*/
// sbit OLED_ROM_OUT=P1^3;  /*字库IC接口定义:OLED_ROM_OUT就是OUT*/
// sbit OLED_ROM_CS=P1^2;   /*字库IC接口定义OLED_ROM_CS就是字库IC的CS2*/

// #define u8  unsigned char
// #define u32 unsigned int
// #define u8long unsigned long 
// #define OLED_CMD  0   //写命令
// #define OLED_DATA 1   //写数据

// #define OLED_SCLK_Set()       OLED_SCLK=1;
// #define OLED_SCLK_Clr()        OLED_SCLK=0;

// #define OLED_SDIN_Set()       OLED_SDIN=1;
// #define OLED_SDIN_Clr()        OLED_SDIN=0;

// #define OLED_DC_Set()         OLED_DC=1;
// #define OLED_DC_Clr()          OLED_DC=0;

// #define OLED_CS_Set()         OLED_CS=1;
// #define OLED_CS_Clr()          OLED_CS=0;

// #define OLED_ROM_OUT_Set()    OLED_ROM_OUT=1;
// #define OLED_ROM_OUT_Clr()     OLED_ROM_OUT=0;

// #define OLED_ROM_CS_Set()     OLED_ROM_CS=1;
// #define OLED_ROM_CS_Clr()      OLED_ROM_CS=0;

// sbit OLED_SCLK=PB10;//42     /*接口定义:OLED_SCLK就是D0*/
// sbit OLED_SDIN=PB11;//43    /*接口定义:OLED_SDIN就是D1*/
// sbit OLED_DC=PB12;//44       /*接口定义:OLED_DC就是DC*/
// sbit OLED_CS=PB13;//45       /*接口定义:OLED_CS就是OLED的片选CS1*/
// sbit OLED_ROM_OUT=PB14;//46  /*字库IC接口定义:OLED_ROM_OUT就是OUT*/
// sbit OLED_ROM_CS=PB15;//47   /*字库IC接口定义OLED_ROM_CS就是字库IC的CS2*/

#define u8  unsigned char
#define u32 unsigned int
#define u8long unsigned long 
#define OLED_CMD  0   //写命令
#define OLED_DATA 1   //写数据

#define OLED_SCLK_Set()       {dll_gpio_export(42);dll_gpio_direction(42, GPIODIR_OUT);dll_gpio_setvalue(42, 1);}
#define OLED_SCLK_Clr()       {dll_gpio_export(42);dll_gpio_direction(42, GPIODIR_OUT);dll_gpio_setvalue(42, 0);}

#define OLED_SDIN_Set()       {dll_gpio_export(43);dll_gpio_direction(43, GPIODIR_OUT);dll_gpio_setvalue(43, 1);}
#define OLED_SDIN_Clr()       {dll_gpio_export(43);dll_gpio_direction(43, GPIODIR_OUT);dll_gpio_setvalue(43, 0);}

#define OLED_DC_Set()         {dll_gpio_export(44);dll_gpio_direction(44, GPIODIR_OUT);dll_gpio_setvalue(44, 1);}
#define OLED_DC_Clr()         {dll_gpio_export(44);dll_gpio_direction(44, GPIODIR_OUT);dll_gpio_setvalue(44, 0);}

#define OLED_CS_Set()         {dll_gpio_export(45);dll_gpio_direction(45, GPIODIR_OUT);dll_gpio_setvalue(45, 1);}
#define OLED_CS_Clr()         {dll_gpio_export(45);dll_gpio_direction(45, GPIODIR_OUT);dll_gpio_setvalue(45, 0);}

#define OLED_ROM_OUT_Set()    {dll_gpio_export(46);dll_gpio_direction(46, GPIODIR_OUT);dll_gpio_setvalue(46, 1);}
#define OLED_ROM_OUT_Clr()    {dll_gpio_export(46);dll_gpio_direction(46, GPIODIR_OUT);dll_gpio_setvalue(46, 0);}

#define OLED_ROM_CS_Set()     {dll_gpio_export(47);dll_gpio_direction(47, GPIODIR_OUT);dll_gpio_setvalue(47, 1);}
#define OLED_ROM_CS_Clr()     {dll_gpio_export(47);dll_gpio_direction(47, GPIODIR_OUT);dll_gpio_setvalue(47, 0);}

void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u32 dat,u8 mode);
void OLED_Clear(void);
void OLED_address(u8 page,u8 column);
void OLED_Display_128x64(u8 *dp);
void OLED_Display_16x16(u32 column,u32 page,u8 *dp);
void OLED_Display_8x16(u8 column,u32 page,u8 *dp);
void OLED_Display_5x7(u8 column,u32 page,u8 *dp);
void Send_Command_to_ROM(u8 dat);
u8 Get_data_from_ROM();
void OLED_get_data_from_ROM(u8 addrHigh,u8 addrMid,u8 addrLow,u8 *pbuff,u8 DataLen);
void OLED_Display_GB2312_string(u8 x,u8 y,u8 *text);
void OLED_Display_string_5x7(u8 x,u8 y,u8 *text);
void OLED_ShowNum(u8 x,u8 y,float num1,u8 len);
void OLED_Init(void);
#endif