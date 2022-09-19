/*******************************************************
   Baize_ServoDriver_esp32
   功能：串口输入角度，板子驱动舵机转到该角度
   引脚：SDA:21   SCL:22
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-23
 *******************************************************/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();               //驱动1~16或(0~15)号舵机
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);          //驱动17~32或(16~31)号舵机
 
#define SERVOMIN  102               //0.5/20 * 4096 = 102
#define SERVOMID  307               //1.5/20 * 4096 = 307
#define SERVOMAX  512               //2.5/20 * 4096 = 512
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("ControlServo_ViaSerialPort.ino");
  pwm.begin();
  pwm1.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  pwm1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  
}
 
void loop() {
  // put your main code here, to run repeatedly:
  while(!(Serial.available()>0));
  int pwmdata=Serial.parseInt();
 
  for(int i=0;i<16;i++)
  {
    pwm.setPWM(i, 0, pwmdata);
  }
  pwm1.setPWM(0, 0, pwmdata);
  pwm1.setPWM(1, 0, pwmdata);
  delay(500);
  
}
