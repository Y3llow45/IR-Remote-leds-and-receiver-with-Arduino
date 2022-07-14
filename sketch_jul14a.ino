#include <IRremote.h>
int receiver = 13;
IRrecv irrecv(receiver);
decode_results results;
int LED1 = 7;
int LED2 = 8;
int LED3 = 9;
int LED4 = 10;
int LED5 = 11;
String hexValue;
bool bools[] = {false, false, false, false, false};
bool on = false;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void powerButtonRed() {

}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    hexValue = String(results.value, HEX);
    Serial.println(hexValue);
    if (hexValue == "ff02fd") {
      if (on == false) {
        for (int i = 7; i <= 11; i++) {
          digitalWrite(i, HIGH);
          on = true;
          for (int i = 0; i <= 4; i++) {
            bools[i] = true;
          }
        }
      } else {
        for (int i = 7; i <= 11; i++) {
          digitalWrite(i, LOW);
          on = false;
          for (int i = 0; i <= 4; i++) {
            bools[i] = false;
          }
        }
      }
    } else if (hexValue == "ff807f") {
      if (bools[0] == false) {
        digitalWrite(LED1, HIGH);
        bools[0] = true;
      } else {
        digitalWrite(LED1, LOW);
        bools[0] = false;
      }
    } else if (hexValue == "ff40bf") {
      if (bools[1] == false) {
        digitalWrite(LED2, HIGH);
        bools[1] = true;
      } else {
        digitalWrite(LED2, LOW);
        bools[1] = false;
      }
    } else if (hexValue == "ffc03f") {
      if (bools[2] == false) {
        digitalWrite(LED3, HIGH);
        bools[2] = true;
      } else {
        digitalWrite(LED3, LOW);
        bools[2] = false;
      }
    } else if (hexValue == "ff20df") {
      if (bools[3] == false) {
        digitalWrite(LED4, HIGH);
        bools[3] = true;
      } else {
        digitalWrite(LED4, LOW);
        bools[3] = false;
      }
    } else if (hexValue == "ffa05f") {
      if (bools[4] == false) {
        digitalWrite(LED5, HIGH);
        bools[4] = true;
      } else {
        digitalWrite(LED5, LOW);
        bools[4] = false;
      }
    } else if (hexValue == "20df10ef") {
      if (bools[0] == true) {
        digitalWrite(LED1, LOW);
        bools[0] == false;
      } else {
        digitalWrite(LED1, HIGH);
        bools[0] == true;
      } if (bools[1] == true) {
        digitalWrite(LED2, LOW);
        bools[1] == false;
      } else {
        digitalWrite(LED2, HIGH);
        bools[1] == true;
      } if (bools[2] == true) {
        digitalWrite(LED3, LOW);
        bools[2] == false;
      } else {
        digitalWrite(LED3, HIGH);
        bools[2] == true;
      } if (bools[3] == true) {
        digitalWrite(LED4, LOW);
        bools[3] == false;
      } else {
        digitalWrite(LED4, HIGH);
        bools[3] == true;
      } if (bools[4] == true) {
        digitalWrite(LED5, LOW);
        bools[4] == false;
      } else {
        digitalWrite(LED5, HIGH);
        bools[4] == true;
      }
    }
    delay(50);
    irrecv.resume();
  }
}
