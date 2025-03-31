//#define enA 5  //Enable1 L298 Pin enA
#define in1 9  //Motor1  L298 Pin in1
#define in2 8  //Motor1  L298 Pin in1
#define in3 7  //Motor2  L298 Pin in1
#define in4 6  //Motor2  L298 Pin in1
#define enB 5  //Enable2 L298 Pin enB

int speedSet = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  // start serial communication at 9600bps

  //pinMode(enA, OUTPUT);  // declare as output for L298 Pin enA
  pinMode(in1, OUTPUT);  // declare as output for L298 Pin in1
  pinMode(in2, OUTPUT);  // declare as output for L298 Pin in2
  pinMode(in3, OUTPUT);  // declare as output for L298 Pin in3
  pinMode(in4, OUTPUT);  // declare as output for L298 Pin in4
  pinMode(enB, OUTPUT);  // declare as output for L298 Pin enB
  
  //analogWrite(enA, 110);  // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed
  analogWrite(enB, 110);  // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed
}

char Ins = '_';

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    Ins = Serial.read();
    if(Ins == '~' || Ins == '@' || Ins == '^' || Ins == '$' || Ins == 'X')
    {
      speedSet = Serial.parseInt();
    }

    if(Ins == '~')
    {
      moveForward();
    }
    else if (Ins == '@')
    {
      moveBackward();
    }
    else if (Ins == 'Q')
    {
      turnLeft();
    }
    else if (Ins == '$')
    {
      turnRight();
    }
    else if (Ins == 'X')
    {
      moveStop();
    }

    else
    {
      Serial.read();
    }
  }
}

void moveStop() {
  //Serial.println("Stopping!");
  digitalWrite(in1, LOW);  //Left Motor backword Pin
  digitalWrite(in2, LOW);  //Left Motor forword Pin
  digitalWrite(in3, LOW);  //Right Motor forword Pin
  digitalWrite(in4, LOW);  //Right Motor backword Pin
}

void moveForward() {
  digitalWrite(in1, LOW);   //Left Motor backword Pin
  digitalWrite(in2, HIGH);  //Left Motor forword Pin
  digitalWrite(in3, HIGH);  //Right Motor forword Pin
  digitalWrite(in4, LOW);   //Right Motor backword Pin
  analogWrite(enB, speedSet);
}

void moveBackward() {
  digitalWrite(in1, HIGH);  //Left Motor backword Pin
  digitalWrite(in2, LOW);   //Left Motor forword Pin
  digitalWrite(in3, LOW);   //Right Motor forword Pin
  digitalWrite(in4, HIGH);  //Right Motor backword Pin

  analogWrite(enB, speedSet);
}

void turnRight() {
  digitalWrite(in1, LOW);   //Left Motor backword Pin
  digitalWrite(in2, HIGH);  //Left Motor forword Pin
  digitalWrite(in3, LOW);   //Right Motor forword Pin
  digitalWrite(in4, HIGH);  //Right Motor backword Pin
  analogWrite(enB, speedSet);
}

void turnLeft() {
  digitalWrite(in1, HIGH);  //Left Motor backword Pin
  digitalWrite(in2, LOW);   //Left Motor forword Pin
  digitalWrite(in3, HIGH);  //Right Motor forword Pin
  digitalWrite(in4, LOW);   //Right Motor backword Pin
  
  analogWrite(enB, speedSet);
}

