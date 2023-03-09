void ShowSensor() {
  ReadSensor();
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);

  Serial.print("SoliSensor = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "SoilSensor = "
  Serial.println(val); // พิมพ์ค่าของตัวแปร val
  
  //delay(500);
}
