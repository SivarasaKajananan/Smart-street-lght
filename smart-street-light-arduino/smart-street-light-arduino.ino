// Define sensor and LED pins
const int IR1 = 8; // Pin 8
const int IR2 = 9; // Pin 9
const int IR3 = 10; // Pin 10
const int IR4 = 11; // Pin 11

const int LED1 = 2; // Pin 2
const int LED2 = 3; // Pin 3
const int LED3 = 4; // Pin 4
const int LED4 = 5; // Pin 5
const int LED5 = 6; // Pin 6
const int LED6 = 7; // Pin 7
const int LED7 = 12; // Pin 12
const int LED8 = 13; // Pin 13

void setup() {
  // Initialize sensor pins as input
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);

  // Initialize LED pins as output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  // Turn off all LEDs at the start
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);
}

void loop() {
  // Read sensors
  bool ir1Detected = digitalRead(IR1);
  bool ir2Detected = digitalRead(IR2);
  bool ir3Detected = digitalRead(IR3);
  bool ir4Detected = digitalRead(IR4);

  // Check each sensor and update LEDs
  if (ir1Detected) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
  } else if (ir2Detected) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
  } else if (ir3Detected) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
  } else if (ir4Detected) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, HIGH);
    digitalWrite(LED8, HIGH);
  } else {
    // No motion detected, turn off all LEDs
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
  }
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
