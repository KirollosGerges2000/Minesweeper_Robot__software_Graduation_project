/*  Minesweeper Graduation project 2023 
 *   Integrations 
 *   Mechatronic depertment "Level 5"
 *   Egyptian chinese university
 *   ECU
 *   Author:
 *   Eng/Kirollos Gerges
 */

#include <CytronMotorDriver.h>
char command;
int sensor =A0;
volatile int value =analogRead(sensor);
// Define logic control pins of motors
CytronMD M_R(PWM_DIR, 3, 2); 
CytronMD M_L(PWM_DIR, 5, 4);
   
   
void setup() 
{ // Code executes only once
Serial.begin(9600); // Start serial channel (bluetooth)
// configure the motor control pins to behave as an output
pinMode(sensor,INPUT);
}
void loop() { // Code executes repeatedly
if (Serial.available()) { // Checking if connection is available
Serial.write("Serial Connection Started...\n"); // Connection start notification
command = Serial.read(); // Read next command from the bluetooth connection
 Serial.print("Analog reading = ");
  Serial.print(value);   // the raw analog reading
}
Serial.print("Analog reading = ");
  Serial.print(value);   // the raw analog reading
switch (command) { // Compare the received command to a list of known commands and execute the first match
case 'f':
moveForward();
break;
case 'b':
moveBackward();
break;
case 'r':
moveRight();
break;
case 'l':
moveLeft();
break;
case 's':
stop();
break;
default: // No match from the list of known commands
Serial.write("Unknown Command \n");
break;
}
delay(200);
}
void moveForward()
{
 M_R.setSpeed(255);
  M_L.setSpeed(255);
  if (value >= 0  || value < 100  )
  {
    M_R.setSpeed(0);
  M_L.setSpeed(0);
   
  } 
}

void moveBackward() {
 M_R.setSpeed(-255);
  M_L.setSpeed(-255);
}
void moveRight() {
 M_R.setSpeed(-255);
  M_L.setSpeed(255);
}
void moveLeft() {
 M_R.setSpeed(255);
  M_L.setSpeed(-255);
}
void stop() {
 M_R.setSpeed(0);
  M_L.setSpeed(0);
}
