
const int analogInPin = A0;
int sensorValue = 0; 
float voltage, degreeC, degreeF ;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  voltage = sensorValue * 3.3 / 1023 * 1000;     // mv from LM35 

  Serial.print("voltage (mv) : "); Serial.println(voltage);

  degreeC = voltage / 10;
  Serial.print("Temp (C) : "); Serial.print(degreeC);

//  if (degreeC > 50 ) {
//      digitalWrite(devicePin, LOW);
//    }


  degreeF = degreeC * (9.0/5.0) + 32.0;
  Serial.print(" \tTemp (F) : "); Serial.println(degreeF);

  delay(1000);
}
