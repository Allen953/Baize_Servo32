/*******************************************************
   Baize_ServoDriver_esp32
   功能：上位机联合调试
   引脚：SDA:21   SCL:22
   对于ARDUINO UNO，SCL:A5，SDA:A4
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-09-24 21:23
*******************************************************/

#include "BluetoothSerial.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

//#define SERVOMIN  102               //0.5/20 * 4096 = 102
//#define SERVOMID  307               //1.5/20 * 4096 = 307
//#define SERVOMAX  512               //2.5/20 * 4096 = 512
//实际测试
#define SERVOMIN  102               
#define SERVOMID  327               
#define SERVOMAX  552 

String buffer;
char ServoEnd = 'P',PulseEnd = 'T';
int ServoNum = 0,PulseNum = 1500;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32test"); //Bluetooth device name

  pwm.begin();
  pwm1.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  pwm1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println(buffer);
  Serial.println(buffer.toInt()*2);
  while(Serial.readStringUntil('+')!="#Vers")
  {
    delay(500);
    Serial.flush();
  }
  SerialBT.println("Connected!");
  
}

void loop() {
  if (Serial.available()) {
    while(Serial.read()!='#')delayMicroseconds(10);
    buffer = Serial.readStringUntil('P');
//    SerialBT.print(buffer);
    ServoNum = buffer.toInt();
    SerialBT.print(ServoNum);
    while(!Serial.available())delayMicroseconds(10);
    buffer = Serial.readStringUntil('T');
    SerialBT.print(",");
    PulseNum = buffer.toInt();
    SerialBT.println(PulseNum);
//    SerialBT.write(Serial.read());
  if((ServoNum>=0)&&(ServoNum<16))
    pwm.setPWM(ServoNum-1, 0, map(PulseNum,500,2500,SERVOMIN,SERVOMAX));
  else if((ServoNum>=16)&&(ServoNum<32))
    pwm1.setPWM(ServoNum-17, 0, map(PulseNum,500,2500,SERVOMIN,SERVOMAX));
  else;
  delayMicroseconds(100);
  }
  delayMicroseconds(100);
}
