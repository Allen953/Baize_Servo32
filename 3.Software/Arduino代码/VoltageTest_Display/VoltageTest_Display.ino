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
#include <SPI.h>
#include <TFT_eSPI.h>
 
TFT_eSPI TFT = TFT_eSPI();
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);
 
#define SERVOMIN  102               //0.5/20 * 4096 = 102
#define SERVOMID  307               //(102+512)/2=307
#define SERVOMAX  512               //2.5/20 * 4096 = 512
//pcb板测试时，如果是2S的锂电池供电，则以此电压为阈值，低于此电压时，不再驱动舵机运动，保护电池。
int voltage_testpin = 16;
float vol = 0.0;
 
void setup() {
  TFT.init();
  TFT.setRotation(3);
  TFT.fillScreen(TFT_BLACK);
  TFT.initDMA();
  
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
     //全部舵机转到0度
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, SERVOMIN);
          pwm1.setPWM(i, 0, SERVOMIN);
        }
        delayMicroseconds(200);
        vol = float(analogRead(voltage_testpin))/4095.0*3.3*4.0;
        TFT.setCursor(10, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
        TFT.setTextColor(TFT_WHITE, TFT_BLACK);
        TFT.println("Voltage:\n");    
        TFT.setCursor(105, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
        TFT.setTextColor(TFT_WHITE, TFT_BLACK);
        TFT.println(vol); 
        delay(1000);
        
  //全部舵机转到90度
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, SERVOMID);
          pwm1.setPWM(i, 0, SERVOMID);
        }
        delayMicroseconds(200);
        vol = float(analogRead(voltage_testpin))/4095.0*3.3*4.0;
        TFT.setCursor(10, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
        TFT.setTextColor(TFT_WHITE, TFT_BLACK);
        TFT.println("Voltage:\n");    
        TFT.setCursor(105, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
        TFT.setTextColor(TFT_WHITE, TFT_BLACK);
        TFT.println(vol); 
        delay(1000);
        
  //全部舵机转到180度
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, SERVOMAX);
          pwm1.setPWM(i, 0, SERVOMAX);
        }
        delayMicroseconds(200);
        vol = float(analogRead(voltage_testpin))/4095.0*3.3*4.0;
        TFT.setCursor(10, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
        TFT.setTextColor(TFT_WHITE, TFT_BLACK);
        TFT.println("Voltage:\n");    
        TFT.setCursor(105, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
        TFT.setTextColor(TFT_WHITE, TFT_BLACK);
        TFT.println(vol); 
        delay(1000);
        
  //全部舵机转到90度
        for(int i=0;i<16;i++)
        {
          pwm.setPWM(i, 0, SERVOMID);
          pwm1.setPWM(i, 0, SERVOMID);
        }
        delayMicroseconds(200);
        vol = float(analogRead(voltage_testpin))/4095.0*3.3*4.0;
        TFT.setCursor(10, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
        TFT.setTextColor(TFT_WHITE, TFT_BLACK);
        TFT.println("Voltage:\n");    
        TFT.setCursor(105, 10, 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
        TFT.setTextColor(TFT_WHITE, TFT_BLACK);
        TFT.println(vol); 
        delay(1000);
 
}
