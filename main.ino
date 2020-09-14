
#include <dht.h>


dht DHT;


const int trigPin=9;
const int echoPin=10;
const int dhtpin=7;
long duration;
long distance;
void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);

}

void loop()
{
  int chk = DHT.read11(dhtpin);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  //Sending_To_phpmyadmindatabase();
  delay(3000);
}
