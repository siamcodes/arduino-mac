void ShowADC() {
  ReadADC();
  oled.clear(); //เคลียร์หน้าจอให้ว่าง
  oled.text(0, 0, " L = %d ", L); // Left Sensor
  oled.text(1, 0, " C = %d ", C); // Center Sensor
  oled.text(2, 0, " R = %d ", R); // Right Sensor
  oled.text(3, 0, " PulseML = %d ", PulseML); // motor_left
  oled.text(4, 0, " PulseMR = %d ", PulseMR); // motor_right
  oled.show();
}
