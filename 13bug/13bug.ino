void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(13);
  delay(1000);
}
