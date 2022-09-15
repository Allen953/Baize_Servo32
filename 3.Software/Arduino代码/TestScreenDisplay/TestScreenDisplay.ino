/*******************************************************
   Baize_ServoDriver_esp32
   功能：测试显示屏
   引脚：MOSI:21   CLK:18   RS:12   RES:13   CS:5   BLK:15
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-22
*******************************************************/
#include <SPI.h>
#include <TFT_eSPI.h>
 
TFT_eSPI TFT = TFT_eSPI();
 
void setup() {
    TFT.init();
    TFT.setRotation(3);
    TFT.fillScreen(TFT_BLACK);
    TFT.initDMA();
}
 
void loop() {
  TFT.setCursor(10, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
  TFT.setTextColor(TFT_WHITE, TFT_BLACK);
  TFT.println("Hello Allen!\n");
}
