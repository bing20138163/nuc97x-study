/*
 * @Description: GPIO操作接口文件
 * @Author: Niceshow
 * @Email: xiaoxincomeon@qq.com
 * @Date: 2020-09-07 16:12:20
 * @LastEditTime: 2020-09-07 18:03:57
 * @LastEditors: Niceshow
 */
#include "gpio.h"

#define SYS_GPIO_EXPORT   "/sys/class/gpio/export"    
#define SYS_GPIO_UNEXPORT "/sys/class/gpio/unexport"

/**
 * @description: 配置gpio模式
 * @Author: Niceshow
 * @param : 引脚Id
 * @return {type} 
 */
int dll_gpio_export(int pin)
{
    char buffer[16];
    int len;
    int fd;

    bzero(buffer, sizeof(buffer));
    len = snprintf((char *)buffer, sizeof(buffer), "%d", pin);    
    if((fd = open(SYS_GPIO_EXPORT, O_WRONLY)) < 0)
    {       
        perror(SYS_GPIO_EXPORT);
		//_debug_run(0,"OPEN FAILT :%d\n",pin);
        return -1;
    }
    if(write(fd, buffer, len+1) < 0)
    {         
        close(fd);       
        return -1;
    }
    close(fd);
    return 0;
}

/**
 * @description: 取消配置gpio模式
 * @Author: Niceshow
 * @param : 引脚ID
 * @return {type} 
 */

int dll_gpio_unexport(int pin)
{
    char buffer[16];
    int len;
    int fd;

    bzero(buffer, sizeof(buffer));
    len = snprintf(buffer, sizeof(buffer), "%d", pin);
    if((fd = open(SYS_GPIO_UNEXPORT, O_WRONLY)) < 0)
    {
        perror(SYS_GPIO_UNEXPORT);
		//_debug_run(0,"OPEN FAILT :%d\n",pin);
        return -1;
    }
    if(write(fd, buffer, len+1) < 0)
    {
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

/**
 * @description: 设置引脚输入输出方向
 * @Author: Niceshow
 * @param : 
 * @return {type} 
 */
int dll_gpio_direction(int pin, IOdir direction)
{
    char path[128];
    int fd;

    bzero(path, sizeof(path));
    snprintf((char *)path, sizeof(path), "/sys/class/gpio/gpio%d/direction", pin);
    if((fd = open(path, O_WRONLY)) < 0)
    {
        perror(SYS_GPIO_UNEXPORT);
		//_debug_run(0,"OPEN FAILT :%d\n",pin);
        return -1;
    }

    switch(direction)
    {
        case GPIODIR_IN:      
            write(fd, "in", sizeof("in"));
            break;
        case GPIODIR_OUT:
            write(fd, "out", sizeof("out"));
            break;
        default:
            break;
    }
    close(fd);
    return 0;
}

/**
 * @description: 设置引脚电平
 * @Author: Niceshow
 * @param : 
 * @return {type} 
 */
int dll_gpio_setvalue(int pin, int value)
{
    char path[128];
    int fd;

    bzero(path, sizeof(path));
    snprintf((char *)path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);
    if((fd = open(path, O_WRONLY)) < 0)
    {
        perror(SYS_GPIO_UNEXPORT);
		//_debug_run(0, "OPEN FAILT :%d\n",pin);
        return -1;
    }

    if (0 == value)
    {
        if((write(fd, "0", sizeof("0")) < 0))
        {
            ;
        }
    } else if(1 == value){
        if((write(fd, "1", sizeof("1"))) < 0)
        {
            ;
        }
    } else {
        printf("error value.:%d\n",pin);
    }
    close(fd);
    return 0;
}

/**
 * @description: 获取引脚电平
 * @Author: Niceshow
 * @param : 
 * @return {type} 
 */
unsigned char dll_gpio_getvalue(int pin)
{
    char path[128];
    char buffer[8];
    int fd;

    bzero(path, sizeof(path));
    snprintf((char *)path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);
    if((fd = open(path, O_RDONLY)) < 0)
    {
        perror(SYS_GPIO_UNEXPORT);
		//_debug_run(0, "OPEN FAILT :%d\n", pin);
        return -1;
    }
    if((read(fd, buffer, sizeof(buffer))) < 0)
    {  
        close(fd);
        return -1;
    }
    close(fd);
	if(atoi(buffer) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}   
}

/**
 * @description: 引脚电平切换
 * @Author: Niceshow
 * @param : 
 * @return {type} 
 */
void dll_gpio_tigger(int pin)
{
	int a = dll_gpio_getvalue(pin);	
	if(a > 0)
	{
		dll_gpio_setvalue(pin,0);
	}
	else
	{
		dll_gpio_setvalue(pin,1);		
	}
}