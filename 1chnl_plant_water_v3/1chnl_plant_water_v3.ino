int Relay1 = 2;
int WETSnsr = A0;
int TMPSnsr = A1;
int Relay2 = 3;
int Relay3 = 4;


#define FLOAT_SENSOR 1

void setup() {
  Serial.begin(9600);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
 pinMode (Relay3, OUTPUT);
  pinMode(WETSnsr, INPUT);
 pinMode (TMPSnsr, INPUT); 
  pinMode(FLOAT_SENSOR, INPUT_PULLUP);
  
  


  digitalWrite(Relay1, HIGH);
  digitalWrite (Relay2,HIGH);
  digitalWrite (Relay3,HIGH);



}
void loop() {

int Cels;
    int Temp = analogRead(TMPSnsr);
    Serial.println (Temp);
  int MVolts = (Temp)*(5000/1023);
   Cels = ((MVolts-500)/10);
 Serial.print(Cels);
 Serial.println ("C");


   if (Cels > 13)
   {
    
     digitalWrite(Relay2, LOW);
   } 
   else
   {
    digitalWrite(Relay2, HIGH);
   }

   
    if(digitalRead(FLOAT_SENSOR) == HIGH)
  { 
    Serial.println("float up");
    RunPump();
  }
  else
{
  Serial.println("Float Down");
}
  
  

  delay(2000);
}


void TempSensor()
{
 
 
 digitalWrite(Relay2, LOW);
 }





void RunPump()
{
    
  
   int ML=analogRead(WETSnsr);
   Serial.print("MOISTURE LEVEL:");
  Serial.println(ML);
  if (ML > 350)
  {
    digitalWrite(Relay1, LOW);
    Serial.println("watering");
    delay(1000);
    digitalWrite(Relay1, HIGH);
    Serial.println("Pump off");
    delay(1000);
    
  }

}
