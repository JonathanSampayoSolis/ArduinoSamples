
// init pin 0 | 2
const int GPIO2_PIN = 2;

// init boud
const int SERIAL_BOUND = 9600;

void setup() {
  // begin serial port with 9600 boud
  Serial.begin(SERIAL_BOUND);
  
  // set pin mode
  pinMode(GPIO2_PIN, OUTPUT);
}

void loop() {
  // Check for entries into Serial.
  if (Serial.available() > 0) {
    // Fetch value
    String command = Serial.readStringUntil('\n');
    Serial.println("Input: " + command);

    // Compare command
    if (command.equals("a")) {
      // Turn on port
      Serial.println("GPIO2 ON...");
      digitalWrite(GPIO2_PIN, HIGH);
    } else {
      // Turn off port
      Serial.println("GPIO2 OFF...");
      digitalWrite(GPIO2_PIN, LOW);
    }
  }
  
}
