//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-10-31
//  ����޸�   : 
//  ��������   : OLED SPI�ӿ���ʾ����(51ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  3.3v��Դ
//              D0   P1^7��SCL��
//              D1   P1^6��SDA��
//              DC   P1^5
//              CS1  P1^4
//              FS0  P1^3 
//              CS2  P1^2
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018-10-31
//All rights reserved
//******************************************************************************/
//#include <reg52.H>
// #include <intrins.h>
// #include "oled.h"
#include "bmp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "gpio.h"
#include "spi.h"

void delay_ms(unsigned int i)
{
	usleep(1000 * i);
}

int main(void)
{
	float t=0;
	OLED_Init();
	OLED_ColorTurn(0);//0������ʾ��1 ��ɫ��ʾ
  	OLED_DisplayTurn(0);//0������ʾ 1 ��Ļ��ת��ʾ
//	OLED_Clear();
	while(1)
	{	
//		t+=0.01;
//		OLED_ShowNum(0,0,t,5);
//		OLED_Display_128x64(bmp1);
//		delay_ms(500);
		OLED_Display_GB2312_string(0,0,"��ʯ���ӹɷ�����");	/*�ڵ�1ҳ����1�У���ʾһ��16x16�����ֻ�8x16��ASCII��*/
		OLED_Display_GB2312_string(0,2,"��˾-��ѩ��");  /*��ʾһ��16x16�����ֻ�8x16��ASCII��.������ͬ*/
		OLED_Display_GB2312_string(0,4,"13720882830");
		OLED_Display_GB2312_string(0,6,"��5X7����ASCII��");
		delay_ms(500);				
		OLED_Clear();
		OLED_Display_GB2312_string(24,0,"�о�԰����");	
		OLED_Display_GB2312_string(0,2,"��Ҫ����OLEDģ��");
		OLED_Display_GB2312_string(0,4,"�˿�������Ϸ���");
		OLED_Display_GB2312_string(0,6,"������������һ��");
		delay_ms(500);	
		OLED_Clear();		
		OLED_Display_GB2312_string(0,0,"GB2312�����ֿ⼰");	
		OLED_Display_GB2312_string(0,2,"��ͼ�͹��ܣ�����");	
		OLED_Display_GB2312_string(0,4,"����ֻ�ͼ�����");
		OLED_Display_GB2312_string(0,6,"Ƨ�֣����磺");
		OLED_Display_16x16(97,6,jiong1);					/*�ڵ�7ҳ����81����ʾ�����Ա���Ƨ���֡��塱*/
    	OLED_Display_16x16(113,6,lei1);
		delay_ms(500);
		OLED_Clear();
		OLED_Display_GB2312_string(0,0,"<!@#$%^&*()_-+]/");	/*�ڵ�1ҳ����1�У���ʾһ��16x16�����ֻ�8*16��ASCII��*/
		OLED_Display_string_5x7(0,2,"<!@#$%^&*()_-+]/;.,?[");/*�ڵ�3ҳ����1�У���ʾһ��5x7�����ASCII��*/
		OLED_Display_string_5x7(0,3,"XY electronics Co., ");/*��ʾһ��5x7�����ASCII��*/
		OLED_Display_string_5x7(0,4,"Ltd. established at  ");/*��ʾһ��5x7�����ASCII��*/	
		OLED_Display_string_5x7(0,5,"year 2010.Focus OLED ");/*��ʾһ��5x7�����ASCII��*/
		OLED_Display_string_5x7(0,6,"Mobile:13265585975");/*��ʾһ��5x7�����ASCII��*/
		OLED_Display_string_5x7(0,7,"Tel:0755-32910715");/*��ʾһ��5x7�����ASCII��*/
		delay_ms(500);
		OLED_Clear();	
		OLED_Display_GB2312_string(0,0,"����������������");	/*�ڵ�1ҳ����1�У���ʾһ��16x16�����ֻ�8x16��ASCII��*/
		OLED_Display_GB2312_string(0,2,"����������������");  /*��ʾһ��16x16�����ֻ�8x16��ASCII��.������ͬ*/
		OLED_Display_GB2312_string(0,4,"����������������");
		OLED_Display_GB2312_string(0,6,"����������������");		        
		delay_ms(500);
		OLED_Clear();	
		OLED_Display_GB2312_string(0,0,"����������������");
		OLED_Display_GB2312_string(0,2,"����������������");
		OLED_Display_GB2312_string(0,4,"����������������");
		OLED_Display_GB2312_string(0,6,"����������������");
		delay_ms(500);
		OLED_Clear();
  }
}