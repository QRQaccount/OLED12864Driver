#ifndef _OLED12864_H
#define _OLED12864_H

#include "stm32f1xx_hal.h"

#define OLED_CLK_Port GPIOA          // 时钟信号端口组
#define OLED_CLK_GPIO_Pin GPIO_PIN_4 // 时钟信号端口号
#define OLED_DI_Port GPIOA           // SPI:MISO端口组 IIC:
#define OLED_DI_GPIO_Pin GPIO_PIN_5  // SPI:MISO端口号 IIC:
#define OLED_RST_Port GPIOA          // 重置信号端口组
#define OLED_RST_GPIO_Pin GPIO_PIN_6 // 重置信号端口号
#define OLED_DC_Port GPIOA           // 指令/数据端口组
#define OLED_DC_GPIO_Pin GPIO_PIN_7  // 指令/数据端口号

#define OLED_SPI_Mode 1 //SPI通信方式
#define OLED_IIC_Mode 0 //IIC通信方式

// 用于设置与OLED12864的连接方式,支持SPI与IIC两种方式
#define CONNECTION_MODE OLED_SPI_Mode

// 初始化需要使用的GPIO口

// 常用形状
typedef enum OLED_Shap
{
    Square,   // 正方形
    Triangle, // 等边三角形
    Circular  //圆形
} OLED_Shap;

// 用于记录点的位置和值.令左上角为(0,0)
typedef struct
{
    uint16_t x;
    uint16_t y;
} OLED_Point;

/**
 * 
 * OLED12864初始化
 * 
*/
void OLED_Init(void);

/**
 * 
 * 绘制常用图形
 * @param shap 由枚举类型Shap定义绘制图形的形状,
 * @param center 图形的中心点
 * @param R 16位无符号整型.当图形是圆时R表示圆的半径.当图形是等边三角形时R表示中点到顶角的距离.当图形表示正方形时R表示二分之一斜边长度
*/
void OLED_DrawShap(OLED_Shap shap, OLED_Point center, uint16_t R);

/**
 * 
 * 绘制一个点
 * @param node 在屏幕上画出一个指定位置的点
*/
void OLED_DrawPoint(OLED_Point point);

/**
 * 
 * 绘制一连串的点
 * @param arrary_pointer OLED_Point的数组指针
 * @param length 传入的数组长度
*/
void OLED_DrawArray(OLED_Point *array_pointer, uint16_t length);

/**
 * 
 * 将数据填充到整个屏幕
*/
void OLED_Fill(unsigned char data);

/**
 * 
 * 绘制一条线段
 * @param point1 第一个点的坐标
 * @param point2 第二个点的坐标
*/
void OLED_DrawLine(OLED_Point point1, OLED_Point point2);

// 字体大小
typedef enum
{
    small,
    big
} FontSize;

/**
 * 
 * 输出指定字体大小的ASCII字符
 * @param character 需要输入的字符
 * @param start_point 字符的位置
 * @param font_size 字体大小
*/
void OLED_DrawCharacter(char character, OLED_Point start_point, FontSize font_size);

/**
 * 
 * 输出指定字体大小的ASCII字符串
 * @param str 字符串
 * @param start_point 字符的位置
 * @param font_size 字体大小
*/
void OLED_DrawString(const char str[], OLED_Point start_point, FontSize font_size);

#endif