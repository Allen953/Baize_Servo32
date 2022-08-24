/*******************************************************
   Baize_ServoDriver_esp32
   功能：测试蜂鸣器
   引脚：Ｄ2(GPIO2)
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-22
 *******************************************************/
#define LED_PWM 2 //把调用的GPIO引脚进行了一个宏定义
int freq = 5000;
int ledChannel = 0;
int resolution = 8;
void setup() {
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_PWM, ledChannel);
}
void loop() {
  ledcWrite(ledChannel, 180);
  delay(100);
  ledcWrite(ledChannel, 0);
  delay(100);
}
