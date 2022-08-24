/*******************************************************
   Baize_ServoDriver_esp32
   功能：角度映射
   引脚：SDA:21   SCL:22
   对于ARDUINO UNO，SCL:A5，SDA:A4
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-24
*******************************************************/
 
//#define SERVOMIN  102               //0.5/20 * 4096 = 102
//#define SERVOMID  307               //1.5/20 * 4096 = 307
//#define SERVOMAX  512               //2.5/20 * 4096 = 512
//实际测试
#define SERVOMIN  102               
#define SERVOMID  327               
#define SERVOMAX  552
int hello[18]={1500,1529,1500,1549,1529,1481,1434,1500,1355,1466,1513,1546,1423,1452,1500,1444,1529,1586};
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("{");
  delay(1);
  for(int i=0;i<18;i++)
  {
    Serial.print(map(hello[i],500,2500,SERVOMIN,SERVOMAX));
    Serial.print(",");
    delay(1);
  }
  Serial.print("}");
  
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
}
