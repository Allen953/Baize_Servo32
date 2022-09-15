/*******************************************************
   Baize_ServoDriver_esp32
   功能：按键调参
   引脚：MOSI:21   CLK:18   RS:12   RES:13   CS:5   BLK:15
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-09-09 23:30
*******************************************************/
#include <SPI.h>
#include <TFT_eSPI.h>
#define key1 35
#define key2 34
#define key3 39
#define key4 36
 
bool key1s=0,key2s=0,key3s=0,key4s=0;
int a=0,b=0;
 
TFT_eSPI TFT = TFT_eSPI();
char cmd = 'e';//a:forward b:backward c:left d:right e:stop 
 
long times=0;
 
void setup() {
  Serial.begin(115200);
    TFT.init();
    TFT.setRotation(3);
    TFT.fillScreen(TFT_BLACK);
    TFT.initDMA();
 
    pinMode(key1,INPUT);
    pinMode(key2,INPUT);
    pinMode(key3,INPUT);
    pinMode(key4,INPUT);
 
    times = millis();
}
 
void loop() {
//  TFT.setCursor(10, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
//  TFT.setTextColor(TFT_WHITE, TFT_BLACK);
//  TFT.println("Hello Allen!\n");
  if(cmd == 'a')
  {
    
  }
  else if(cmd == 'b')
  {
    
  }
  else if(cmd == 'd')
  {
    
  }
  else if(cmd =='e')
  {
    Serial.println("hello");
    if(digitalRead(key1)==1)
    {
      delay(5);
      if(digitalRead(key1)==1)
      {
        if(key1s==0)
        {
          a++;
          key1s=1;
 
        }
      }
    }
    if(digitalRead(key1)==0)
    {
      delay(5);
      if(digitalRead(key1)==0)
      {
        if(key1s==1)
        {
          key1s=0;
 
        }
      }
    }
    if(digitalRead(key2)==1)
    {
      delay(5);
      if(digitalRead(key2)==1)
      {
        if(key2s==0)
        {
          a--;
          key2s=1;
        }
      }
    }
    if(digitalRead(key2)==0)
    {
      delay(5);
      if(digitalRead(key2)==0)
      {
        if(key2s==1)
        {
          key2s=0;
        }
      }
    }
  }
  else if(cmd == 'f')
  {
    
  }
          TFT.setCursor(10, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
          TFT.setTextColor(TFT_WHITE, TFT_BLACK);
          TFT.println("a:");
          TFT.drawNumber(a, 50, 10);               // Draw float using current font
  if(millis()-times>100)
  {
    TFT.fillScreen(TFT_BLACK);
    times = millis();
  }
}
