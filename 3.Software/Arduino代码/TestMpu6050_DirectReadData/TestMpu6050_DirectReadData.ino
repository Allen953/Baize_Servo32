/*******************************************************
   Baize_ServoDriver_esp32
   功能：测试mpu6050
   引脚：SDA:21   SCL:22
   对于ARDUINO UNO，SCL:A5，SDA:A4
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-22
*******************************************************/
 
#include "Wire.h"          //I2C通讯库
#include "I2Cdev.h"        //
#include "MPU6050.h"       //mpu6050库
 
MPU6050 mympu;             //定义mympu对象
 
float pi=3.1415926;             //Π的值，用于单位转换
float AcceRatio=16384.0;        //加速度计比例系数
float GyroRatio=131.0;          //陀螺仪比例系数             
//定义3个变量，用于存储倾角数据
float angle_x=0.0,angle_y=0.0,angle_z=0.0;
int16_t ax=0,ay=0,az=0,gx=0,gy=0,gz=0;     //加速度计陀螺仪原始数据
float accx=0.0,accy=0.0,accz=0.0;
 
void setup(){   
  Wire.begin();//开启iic通讯，mpu6050的数据传输协议为iic
  Serial.begin(115200);//打开串口
  mympu.initialize();  //初始化mpu6050
}
 
void loop() {
    //通过调用该函数，一次性从mpu6050获取6轴数据
    mympu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
    accx=ax/AcceRatio;              //x轴加速度
    accy=ay/AcceRatio;              //y轴加速度
    accz=az/AcceRatio;              //z轴加速度
    angle_x=(atan(accx/accz)*180/pi); //计算身体前后的倾角，绕y轴的转角
    angle_y=(atan(accy/accz)*180/pi); //计算身体左右的倾角，绕x轴的转角
    Serial.print(az);Serial.print("     ");//将z轴加速度原始数据输出
    Serial.print(accx);Serial.print("     ");//将3轴加速度输出（单位:g)
    Serial.print(accy);Serial.print("     ");//将两个转角从串口输出
    Serial.print(accz);Serial.print("     ");//将两个转角从串口输出
    Serial.print(angle_x);Serial.print("     ");//将两个转角从串口输出
    Serial.print(angle_y);Serial.println("   ");
    delay(100);
}
