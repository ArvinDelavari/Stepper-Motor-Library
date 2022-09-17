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

#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>

void DriverType (String Driver);
void setupMotor(int stepPin, int dirPin, int enablePin, int MS1, int MS2, int MS3);
void motorDirection(int Direction);
void setMicrostep(int microStep);
void motorAction(double speed, double movement);

#endif