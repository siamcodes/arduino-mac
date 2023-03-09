void ReadSensor() {
  delay(dht.getMinimumSamplingPeriod());
  humidity = dht.getHumidity(); // ดึงค่าความชื้น
  temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
  val = analogRead(Soil);  //อ่านค่าสัญญาณ analog ขา9 ที่ต่อกับ Soil Moisture Sensor
}
