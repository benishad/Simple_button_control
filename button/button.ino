#define FSR A0

int ledA = 2;
int ledB = 3;
int ledC = 4;
int ledD = 5;

int buttonA = 8;
int buttonB = 9;
int buttonC = 10;
int buttonD = 11;

boolean current_buttonA = LOW;
boolean current_buttonB = LOW;
boolean current_buttonC = LOW;
boolean current_buttonD = LOW;

boolean last_buttonA = LOW;
boolean last_buttonB = LOW;
boolean last_buttonC = LOW;
boolean last_buttonD = LOW;

boolean led_onA = false;
boolean led_onB = false;
boolean led_onC = false;
boolean led_onD = false;

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(buttonC, INPUT_PULLUP);
  pinMode(buttonD, INPUT_PULLUP);
}

void loop() {
  int sensorValue = analogRead(FSR);

  if (sensorValue > 200) {
    current_buttonA = digitalRead(buttonA);
    current_buttonB = digitalRead(buttonB);
    current_buttonC = digitalRead(buttonC);
    current_buttonD = digitalRead(buttonD);

    if (last_buttonA == LOW && current_buttonA == LOW) {
      led_onA = ! led_onA;
    }
    last_buttonA = current_buttonA;

    digitalWrite(ledA, led_onA);


    if (last_buttonB == LOW && current_buttonB == LOW) {
      led_onB = ! led_onB;
    }
    last_buttonB = current_buttonB;

    digitalWrite(ledB, led_onB);


    if (last_buttonC == LOW && current_buttonC == LOW) {
      led_onC = ! led_onC;
    }
    last_buttonC = current_buttonC;

    digitalWrite(ledC, led_onC);


    if (last_buttonD == LOW && current_buttonD == LOW) {
      led_onD = ! led_onD;
    }
    last_buttonD = current_buttonD;

    digitalWrite(ledD, led_onD);
    delay(300);
  }
  else {
    current_buttonA = LOW;
    current_buttonB = LOW;
    current_buttonC = LOW;
    current_buttonD = LOW;
    last_buttonA = LOW;
    last_buttonB = LOW;
    last_buttonC = LOW;
    last_buttonD = LOW;
    led_onA = false;
    led_onB = false;
    led_onC = false;
    led_onD = false;
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
  }
}
