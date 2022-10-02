/**
  ESP32 最简单直接获取网络时间方法
*/

#include <WiFi.h>
#include <SPI.h>
#include <TFT_eSPI.h>
 
TFT_eSPI TFT = TFT_eSPI();


#define NTP1  "ntp1.aliyun.com"
#define NTP2  "ntp2.aliyun.com"
#define NTP3  "ntp3.aliyun.com"

//填写WIFI入网信息
const char* ssid     = "Zhitong";     // WIFI账户
const char* password = "95359897"; // WIFI密码

void setClock() {
  struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {//如果获取失败，就开启联网模式，获取时间
        Serial.println("Failed to obtain time");
     //    WiFi.disconnect(false);
        WiFi.mode(WIFI_STA);//开启网络  
       WiFi.begin(ssid, password);
         while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
     configTime(8 * 3600, 0, NTP1, NTP2,NTP3);
        return;
    }
    Serial.println(&timeinfo, "%F %T %A"); // 格式化输出:2021-10-24 23:00:44 Sunday
    Serial.print(asctime(&timeinfo));//默认打印格式：Mon Oct 25 11:13:29 2021
  //   WiFi.disconnect(true);//断开网络连接，关闭网络
  TFT.fillScreen(TFT_BLACK);
  TFT.setCursor(0, 0, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
  TFT.setTextColor(TFT_WHITE, TFT_BLACK);
  TFT.println(asctime(&timeinfo));
}

void setup()
{
  TFT.init();
    TFT.setRotation(3);
    TFT.fillScreen(TFT_BLACK);
    TFT.initDMA();

    Serial.begin(115200);
    Serial.println();
 //设置ESP32工作模式为无线终端模式
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi connected!");
 configTime(8 * 3600, 0, NTP1, NTP2,NTP3);
      setClock();
    // 从网络时间服务器上获取并设置时间
    // 获取成功后芯片会使用RTC时钟保持时间的更新
   
//    WiFi.disconnect(true);//断开wifi网络
//    WiFi.mode(WIFI_OFF);//关闭网络
    Serial.println("WiFi disconnected!");
}

void loop()
{
  Serial.println("Waiting 10s before the next round...");
  delay(1000);
  setClock();
}
