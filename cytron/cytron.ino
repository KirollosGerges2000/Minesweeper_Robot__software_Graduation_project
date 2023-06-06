#include <CytronMotorDriver.h>
int i;
CytronMD M_R(PWM_DIR, 3, 2); 
CytronMD M_L(PWM_DIR, 5, 4); 

void setup() {
  // put your setup code here, to run once:

}

void loop() {
 M_R.setSpeed(255);
  M_L.setSpeed(255);
}
