/*
   ROBO GARDENZILLA
   An Automated Plant Watering System
   By Liam McKinnon
   200237089

   This is a fully automated plant watering and temperature control system.

   Version 4.0: Functional watering and temperature control. Some code in place for a third module.

   Build
   Relay VCC to board 5V

  Relay GND to GND
  Relay 1 common to 5V
  Relay 1 NO to Pump 5V
  Relay 2 common to 5V
  Relay 2 NO to DC fan
  Pin 2 to relay IN1
  Pin 3 to relay IN2

  Pin 13 to float pump
  Soil moisture(SM) VCC to 5V SM GND to GND
  SM AOUT to A0

  TMP 5V to 5V
  TMP GND to GND
  TMP analog (middle pin) to A1


  Using the system:
  Place the sensor in a dry plant. Fill water reservoir and place soil moisture sensor inside. Watch in wonder as your plants grow!
  To change watering threshold, charge the variable float MstLvl.
  To change temperature threshold, change the variable float TempLvl.

*/

int WETSnsr = A0; //Analog pin for moisture sensor
int TMPSnsr = A1; //Analog pin for temperature sensor
int Relay1 = 2;
int Relay2 = 3;
//int Relay3 = 4;
float MstLvl = 350;
float TempLvl = 28;

#define FLOAT_SENSOR 13 //Float sensor setup

void setup() {
  Serial.begin(9600);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  // pinMode (Relay3, OUTPUT);
  pinMode(WETSnsr, INPUT);
  pinMode (TMPSnsr, INPUT);
  pinMode(FLOAT_SENSOR, INPUT_PULLUP);




  digitalWrite(Relay1, HIGH); //Sets relay states to HIGH (open)
  digitalWrite (Relay2, HIGH);
  //digitalWrite (Relay3,HIGH);





}
void loop() {

  float Cels; //Code to convert analog reading to degrees celsius. This should probably be handled by a seperate function.
  int Temp = analogRead(TMPSnsr);
  Serial.println (Temp);
  int MVolts = (Temp) * (5000 / 1023);
  Cels = ((MVolts - 500) / 10);

  Serial.println ("C");//Print degrees Celsius

  if (Cels > TempLvl ) {
    digitalWrite(Relay2, LOW); //Turn on fan
  }
  else
  {
    digitalWrite(Relay2, HIGH); //Turn off fan
  }

  if (digitalRead(FLOAT_SENSOR) == HIGH) {//Check float pump
    Serial.println("float up");
    RunPump();
  }
  else
  {
    Serial.println("Float Down"); //Indicates that the float pump is down/reservoir is empty
  }
  delay(500);//Pause, for easier Serial Monitor reading
}


void RunPump()//Function to control water pumping
{
  float ML = analogRead(WETSnsr);//Check soil moisture sensor
  Serial.print("MOISTURE LEVEL:");
  Serial.println(ML);
  if (ML > MstLvl)
  {
    digitalWrite(Relay1, LOW);//Turn on pump
    Serial.println("watering");
    delay(1000);//Water for one second
    digitalWrite(Relay1, HIGH); //Turn off pump
    Serial.println("Pump off");
    delay(1000);//Wait one second

  }

}
