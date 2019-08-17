
// init pin
const int SENSOR_PIN = 2;

// init boud
const int SERIAL_BOUND = 9600;

// vibration level for trigger change
int MAX_VIBRATION_LEVEL = 4;

int vibrationLevel = 0;

void setup() {
  // begin serial port with 9600 boud
  Serial.begin(SERIAL_BOUND);

  // set pin mode
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  // When sensor is static means the circuit is closed and the read is HIGH,
  // so reset {vibrationLevel} and break the loop
  if (digitalRead(SENSOR_PIN) == HIGH) {
    vibrationLevel = 0;
    return;
  }
  
  // For each time the sensor is vibrated make an addition by one until reach {MAX_VIBRATION_LEVEL} and print.
  if (++vibrationLevel == MAX_VIBRATION_LEVEL)
      Serial.println("Vibration recognized");
  
  delay(10);
}
