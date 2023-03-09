void ReadADC() {
  IL = analogRead(A0);
  IC = analogRead(A1);
  IR = analogRead(A2);

  L = digitalRead(A3);
  R = digitalRead(A4);
 
}
