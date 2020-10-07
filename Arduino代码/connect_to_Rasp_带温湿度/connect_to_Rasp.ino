const int TrigPin=7;//控制端接口为2
const int EchoPin=8;//接收端接口为3
#include <Wire.h>
#include <dht11.h>  
#define DHT11PIN 14 
float cm;//定义温湿度针脚号为2号引脚
dht11 DHT11; 
void setup() 
{
  Serial.begin(9600); // 9600 bps0
  pinMode(TrigPin,OUTPUT);//定义Trig为输出接口
  pinMode(EchoPin,INPUT);/
}
void loop()
{
  DHT11.read(DHT11PIN);
  digitalWrite(TrigPin,LOW);//低高低电平发一个短时间脉冲去TrigPin
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  cm=pulseIn(EchoPin,HIGH)/58;
  cm=(int(cm*100))/100;//保留两位小数
  float h = (float)DHT11.humidity;
  float t = (float)DHT11.temperature;
  if ( Serial.available())
    {
      if('s' == Serial.read())
        Serial.print("温度：");
        Serial.println(t);
        Serial.print("湿度：");
        Serial.println(h);
        Serial.print("距离： ");
        Serial.print(cm);
        Serial.println("cm");
        
     }
}
