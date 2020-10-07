const int TrigPin=7;//控制端接口为2
const int EchoPin=8;//接收端接口为3
const int OUTOMME = A1;//灰度传感器out口
int grayValue = 0; 
#include <Wire.h>
float cm;//定义温湿度针脚号为2号引脚 
void setup() 
{
  Serial.begin(9600); // 9600 bps0
  pinMode(TrigPin,OUTPUT);//定义Trig为输出接口
  pinMode(EchoPin,INPUT);
  pinMode(OUTOMME,OUTPUT);
}
void loop()
{
  grayValue = analogRead(OUTOMME);
  digitalWrite(TrigPin,LOW);//低高低电平发一个短时间脉冲去TrigPin
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  cm=pulseIn(EchoPin,HIGH)/58;
  cm=(int(cm*100))/100;//保留两位小数
  if ( Serial.available())
    {
      if('s' == Serial.read())

        Serial.print(cm);
        Serial.println("cm");
        Serial.print("Grayscalse Sensor Value is ");

        Serial.println(grayValue);

        Serial.println();
        delay(1000);
        
     }
}
