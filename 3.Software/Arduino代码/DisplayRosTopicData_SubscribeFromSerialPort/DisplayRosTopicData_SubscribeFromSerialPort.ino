/*******************************************************
   Baize_ServoDriver_esp32
   功能：WiFi话题通信订阅消息并显示
   引脚：SDA:21   SCL:22
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-09-13 21:40
 *******************************************************/
 
#include <ros.h>
#include <std_msgs/String.h>
 
#include <SPI.h>
#include <TFT_eSPI.h>       // Hardware-specific library
TFT_eSPI TFT = TFT_eSPI();  // Invoke custom library
 
 
void chatterCallback(const std_msgs::String& msg) {
//  TFT.fillScreen(TFT_BLACK);
  TFT.setCursor(0, 30, 4);
  // Set the font colour to be white with a black background
  TFT.setTextColor(TFT_WHITE, TFT_BLACK);
 
  // We can now plot text on screen using the "print" class
  TFT.println(msg.data); 
}
 
ros::NodeHandle  nh;
 
std_msgs::String str_msg;
ros::Publisher chatter("gun", &str_msg);
ros::Subscriber<std_msgs::String> sub("message", chatterCallback);
char hello[13] = "hello!";
 
 
void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  
    TFT.init();
    TFT.setRotation(3);
    TFT.fillScreen(TFT_BLACK);
    TFT.initDMA();
    
  TFT.setCursor(0, 0, 4);
  // Set the font colour to be white with a black background
  TFT.setTextColor(TFT_WHITE, TFT_BLACK);
 
  // We can now plot text on screen using the "print" class
  TFT.println("Initialised default\n"); 
}
 
void loop()
{
    str_msg.data = hello;
    chatter.publish( &str_msg );
 
    nh.spinOnce();
 
  delay(1000);
}
