#define MOTOR_CH_A 12
#define BRAKE_CH_A 9
#define SPEED_CH_A 3

#define MOTOR_CH_B 13
#define BRAKE_CH_B 8
#define SPEED_CH_B 11

#define HI_SPEED 150
#define LO_SPEED 0
#define ME_SPEED 75

int IRPin = 2;
int proximity = 0;

void setup() {
  
  Serial.begin(9600);
  //Setup Channel A in the Arduino Motor Shield
  pinMode(MOTOR_CH_A, OUTPUT); //Initiates Motor Channel A pin
  pinMode(BRAKE_CH_A, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B in the Arduino Motor Shield
  pinMode(MOTOR_CH_B, OUTPUT); //Initiates Motor Channel A pin
  pinMode(BRAKE_CH_B, OUTPUT);  //Initiates Brake Channel A pin
 
}

void loop() {
  // detect the proximity with an obstacle
  proximity = digitalRead(IRPin);
  if (proximity == HIGH)
  {
    digitalWrite(MOTOR_CH_A, LOW); //Establishes forward direction of Channel A
    digitalWrite(BRAKE_CH_A, LOW);   //RELEASE the Brake for Channel A
    analogWrite(3, 255);   //Spins the motor on Channel B at full speed
   
    digitalWrite(MOTOR_CH_B, LOW); //Establishes forward direction of Channel B
    digitalWrite(BRAKE_CH_B, LOW);   //RELEASE the Brake for Channel B
    analogWrite(11, 255);   //Spins the motor on Channel B at full speed
    }

   else{
    digitalWrite(BRAKE_CH_A, HIGH);
    digitalWrite(BRAKE_CH_B, HIGH);
    }
