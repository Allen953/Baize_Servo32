/*******************************************************
   Baize_ServoDriver_esp32
   功能：扫描iic设备
   引脚：SDA:21   SCL:22
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-22
 *******************************************************/
#include <Wire.h>
 
void setup()
{
  Wire.begin();
  Serial.begin(115200);
}
 
void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
  delay(5000);
}
