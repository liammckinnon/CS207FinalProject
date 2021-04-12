int Relay1 = 2;
int Snsr = A0; 
float value1 = 0;
#define FLOAT_SENSOR 3

void setup() {
  Serial.begin(9600);
  pinMode(Relay1, OUTPUT);
  pinMode(Snsr, INPUT);
  pinMode(FLOAT_SENSOR, INPUT_PULLUP);
  
  digitalWrite(Relay1, HIGH);
  delay(500);
}
void loop() {
  if(digitalRead(FLOAT_SENSOR) == HIGH)
  
  {
  Serial.println("float up");
  
  Serial.print("MOISTURE LEVEL:");
int ML = analogRead(Snsr);
  Serial.println(ML);
  if(ML>400)
  {
      digitalWrite(Relay1, LOW);
      Serial.println("watering");
      delay(1000);
      digitalWrite(Relay1, HIGH);
  }
  else
  {
    digitalWrite(Relay1, HIGH);
    }
    Serial.println();
  delay(1000);
  }
  
else
  {
  Serial.println("Float down");
  delay (1000);
  }
  
}
