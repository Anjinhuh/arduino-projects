#include "DHT.h"
#define pino_sinal_analogico A5
#define DHTPIN A0 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11


DHT dht(DHTPIN, DHTTYPE);
 int valor_analogico;
void setup() 
{
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  Serial.println("JUJU LINDO");
  dht.begin();
}
 
void loop() 
{
  valor_analogico = analogRead(pino_sinal_analogico);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } 
  else{
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
    Serial.print("Porta analogica: ");
    Serial.print(valor_analogico);
  }
}
