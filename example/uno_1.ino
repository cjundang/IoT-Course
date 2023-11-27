void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if (inChar == '0') {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
