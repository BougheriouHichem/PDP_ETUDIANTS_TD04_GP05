#include <DHT.h>

#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP  5  
#define sensor 33 
#define LED 26

#define DHTTYPE DHT11  

touch_pad_t touchPin;

DHT dht(sensor, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();

  // ***************************
  
  //placeholder callback function
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

  delay(100);
  ESP.deepSleep(5e6);
}



void loop(){
  // on met plus rien ici esp32 en mode deep sleep
}

