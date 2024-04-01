#include "Stepper.h"

Stepper stepper(11, 9, 10, 8);

void setup() {

}

void loop() {
  stepper.runRight(65530);

}
