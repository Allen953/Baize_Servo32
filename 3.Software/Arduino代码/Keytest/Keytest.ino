/*******************************************************
   Baize_ServoDriver_esp32
   功能：测试独立按键
   引脚：key1:35    key2:34    key3:39    key4:36
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-09-09 21:08
*******************************************************/
 
#define key1 35
#define key2 34
#define key3 39
#define key4 36
 
void setup() {
  Serial.begin(115200);
  pinMode(key1,INPUT);
  pinMode(key2,INPUT);
  pinMode(key3,INPUT);
  pinMode(key4,INPUT);
}
 
void loop() {
  Serial.print("key1:");
  Serial.print(digitalRead(key1));
  Serial.print("    ");
  Serial.print("key2:");
  Serial.print(digitalRead(key2));
  Serial.print("    ");
  Serial.print("key3:");
  Serial.print(digitalRead(key3));
  Serial.print("    ");
  Serial.print("key4:");
  Serial.print(digitalRead(key4));
  Serial.println();
}
