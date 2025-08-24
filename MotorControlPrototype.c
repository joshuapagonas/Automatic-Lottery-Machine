#include <Servo.h>
#define RESET_BUTTON_PIN 12
#define EN1_PIN_2 13
#define IN1_PIN_2 9
#define IN2_PIN_2 8 
#define TRIG_PIN 7
#define ECHO_PIN 6
#define EN1_PIN 5
#define IN1_PIN 4
#define IN2_PIN 3
#define START_BUTTON_PIN 2
Servo myservo;  // create servo object to control a servo
Servo emptyservo; // create servo object to control a servo
// twelve servo objects can be created on most boards

//L293D Out 1 Power Controlled By Enable 1 Pin 3 on L293D
//L293D Out 2 Ground Controlled By Enable 1 on L293D

uint8_t unlock_position = 180;    //Stores the servo motor's position
uint8_t lock_position = 0;
uint8_t balls_encountered = 0;
long duration, distance;
int start_button_state = 0;
int reset_button_state = 0;
float current_time = 0;

void setup() {
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
  Serial.begin(9600);
  Serial.println();

  pinMode(EN1_PIN_2,OUTPUT);
  pinMode(IN2_PIN_2,OUTPUT);
  pinMode(IN1_PIN_2,OUTPUT);

  pinMode(EN1_PIN,OUTPUT);
  pinMode(IN2_PIN,OUTPUT);
  pinMode(IN1_PIN,OUTPUT);

  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

  pinMode(START_BUTTON_PIN,INPUT);
  pinMode(RESET_BUTTON_PIN,INPUT);

  lock_door_hatch();
  emptyservo.attach(11);
  emptyservo.write(0); //If all else fails, change this value to 90
  delay(500);
}

void spin_agitator(){
  digitalWrite(IN1_PIN,LOW);
  digitalWrite(IN2_PIN,HIGH);
  analogWrite(EN1_PIN,255);
}

void stop_agitator(){
  analogWrite(EN1_PIN,0);
  digitalWrite(IN1_PIN, LOW);   // Set IN1 to LOW
  digitalWrite(IN2_PIN, LOW);   // Set IN2 to LOW
}

void spin_auger(){
  digitalWrite(IN1_PIN_2,LOW); // Set IN1_2 to LOW
  digitalWrite(IN2_PIN_2,HIGH); // Set IN2_2 to HIGH
  analogWrite(EN1_PIN_2,255);
}

void stop_auger(){
  analogWrite(EN1_PIN_2,0);
  digitalWrite(IN1_PIN_2, LOW);   // Set IN1 to LOW
  digitalWrite(IN2_PIN_2, LOW);   // Set IN2 to LOW
}

void unlock_door_hatch(){
  myservo.write(unlock_position);
  delay(1000);
}

void lock_door_hatch(){
  myservo.write(lock_position);
  delay(1000);
}

void release_balls(){
  emptyservo.write(unlock_position);
}

void relock_hatch(){
  emptyservo.write(lock_position);
}

void read_ultrasonic_sensor(){
  //Clears the TRIG_PIN, Starts the distance measurement, and sends out a pulse and get ready to listen for the echo
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,LOW);

  duration = pulseIn(ECHO_PIN,HIGH);
  distance = duration * 0.034 / 2; // Calculating the distance in centimeters

  if(distance > 0 && distance <= 9 && balls_encountered < 5){
    unlock_door_hatch();
    Serial.print(distance);
    Serial.println(" cm");
    balls_encountered++;
    Serial.print("Balls Encountered: ");
    Serial.println(balls_encountered);
    lock_door_hatch();
  }
}

void start_machine(){
  start_button_state = digitalRead(START_BUTTON_PIN);
  if(start_button_state == 1 && reset_button_state == 0){
    spin_agitator();
    while(balls_encountered != 5){
      read_ultrasonic_sensor();
      delay(500);
    }
    stop_agitator();
    start_button_state = 0;
  }
  reset_button_state = digitalRead(RESET_BUTTON_PIN);
  if(reset_button_state == 1 && start_button_state == 0){
    release_balls();
    current_time = millis();
    while(millis() - current_time <= 30000){
      spin_auger();
    }
    relock_hatch();
    stop_auger();
    reset_button_state = 0;
  }
}

void loop() {
  start_machine();
}
