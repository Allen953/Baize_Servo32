/*******************************************************
   Baize_ServoDriver_esp32
   功能：测试显示屏
   引脚：MOSI:21   CLK:18   RS:12   RES:13   CS:5   BLK:15
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-22
*******************************************************/
  
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);
 
#define SERVOMIN  102               //0.5/20 * 4096 = 102
#define SERVOMAX  512               //2.5/20 * 4096 = 512
//pcb板测试时，如果是2S的锂电池供电，则以此电压为阈值，低于此电压时，不再驱动舵机运动，保护电池。
float voltage_threshold = 6.5;
int voltage_testpin = 26;
float voltage_b = 0.0;
 
bool servo_f = 1;
 
 
 
 
 
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("16 channel Servo test!");
  
  pwm.begin();
  pwm1.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  pwm1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
 
  delay(200);
  for(int i=0;i<16;i++)
  {
    pwm.setPWM(i, 0, SERVOMIN); // 驱动32路舵机转到0度
    pwm1.setPWM(i, 0, SERVOMIN);// 驱动32路舵机转到0度
  }
  delay(2000);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, pulselen);
          pwm1.setPWM(i, 0, pulselen);
        }
        delayMicroseconds(200);
  }
}
 
void loop() {
  if(servo_f==1)
  {
        for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
              for(int i=0;i<16;i++)
              {
                pwm.setPWM(i, 0, pulselen);
                pwm1.setPWM(i, 0, pulselen);
              }
              delayMicroseconds(200);
        }
        //电压检测
        int voltage_sum = 0.0;
        for(int i=0;i<10;i++)
        {
          voltage_sum += float(analogRead(voltage_testpin))/4095.0*3.3*4.0;
          Serial.println(analogRead(voltage_testpin));
          delay(100);
        }
        voltage_b = voltage_sum / 10.0;
        Serial.println(voltage_b);
        if(voltage_b<voltage_threshold)
        servo_f = 0;
        
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, SERVOMIN); // 驱动32路舵机转到0度
          pwm1.setPWM(i, 0, SERVOMIN);// 驱动32路舵机转到0度
        }
        delay(2000);
  }
 
 
}
