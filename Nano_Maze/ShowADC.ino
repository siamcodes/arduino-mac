void ShowADC(){
  ReadADC();
  Serial.print((String)L1 + "\t" + (String)C + "\t" + (String)R1 + "\n");
  delay(100);
}
