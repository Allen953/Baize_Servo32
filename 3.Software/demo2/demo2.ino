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
 
//#define SERVOMIN  102               //0.5/20 * 4096 = 102
//#define SERVOMID  307               //1.5/20 * 4096 = 307
//#define SERVOMAX  512               //2.5/20 * 4096 = 512
//实际测试
#define SERVOMIN  102               
#define SERVOMID  327               
#define SERVOMAX  552   
 
void setup() {
  Serial.begin(115200);
  Serial.println("16 channel Servo test!");
  
  pwm.begin();
  pwm1.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  pwm1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
}
 
void loop() {
   for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, pulselen);
          pwm1.setPWM(i, 0, pulselen);
        }
        delayMicroseconds(200);
   }
   for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, pulselen);
          pwm1.setPWM(i, 0, pulselen);
        }
        delayMicroseconds(200);
   }
}
