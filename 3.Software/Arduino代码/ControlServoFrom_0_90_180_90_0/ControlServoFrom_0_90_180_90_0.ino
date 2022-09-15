/*******************************************************
   Baize_ServoDriver_esp32
   功能：测试舵机
   引脚：SDA:21   SCL:22
   对于ARDUINO UNO，SCL:A5，SDA:A4
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-22
*******************************************************/
  
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);
 
#define SERVOMIN  102               //0.5/20 * 4096 = 102
#define SERVOMID  307              //(102+512)/2=307
#define SERVOMAX  512               //2.5/20 * 4096 = 512
 
//pwm.setPWM(i, 0, pulse);i=0~15对应第0-15个舵机；pwm1.setPWM(j, 0, pulse);j=0~15对应第16-31个舵机，
 
void setup() {
  Serial.begin(115200);
  Serial.println("16 channel Servo test!");
  
  pwm.begin();
  pwm1.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  pwm1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
}
 
void loop() {
   //全部舵机转到0度
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, SERVOMIN);
          pwm1.setPWM(i, 0, SERVOMIN);
        }
        delayMicroseconds(200);
        delay(1000);
  //全部舵机转到90度
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, SERVOMID);
          pwm1.setPWM(i, 0, SERVOMID);
        }
        delayMicroseconds(200);
        delay(1000);
  //全部舵机转到180度
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, SERVOMAX);
          pwm1.setPWM(i, 0, SERVOMAX);
        }
        delayMicroseconds(200);
        delay(1000);
  //全部舵机转到90度
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, SERVOMID);
          pwm1.setPWM(i, 0, SERVOMID);
        }
        delayMicroseconds(200);
        delay(1000);
}
