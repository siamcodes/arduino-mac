void EncoderML() {
  int ML = digitalRead(Encoder_output_B2); // motor_right
  if (ML > 0) {
    PulseML++;
  }
  else {
    PulseML--;
  }
}


void EncoderMR() {
  int MR = digitalRead(Encoder_output_B1); // motor_right
  if (MR > 0) {
    PulseMR--;
  }
  else {
    PulseMR++;
  }
}

void ShowEncode() {
  oled.clear();
  oled.text(3, 0, "PulseML = %d", PulseML);
  oled.text(4, 0, "PulseMR = %d", PulseMR);
  oled.show();
}
