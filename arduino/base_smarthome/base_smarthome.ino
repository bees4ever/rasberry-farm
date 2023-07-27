
// TIME: https://playground.arduino.cc/Code/Time/?_gl=1*14yn4h1*_ga*MTYxNzc0MzMyNy4xNjg5NjE5Njc5*_ga_NEXN8H46L5*MTY4OTYxOTY3OC4xLjEuMTY4OTYyMDI4OS4wLjAuMA..
#include <TimeLib.h>

/////// CONSTANTS

int PIN_PUMP_RELEASE_A = 1;
int PIN_PUMP_RELEASE_B = 1;
int PIN_PUMP_RELEASE_C = 1;


int PLANT_A_HUMIDTY = A0;
int PLANT_B_HUMIDTY = A1;
int PLANT_C_HUMIDTY = A0;

int PIN_ECHOLOT_TRIGGER = 7;
int PIN_ECHOLOT_ECHO = 6;


void doPinConfig() {
  pinMode(PIN_ECHOLOT_TRIGGER, OUTPUT); // Trigger-Pin ist ein Ausgang
  pinMode(PIN_ECHOLOT_ECHO, INPUT); // Echo-Pin ist ein Eingang

}


void setupEthernet() {
  // todo PIN config
}


bool sendValueToRasbery(String value) {,<. 

}


/*Functions to read values from PINS / Devices*/

float getTemperature() {
  return 1;
}

float getHumididty(int pin) {
  return 1;
}

int getPlantHumidity(int pin) {
int messwert=analogRead(pin); //Die Spannung an dem Sensor wird ausgelesen und unter der Variable „messwert“ gespeichert.

  Serial.print("Feuchtigkeits-Messwert:"); //Ausgabe am Serial-Monitor: Das Wort „Feuchtigkeits-Messwert:"

  Serial.println(messwert); //und im Anschluss der eigentliche Messwert.
return messwert;
}

long getDistance() {
 
  digitalWrite(PIN_ECHOLOT_TRIGGER, LOW); //Hier nimmt man die Spannung für kurze Zeit vom Trigger-Pin, damit man später beim senden des Trigger-Signals ein rauschfreies Signal hat.
delay(5); //Dauer: 5 Millisekunden
digitalWrite(PIN_ECHOLOT_TRIGGER, HIGH); //Jetzt sendet man eine Ultraschallwelle los.
delay(10); //Dieser „Ton“ erklingt für 10 Millisekunden.
digitalWrite(PIN_ECHOLOT_TRIGGER, LOW);//Dann wird der „Ton“ abgeschaltet.
long dauer = pulseIn(PIN_ECHOLOT_ECHO, HIGH); //Mit dem Befehl „pulseIn“ zählt der Mikrokontroller die Zeit in Mikrosekunden, bis der Schall zum Ultraschallsensor zurückkehrt.
long entfernung = (dauer/2) * 0.03432; //Nun berechnet man die Entfernung in Zentimetern. Man teilt zunächst die Zeit durch zwei (Weil man ja nur eine Strecke berechnen möchte und nicht die Strecke hin- und zurück). Den Wert multipliziert man mit der Schallgeschwindigkeit in der Einheit Zentimeter/Mikrosekunde und erhält dann den Wert in Zentimetern.

  
  
  if (entfernung >= 500 || entfernung <= 0) //Wenn die gemessene Entfernung über 500cm oder unter 0cm liegt,…
  {
    //Serial.println("Kein Messwert"); //dann soll der serial monitor ausgeben „Kein Messwert“, weil Messwerte in diesen Bereichen falsch oder ungenau sind.
    return -1;
  }
  else //  Ansonsten…
  {
    return entfernung;
    //Serial.print(entfernung); //…soll der Wert der Entfernung an den serial monitor hier ausgegeben werden.
    //Serial.println(" cm"); // Hinter dem Wert der Entfernung soll auch am Serial Monitor die Einheit "cm" angegeben werden.
  }
} 

float getSoilHumidityByPlant(String plant) {
  if (plant == "A") {
    return getPlantHumidity(PLANT_A_HUMIDTY);
  }

  if (plant == "B") {
    return getPlantHumidity(PLANT_B_HUMIDTY);
  }

  if (plant == "C") {
    return getPlantHumidity(PLANT_C_HUMIDTY);
  }
}


String WATERING_MODI_LOW = "low";
String WATERING_MODI_MEDIUM = "low";
String WATERING_MODI_HEIGH = "low";

float PLANT_A_THRESHOLD = 0.0;
float PLANT_B_THRESHOLD = 0.0;
float PLANT_C_THRESHOLD = 0.0;


void runWaiteringProcessByModi(String modi) {
  if (modi == WATERING_MODI_LOW) {

  }
}

int PLANT_A_INDEX = 1;
int PLANT_B_INDEX = 2;
int PLANT_C_INDEX = 3;

time_t lastWateringByPlant[] = {0, 0, 0};

void controllerCheckHumidityAndHandlePump() {
  time_t t = now();

  // check if last watering is at least 24 ago to avoid over watering

  // get humidity of soil by plant ID/Name and check
  // a) is it below a threshold
  // b) what is the average of last 7 days
  // c) then run a watering process, the process has different modi. Load the modi from plant config and run the process

}

/**
    Full logic of all KPIs sending to rasberry
*/
void sendBundleOfKPIsToRasberry() {

}

void setup() {
    // put your main code here, to run repeatedly:
Serial.begin (9600); 

  // put your setup code here, to run once:
  doPinConfig();
  setupEthernet();

}

void loop() {

  sendBundleOfKPIsToRasberry();
float distance = getDistance();
getSoilHumidityByPlant("A");
Serial.println(distance);
delay(1000); //Das delay von einer Sekunde sorgt in ca. jeder neuen Sekunde für einen neuen Messwert.
}
