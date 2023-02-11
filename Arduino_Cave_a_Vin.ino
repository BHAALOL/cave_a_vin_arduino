#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
int timer;
bool etatVentilo = false;
bool etatCompresseur = false; 
//String dhtTemp = String(dht.readTemperature());
//String dhtHum = String(dht.readHumidity());
//int temp = dhtTemp.toInt();
//int hum = dhtHum.toInt();
//bool etatVentilo = false;
//bool etatCompresseur = false;


void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() { 
String dhtTemp = String(dht.readTemperature());
String dhtHum = String(dht.readHumidity());
int temp = dhtTemp.toInt();
int hum = dhtHum.toInt();



  if (etatCompresseur == 1){
    Serial.print ("Compresseur allumé il fait: ");
    Serial.print (temp);
    Serial.print ("°C");
    Serial.println("");
    digitalWrite(11, LOW);
    }
    else {
      Serial.print ("Compresseur off il fait:");
      Serial.print(temp);
      Serial.print ("°C");
      Serial.println("");
      digitalWrite(11, HIGH);
      }
       
  if (temp < 12){ // activation du chauffage en dessous de 12
    Serial.println("Valeur du BOOL  1");
    Serial.print("Temperature actuelle : ");
    Serial.print(temp);
    Serial.print("°C");
    Serial.println("");
    etatCompresseur = true;
  }
  else{
    Serial.println("valeur du BOOL  0");
    Serial.print("Temperature actuelle : ");
    Serial.print(temp);
    Serial.print("°C");
    Serial.println("");
    etatCompresseur = false;
    }
    
  if (timer >= 600){ // 50 Min
      Serial.println ("Ventilo ON");
      digitalWrite(12, HIGH);
    }
  else {
    Serial.println("Ventilateur OFF");
    digitalWrite(12, LOW);
    }
  if (timer >= 3600){ // 1H 
    timer = 0;
    Serial.println("RAZ Timer");
    }
  Serial.print("timer :");
  Serial.print(timer);
  Serial.print(" Secondes");
  Serial.println("");
  delay(10000);
  timer = timer + 10 ;
}
