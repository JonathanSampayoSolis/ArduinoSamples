
// init pin
const int IRS_PIN = 2;

// init boud
const int SERIAL_BOUND = 9600;

byte lastState;

void setup() {
  // begin serial port with 9600 boud
  Serial.begin(SERIAL_BOUND);
  
  // set pin mode
  pinMode(IRS_PIN, INPUT);

  // init state
  lastState = digitalRead(IRS_PIN);
}

void loop() {
  if (lastState != digitalRead(IRS_PIN))  
    Serial.println((lastState = digitalRead(IRS_PIN)) ? "It's free c;" : "There's an obstacle");
    
  delay(10);
}
