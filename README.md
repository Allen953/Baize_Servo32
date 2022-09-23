# Baize_ServoDriver_esp32

该机器人开发板的用法和介绍以CSDN的文章为准：https://blog.csdn.net/qqliuzhitong/article/details/126445164
最新的代码以本仓库为准，本仓库总是存放最新代码，CSDN的代码可能存在滞后。

出于制作机器人的需要，设计了这块儿32路舵机驱动板，板子可以驱动从5~12V的pwm舵机，适应电压范围较宽，所以用起来会非常方便。

板载有电压监测电路和蜂鸣器，这样如果你使用电池为机器人供电时，可以通过电压检测电路来测量电池电量情况，如果电量过低，则需要报警并停止机器人动作，提示我们进行充电。

板载还有mpu6050，这样我们可以感知机器人的姿态等信息，可以根据机器人姿态进行动作的规划。

同时板载一个小型彩色屏幕1.14寸，140*240的分辨率，可以实时显示板子和机器人的状态，方便机器人的现场测试。

板子上还有几个独立按键，作为调试按钮，可以灵活定制按钮功能，对机器人进行调试。

![图片例程](https://github.com/Allen953/Baize_ServoDriver_esp32/blob/main/7.Photos%20%26%20Videos/IMG_20220913_124243.jpg)


![图片例程2](https://github.com/Allen953/Baize_ServoDriver_esp32/blob/main/7.Photos%20%26%20Videos/QQ%E5%9B%BE%E7%89%8720220825144041.png)

