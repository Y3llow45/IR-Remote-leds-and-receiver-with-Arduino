#include <IRremote.h>

int receiver = 13;
int LED1 = 7;
int LED2 = 8;
int LED3 = 9;
int LED4 = 10;
int LED5 = 11;
IRrecv irrecv(receiver);
decode_results results;
String hexValue;
bool bools[] = {false, false, false, false, false};
bool on = false;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void allOff(int de) {
  digitalWrite(7, LOW);
  delay(de);
  digitalWrite(8, LOW);
  delay(de);
  digitalWrite(9, LOW);
  delay(de);
  digitalWrite(10, LOW);
  delay(de);
  digitalWrite(11, LOW);
}

void powerButtonRed() {
  for (int i = 0; i <= 4; i++) {
    if (bools[i] == true) {
      for (int i = 7; i <= 11; i++) {
        digitalWrite(i, LOW);
        for (int i = 0; i <= 4; i++) {
          bools[i] = false;
        }
      }
      return;
    } else {
      for (int i = 7; i <= 11; i++) {
        digitalWrite(i, HIGH);
        for (int i = 0; i <= 4; i++) {
          bools[i] = true;
        }
      }
      return;
    }
  }
}

void firstLed() {
  if (bools[0] == false) {
    digitalWrite(LED1, HIGH);
    bools[0] = true;
  } else {
    digitalWrite(LED1, LOW);
    bools[0] = false;
  }
}

void secondLed() {
  if (bools[1] == false) {
    digitalWrite(LED2, HIGH);
    bools[1] = true;
  } else {
    digitalWrite(LED2, LOW);
    bools[1] = false;
  }
}

void thirdLed() {
  if (bools[2] == false) {
    digitalWrite(LED3, HIGH);
    bools[2] = true;
  } else {
    digitalWrite(LED3, LOW);
    bools[2] = false;
  }
}

void fourthLed() {
  if (bools[3] == false) {
    digitalWrite(LED4, HIGH);
    bools[3] = true;
  } else {
    digitalWrite(LED4, LOW);
    bools[3] = false;
  }
}

void fifthLed() {
  if (bools[4] == false) {
    digitalWrite(LED5, HIGH);
    bools[4] = true;
  } else {
    digitalWrite(LED5, LOW);
    bools[4] = false;
  }
}

void bluePowerbutton() {
  if (bools[0] == true) {
    digitalWrite(LED1, LOW);
    bools[0] = false;
  } else {
    digitalWrite(LED1, HIGH);
    bools[0] = true;
  } if (bools[1] == true) {
    digitalWrite(LED2, LOW);
    bools[1] = false;
  } else {
    digitalWrite(LED2, HIGH);
    bools[1] = true;
  } if (bools[2] == true) {
    digitalWrite(LED3, LOW);
    bools[2] = false;
  } else {
    digitalWrite(LED3, HIGH);
    bools[2] = true;
  } if (bools[3] == true) {
    digitalWrite(LED4, LOW);
    bools[3] = false;
  } else {
    digitalWrite(LED4, HIGH);
    bools[3] = true;
  } if (bools[4] == true) {
    digitalWrite(LED5, LOW);
    bools[4] = false;
  } else {
    digitalWrite(LED5, HIGH);
    bools[4] = true;
  }
}

void partyMode() {
  for (int i = 7; i <= 11; i++) {
    digitalWrite(i, LOW);
    bools[0] == true;
    bools[1] == false;
    bools[2] == true;
    bools[3] == false;
    bools[4] == true;
  }
  for (int i = 7; i <= 11; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  for (int i = 11; i >= 7; i--) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  for (int i = 7; i <= 11; i++) {
    digitalWrite(i, HIGH);
    delay(100);
  }
  allOff(100);
  for (int i = 11; i >= 7; i--) {
    digitalWrite(i, HIGH);
    delay(100);
  }
  allOff(100);
  for (int i = 1; i <= 2; i++) {
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(9, HIGH);
    delay(100);
    digitalWrite(11, HIGH);
    delay(100);
    for (int b = 1; b <= 2; b++) {
      digitalWrite(7, LOW);
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);
      delay(100);
      digitalWrite(8, HIGH);
      digitalWrite(10, HIGH);
      delay(100);
      digitalWrite(7, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      delay(100);
      digitalWrite(8, LOW);
      digitalWrite(10, LOW);
      delay(100);
    }
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    hexValue = String(results.value, HEX);
    Serial.println(hexValue);
    if (hexValue == "ff02fd") {
      powerButtonRed();
    } else if (hexValue == "ff807f") {
      firstLed();
    } else if (hexValue == "ff40bf") {
      secondLed();
    } else if (hexValue == "ffc03f") {
      thirdLed();
    } else if (hexValue == "ff20df") {
      fourthLed();
    } else if (hexValue == "ffa05f") {
      fifthLed();
    } else if (hexValue == "20df10ef") {
      bluePowerbutton();
    } else if (hexValue == "ff926d") {
      partyMode();
    }
    delay(50);
    irrecv.resume();
  }
}
