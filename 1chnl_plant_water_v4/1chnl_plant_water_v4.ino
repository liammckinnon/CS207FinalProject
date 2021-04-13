


int WETSnsr = A0; //Analog pin for moisture sensor
int TMPSnsr = A1; //Analog pin for temperature sensor
int Relay1 = 2;
int Relay2 = 3;
//int Relay3 = 4;
float MstLvl = 350;
float TempLvl = 13;

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
  digitalWrite (Relay2,HIGH);
  //digitalWrite (Relay3,HIGH);





}
void loop() {

float Cels;
    int Temp = analogRead(TMPSnsr);
    Serial.println (Temp);
  int MVolts = (Temp)*(5000/1023);
   Cels = ((MVolts-500)/10);
 Serial.print(Cels);
 Serial.println ("C");


   if (Cels > 13 )
   {
    
     digitalWrite(Relay2, LOW); //Turn on fan
   } 
   else
   {
    digitalWrite(Relay2, HIGH); //Turn off fan
   }

   
    if(digitalRead(FLOAT_SENSOR) == HIGH) //Check float pump
  { 
    Serial.println("float up");
    RunPump();
  }
  else
{
  Serial.println("Float Down"); //Indicates that the float pump is down/reservoir is empty
}
  
  

  delay(500);
}


void RunPump()
{
    
  
   float ML=analogRead(WETSnsr);
   Serial.print("MOISTURE LEVEL:");
  Serial.println(ML);
  if (ML > MstLvl)
  {
    digitalWrite(Relay1, LOW);
    Serial.println("watering");
    delay(1000);
    digitalWrite(Relay1, HIGH);
    Serial.println("Pump off");
    delay(1000);
    
  }

}
