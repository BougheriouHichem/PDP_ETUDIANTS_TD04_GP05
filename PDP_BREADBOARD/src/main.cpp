#include <DHT.h>

#define sensor 33 
#define LED 26

#define DHTTYPE DHT11  

DHT dht(sensor, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // on verivie si les variables sont bien chargées
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Calculer l'indice de chaleur en Fahrenheit (valeur par défaut)
  float hif = dht.computeHeatIndex(f, h);
  // Calculer l'indice de chaleur en degrés Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

// Effectuer une mesure toutes les 5s
  delay(5000);

  // Afficher l'humidité relative avec un peu de formatage
  Serial.print(F("Humidity: "));
  Serial.print(h);

  // Afficher la température avec un peu de formatage
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F"));
  Serial.println("...");
}