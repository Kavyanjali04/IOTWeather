#include <WiFi.h>
#include"DHT.h"
#include"ThingSpeak.h"
const char* ssid ="#####";
const char* password ="#####";
WiFiClient Client;
unsigned long myChannelNumber =;
const char * myWriteAPIKey ="";
float temp=0;
float hum=0;
int pot=0;
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTyPE);
void send_thinkspeak(){
  wifi_connect();
  ThingSpeak.setField(1,string(temp));
  ThingSpeak.setField(2,string(temp));
  ThingSpeak.setField(3,string(temp));
  int X=ThingSpeak.writefields(myChannelNumber,myWriteAPIKey);
  
  Serial.println("the value of X");
  Serial,println(X);
  if(X ==200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("problem updating channel.HTTP error code"+string(X));
  }
}
void read_sensors(){
  hum =dht.readHumidity();
  Serial.println("Humidity");
  Serial.println(hum);
  temp=dht.readTemperature();
  Serial.println("temperature in celcius:");
  Serial.println(temp);
  pot=analogRead(13);
  Serial.println("pot value:");
  Serial.println("pot");
  
}
void wifi_connect()
{
  Serial.println("Attemping to connect");
  if(wifi.status() !=WL_CONNECTED)
  {
    Serial.begin(ssid,password);
    delay(5000)
  }
  Serial.println("\nconnected.");
}
void setup()
{
  Serial
}