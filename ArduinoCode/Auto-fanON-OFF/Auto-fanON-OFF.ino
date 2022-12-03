#include "DHT.h"    //library for DHT sensors

#define DHTPIN 13   //defined the pin for DHT sensor
#define DHTTYPE DHT11   //type of DHT sensor we are using
  
int fan = 7;  //named the pin 7 as fan 

DHT dht(DHTPIN, DHTTYPE);

void fanOn(){
 	digitalWrite(fan, HIGH);    // if we call fanOn() function the fan gets on
}
void fanOff(){
	digitalWrite(fan, LOW);  // if we call the fanOff function the fan gets off
}


void setup() {
  Serial.begin(9600);  //set the baud rate
  pinMode(fan, OUTPUT);  // making the pin 7 as output pin
  dht.begin();    // making the sensor turn on 
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  
   if( t <= 27){
    fanOff();
    
  }
  else{
    fanOn();  
    
  }
}
