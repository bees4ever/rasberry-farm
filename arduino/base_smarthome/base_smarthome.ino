
// TIME: https://playground.arduino.cc/Code/Time/?_gl=1*14yn4h1*_ga*MTYxNzc0MzMyNy4xNjg5NjE5Njc5*_ga_NEXN8H46L5*MTY4OTYxOTY3OC4xLjEuMTY4OTYyMDI4OS4wLjAuMA..
#include <TimeLib.h>

/////// CONSTANTS

int PIN_PUMP_RELEASE_A = 1;
int PIN_PUMP_RELEASE_B = 1;
int PIN_PUMP_RELEASE_C = 1;


int PLANT_A_HUMIDTY = 1;
int PLANT_B_HUMIDTY = 1;
int PLANT_C_HUMIDTY = 1;

void doPinConfig(){
  // todo PIN config
}


void setupEthernet(){
  // todo PIN config
}


bool sendValueToRasbery(String value){

}


/*Functions to read values from PINS / Devices*/

float getTemperature(){
  return 1;
}

float getHumididty(int pin){
  return 1;
}

float getPlantHumidity(int pin){

}


float getSoilHumidityByPlant(String plant){
  if (plant == "A"){
    return getPlantHumidity(PLANT_A_HUMIDTY);
  }

  if (plant == "B"){
    return getPlantHumidity(PLANT_B_HUMIDTY);
  }

  if (plant == "C"){
    return getPlantHumidity(PLANT_C_HUMIDTY);
  }
}


String  WATERING_MODI_LOW = "low";
String WATERING_MODI_MEDIUM= "low";
String  WATERING_MODI_HEIGH = "low";

float PLANT_A_THRESHOLD = 0.0;
float  PLANT_B_THRESHOLD = 0.0;
float  PLANT_C_THRESHOLD = 0.0;


void runWaiteringProcessByModi(String modi){
    if (modi == WATERING_MODI_LOW){

    }
}

int PLANT_A_INDEX = 1;
int PLANT_B_INDEX = 2;
int PLANT_C_INDEX = 3;

time_t lastWateringByPlant[] = {0,0,0};

void controllerCheckHumidityAndHandlePump(){
  time_t t = now();

  // check if last watering is at least 24 ago to avoid over watering

  // get humidity of soil by plant ID/Name and check
  // a) is it below a threshold
  // b) what is the average of last 7 days
  // c) then run a watering process, the process has different modi. Load the modi from plant config and run the process

}

/**
  * Full logic of all KPIs sending to rasberry
  */
void sendBundleOfKPIsToRasberry(){

}

void setup() {
  // put your setup code here, to run once:
  doPinConfig();
  setupEthernet();

}

void loop() {
  // put your main code here, to run repeatedly:


  sendBundleOfKPIsToRasberry();


}
