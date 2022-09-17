/*
  STEPPER MOTOR LIBRARY
  WRITTEN FOR A4988/LV8729/TB6600 AND OTHER SIMILAR DIVERS WICH CAN OPERATE FROM 1 to 128 MICROSTEPS
  YOU CAN CHANGE PARAMTERS AS YOU USE IN YOUR OWN SETUP (MCU PINS)

  ATTENTION : YOU CAN CHANGE CALIBRATION PARAMETERS IN CODE MANNUALY ACCORDING TO YOUR USAGE AND SETUP

  INPUSTS : SPEED - MOVEMENT (UNIT : mm/s - mm)
  SERIAL DEBUGGER IS USED FOR MONITORING ACTIONS. SO INITIALIZE SERIAL MONITOR BEFORE STARTING
  DATE : 9/17/2022
  
  BY : ARVIN DELAVARI - IRAN UNIVERSITY OF SCIENCE AND TECHNOLOGY
       EMBEDDED SOFTWARE PROGRAMMER @ SAMA INSTRUMENTS - TEHRAN,IRAN
       ELECTRONICS R&D SPECIALIST   @ MURANI (TFP ™)   - TEHRAN,IRAN
  E-MAIL   : arvin7807@gmail.com
  LinkedIn : arvin-delavari
  Instagram: @arvin_delavari
*/

#include "Motor.h"
#include "Arduino.h"

#define FORWARD 1
#define BACKWARD 0
#define releaseMotor HIGH
#define SELECTED HIGH

String Driver;

int microStep;

int A4988  = 0;
int TB6600 = 0;
int LV8729 = 0; 

int Saved_dirPin;
int Saved_stepPin;
int Saved_enablePin;
int Saved_MS1;
int Saved_MS2;
int Saved_MS3;


void DriverType (String Driver)
{
  if (Driver =="A4988")
    A4988  = HIGH;
    TB6600 = LOW;
    LV8729 = LOW;
  if (Driver =="TB6600")
    TB6600 = HIGH;
    A4988  = LOW;
    TB6600 = LOW;
  if (Driver =="LV8729")
    LV8729 = HIGH;
    A4988  = LOW;
    TB6600 = LOW;
}

void setupMotor (int stepPin, int dirPin, int enablePin, int MS1, int MS2, int MS3)
{
  Serial.begin(9600);
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin,OUTPUT);
  pinMode(Saved_MS1,OUTPUT);
  pinMode(MS2,OUTPUT);
  pinMode(MS3,OUTPUT);
  Saved_dirPin    = dirPin;
  Saved_stepPin   = stepPin;
  Saved_enablePin = enablePin;
  Saved_MS1 = Saved_MS1;
  Saved_MS2 = MS2;
  Saved_MS3 = MS3;
}

void motorDirection(int Direction)
{
  digitalWrite(Saved_dirPin , Direction);
}

void setMicrostep(int microStep) // 1 - 2 - 4 - 8 - 16 - 32 ... (64 - 128 for LV8729)
{
  if (A4988 == SELECTED || TB6600 == SELECTED)
  {
    if (microStep == 1)
    {
      digitalWrite(Saved_MS1 , !HIGH);
      digitalWrite(Saved_MS2 , !HIGH);
      digitalWrite(Saved_MS3 , !HIGH);
      Serial.println("Move Mode: Full-Step");
    }
      // 1/2 step
    if (microStep == 2)
    {
      digitalWrite(Saved_MS1 , HIGH);
      digitalWrite(Saved_MS2 , !HIGH);
      digitalWrite(Saved_MS3 , !HIGH);
      Serial.println("Move Mode: 1/2-Step");
    }
      //----------------------------
      // 1/4 step
    if (microStep == 4)
    {
      digitalWrite(Saved_MS1 , !HIGH);
      digitalWrite(Saved_MS2 , HIGH);
      digitalWrite(Saved_MS3 , !HIGH);
      Serial.println("Move Mode: 1/4-Step");
    }
      //----------------------------
      // 1/8 step
    if (microStep == 8)
    {
      digitalWrite(Saved_MS1 , HIGH);
      digitalWrite(Saved_MS2 , HIGH);
      digitalWrite(Saved_MS3 , !HIGH);
      Serial.println("Move Mode: 1/8-Step");
    }
      //----------------------------
      // 1/16 step
    if (microStep == 16)
    {
      digitalWrite(Saved_MS1 , !HIGH);
      digitalWrite(Saved_MS2 , !HIGH);
      digitalWrite(Saved_MS3 , HIGH);
      Serial.println("Move Mode: 1/16-Step");
    }
      //----------------------------
      // 1/32 step
    if (microStep == 32)
    {
      digitalWrite(Saved_MS1 , HIGH);
      digitalWrite(Saved_MS2 , HIGH);
      digitalWrite(Saved_MS3 , HIGH);
      Serial.println("Move Mode: 1/32-Step");
    }
  } 
  if (LV8729 == SELECTED)
  {
    if (microStep == 1)
    {
      digitalWrite(Saved_MS1 , !HIGH);
      digitalWrite(Saved_MS2 , !HIGH);
      digitalWrite(Saved_MS3 , !HIGH);
      Serial.println("Move Mode: Full-Step");
    }
      // 1/2 step
    if (microStep == 2)
    {
      digitalWrite(Saved_MS1 , HIGH);
      digitalWrite(Saved_MS2 , !HIGH);
      digitalWrite(Saved_MS3 , !HIGH);
      Serial.println("Move Mode: 1/2-Step");
    }
      //----------------------------
      // 1/4 step
    if (microStep == 4)
    {
      digitalWrite(Saved_MS1 , !HIGH);
      digitalWrite(Saved_MS2 , HIGH);
      digitalWrite(Saved_MS3 , !HIGH);
      Serial.println("Move Mode: 1/4-Step");
    }
      //----------------------------
      // 1/8 step
    if (microStep == 8)
    {
      digitalWrite(Saved_MS1 , HIGH);
      digitalWrite(Saved_MS2 , HIGH);
      digitalWrite(Saved_MS3 , !HIGH);
      Serial.println("Move Mode: 1/8-Step");
    }
      //----------------------------
      // 1/16 step
    if (microStep == 16)
    {
      digitalWrite(Saved_MS1 , !HIGH);
      digitalWrite(Saved_MS2 , !HIGH);
      digitalWrite(Saved_MS3 , HIGH);
      Serial.println("Move Mode: 1/16-Step");
    }
      //----------------------------
      // 1/32 step
    if (microStep == 32)
    {
      digitalWrite(Saved_MS1 , HIGH);
      digitalWrite(Saved_MS2 , !HIGH);
      digitalWrite(Saved_MS3 , HIGH);
      Serial.println("Move Mode: 1/32-Step");
    }
      //----------------------------
      // 1/64 step
    if (microStep == 64)
    {
      digitalWrite(Saved_MS1 , !HIGH);
      digitalWrite(Saved_MS2 , HIGH);
      digitalWrite(Saved_MS3 , HIGH);
      Serial.println("Move Mode: 1/64-Step");
    }
      //----------------------------
      // 1/128 step
    if (microStep == 128)
    {
      digitalWrite(Saved_MS1 , HIGH);
      digitalWrite(Saved_MS2 , HIGH);
      digitalWrite(Saved_MS3 , HIGH);
      Serial.println("Move Mode: 1/128-Step");
    }
      //-------------------------------------
  }
}

void motorAction(double speed, double movement) // speed unit : (mm/s) ... movement unit : (mm)
{
  if (A4988 == SELECTED || TB6600 == SELECTED)
  {
    if (speed > (float)8.0)
    {
      int microStep = 1;
      setMicrostep(1);
    }
    else if (speed <= (float)8.0 && speed > (float)6.0)
    {
      int microStep = 2;
      setMicrostep(2);
    }
    else if (speed <= (float)6.0 && speed > (float)2.0)
    {
      int microStep = 4;
      setMicrostep(4);
    }
    else if (speed <= (float)2.0 && speed > (float)0.75)
    {
      int microStep = 8;
      setMicrostep(8);
    }
    else if (speed <= (float)0.75)
    {
      int microStep = 32;
      setMicrostep(32);
    }
    unsigned long  microDelay = ((10.0 / microStep) / speed);
    unsigned long int Steps = 50 * microStep * movement;
    if (Steps < 1)
      Steps = 1;
    digitalWrite(Saved_enablePin, LOW);
    unsigned long timeBegin = millis();
    for (unsigned long i = 0; i <= Steps ; i++)
    {
      digitalWrite(Saved_stepPin, LOW);
      delayMicroseconds(microDelay);
      digitalWrite(Saved_stepPin, HIGH);
      delayMicroseconds(microDelay);
    }
    unsigned long timeEnd = millis();
    unsigned long duration = timeEnd - timeBegin;
    digitalWrite(Saved_enablePin , HIGH);
    Serial.print("Motor Run Time: ");
    Serial.print(duration / 1000.0);
    Serial.println(" s");
    Serial.println("Task Finished");
  
  }


  if (LV8729 == SELECTED)
  {
    double landa = (0.0008 * speed + 0.000006)/4;
    int microStep = 8;
    if ((1.0/ landa) <= 4000)
        microStep = 8; // STEP = 1/8
    else if (((1.0/landa) > 4000) and ((1.0/landa) <= 32000))
        microStep = 32; // STEP = 1/32
    else if ((1.0/landa) >32000)
        microStep = 128; // STEP = 1/128
    setMicrostep(microStep);

    int delayTime = 100;
    if (microStep == 8)
        delayTime = int ((1.0/landa) / (8.0));
    if (microStep == 32)
        delayTime = int ((1.0/landa) / (32.0));
    if (microStep == 128)
        delayTime = int ((1.0/landa) / (128.0));

    Serial.print("delayTime Calculate data :");
    Serial.println(delayTime);

    unsigned long int Time  = movement/speed;
    unsigned long int STEPS = ((Time * 1e6)  / (2 * delayTime));

    Serial.print("step specifier : ");
    Serial.println(STEPS);

    digitalWrite(Saved_enablePin, LOW);
    unsigned long timeBegin = millis();
    for (long int i = 0; i < STEPS ; i++) 
    {
      digitalWrite(Saved_stepPin , HIGH);
      delayMicroseconds (delayTime);
      digitalWrite(Saved_stepPin , LOW);
      delayMicroseconds (delayTime);
    } 
    unsigned long timeEnd = millis();
    unsigned long duration = timeEnd - timeBegin;
    digitalWrite(Saved_enablePin , HIGH);
    Serial.print("Motor Run Time: ");
    Serial.print(duration / 1000.0);
    Serial.println(" s");
    Serial.println("Task Finished");
  }
}