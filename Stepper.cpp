//
// Created by systemdev on 31.03.24.
//

#include "Stepper.h"
#include "Arduino.h"

Stepper::Stepper(short aPlus, short aMinus, short bPlus, short bMinus) {
      this->aPlus = aPlus;
      this->aMinus = aMinus;
      this->bPlus = bPlus;
      this->bMinus = bMinus;

      pinMode(aPlus, OUTPUT);
      pinMode(aMinus, OUTPUT);
      pinMode(bPlus, OUTPUT);
      pinMode(bMinus, OUTPUT);
}

void Stepper::runRight(short speed) {
  short time = 65535 - speed;

  digitalWrite(aPlus, 1);
  digitalWrite(bPlus, 0);
  digitalWrite(aMinus, 0);
  digitalWrite(bMinus, 0);
  delay(time);

  digitalWrite(aPlus, 0);
  digitalWrite(bPlus, 1);
  digitalWrite(aMinus, 0);
  digitalWrite(bMinus, 0);
  delay(time);

  digitalWrite(aPlus, 0);
  digitalWrite(bPlus, 0);
  digitalWrite(aMinus, 1);
  digitalWrite(bMinus, 0);
  delay(time);

  digitalWrite(aPlus, 0);
  digitalWrite(bPlus, 0);
  digitalWrite(aMinus, 0);
  digitalWrite(bMinus, 1);
  delay(time);
}

void Stepper::runLeft(short speed) {
  short time = 65535 - speed;

  digitalWrite(aPlus, 0);
  digitalWrite(bPlus, 0);
  digitalWrite(aMinus, 0);
  digitalWrite(bMinus, 1);
  delay(time);

  digitalWrite(aPlus, 0);
  digitalWrite(bPlus, 0);
  digitalWrite(aMinus, 1);
  digitalWrite(bMinus, 0);
  delay(time);

  digitalWrite(aPlus, 0);
  digitalWrite(bPlus, 1);
  digitalWrite(aMinus, 0);
  digitalWrite(bMinus, 0);
  delay(time);

  digitalWrite(aPlus, 1);
  digitalWrite(bPlus, 0);
  digitalWrite(aMinus, 0);
  digitalWrite(bMinus, 0);
  delay(time);
}

void Stepper::stop() {
  digitalWrite(aPlus, 0);
  digitalWrite(bPlus, 0);
  digitalWrite(aMinus, 0);
  digitalWrite(bMinus, 0);
}

void Stepper::enterUnsafe() { unsafeMode = true; }
void Stepper::exitUnsafe() { unsafeMode = false; }