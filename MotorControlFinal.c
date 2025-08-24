#include <Servo.h>

#define TRIG_PIN 13
#define ECHO_PIN 12
#define SERVO_PIN 3
#define BUTTON_PIN 2
#define IN1 5
#define IN2 6
#define ENA 9 //Agitator
#define IN3 8
#define IN4 7
#define ENA2 11 //Auger
#define BUTTON_RESET_PIN 4
#define SERVO_DOOR_PIN 10

Servo gateServo;
int ballCount = 0;
bool machineRunning = false;
unsigned long lastDetectTime = 0;
bool lastBallSettled = false;
Servo doorServo;
bool resetting = false;
unsigned long resetStartTime = 0;


#define DOOR_OPEN_POS 0
#define DOOR_CLOSED_POS 90
#define RESET_RUN_TIME 15000  // 5 seconds
#define BALL_DETECT_DISTANCE 10  // cm, distance considered as ball present
#define BALL_SETTLE_TIME 3000    // ms, time to confirm 5th ball has settled
#define SERVO_OPEN_POS 0
#define SERVO_CLOSED_POS 180


void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA2, OUTPUT);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  gateServo.attach(SERVO_PIN);
  gateServo.write(SERVO_CLOSED_POS);

  pinMode(BUTTON_RESET_PIN, INPUT_PULLUP);

  doorServo.attach(SERVO_DOOR_PIN);
  doorServo.write(90);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW && !machineRunning) {
    startMachine();
  }

  if (machineRunning && ballCount < 3) {
    releaseBallIfNeeded();
  }

  if (ballCount == 3 && !lastBallSettled) {
    checkBallSettle();
  }

  if (digitalRead(BUTTON_RESET_PIN) == LOW && !resetting) {
    startReset();
  }

  if (resetting) {
    updateResetProcess();
  }
}

void startMachine() {
  Serial.println("Machine started!");
  machineRunning = true;
  ballCount = 0;
  lastBallSettled = false;
  analogWrite(ENA, 250);
    // Open servo gate to drop a ball
    gateServo.write(SERVO_OPEN_POS);
    delay(2000); // Time to open
    gateServo.write(SERVO_CLOSED_POS);
    delay(2000); // Time to close
}

void releaseBallIfNeeded() {
  if ((millis() % 2000 == 0)) {
    ballCount++;
    Serial.print("Ball Detected: ");
    Serial.println(ballCount);

    // Open servo gate to drop a ball
    gateServo.write(SERVO_OPEN_POS);
    delay(1000); // Time to open
    gateServo.write(SERVO_CLOSED_POS);
    delay(1000); // Time to close

    // Wait for ball to roll down
    delay(1000);
  }
}

bool detectBall() {
  long duration;
  int distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print(distance);

  if (distance > 0 && distance < BALL_DETECT_DISTANCE) {
    delay(100); // debounce delay
    return true;
  }

  return false;
}

void checkBallSettle() {
  int distance = getDistance();
  Serial.println(distance);
  if (distance > 0 && distance < BALL_DETECT_DISTANCE) {
    if (lastDetectTime == 0) {
      lastDetectTime = millis();
    } else if (millis() - lastDetectTime >= BALL_SETTLE_TIME) {
      stopMachine();
    }
  } else {
    lastDetectTime = 0;
  }
}

int getDistance() {
  long duration;
  int distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  delay(50);
  return distance;
}

void stopMachine() {
  analogWrite(ENA, 0);
  machineRunning = false;
  lastBallSettled = true;
  Serial.println("Machine stopped. 5 balls in place.");
}

void startReset() {
  Serial.println("Reset started!");
  resetting = true;
  resetStartTime = millis();

  doorServo.write(DOOR_OPEN_POS);             // Open the door
  analogWrite(ENA2, 250);       // Turn on auger motor
}

void updateResetProcess() {
  if (millis() - resetStartTime >= RESET_RUN_TIME) {
    doorServo.write(DOOR_CLOSED_POS);         // Close the door
    analogWrite(ENA2, 0);      // Stop motor
    resetting = false;
    Serial.println("Reset complete!");
  }
}
