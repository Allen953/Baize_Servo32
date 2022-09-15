/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */
/*******************************************************
   Baize_ServoDriver_esp32
   功能：串口话题通信
   引脚：SDA:21   SCL:22
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-09-13 19:35
 *******************************************************/
 
 
#include <ros.h>
#include <std_msgs/String.h>
#include <SPI.h>
#include <TFT_eSPI.h>       // Hardware-specific library
TFT_eSPI TFT = TFT_eSPI();  // Invoke custom library
 
ros::NodeHandle  nh;
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
char hello[15] = "hello world!";
long time_s=0;
void setup()
{
  nh.initNode();
  nh.advertise(chatter);
    TFT.init();
    TFT.setRotation(3);
    TFT.fillScreen(TFT_BLACK);
    TFT.initDMA();
  TFT.setCursor(0, 0, 4);
  // Set the font colour to be white with a black background
  TFT.setTextColor(TFT_WHITE, TFT_BLACK);
  // We can now plot text on screen using the "print" class
  TFT.println("Initialised default\n"); 
  time_s = millis();
}
void loop()
{
    str_msg.data = hello;
    chatter.publish( &str_msg );
    nh.spinOnce();
    time_s = millis();  
  delay(1000);
}
