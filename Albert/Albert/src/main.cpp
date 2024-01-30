#include <Arduino.h>
/*
// This is very similar to Example 3 - Receive with start- and end-markers
//    in Serial Input Basics   http://forum.arduino.cc/index.php?topic=396450.0

const byte numChars = 64;
char receivedChars[numChars];

boolean newData = false;

byte ledPin = 13;   // the onboard LED

//===============

void setup() {
    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
    digitalWrite(ledPin, HIGH);

    Serial.println("<Arduino is ready>");
}

//===============

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

//===============

void replyToPython() {
    if (newData == true) {
        Serial.print("<This just in ... ");
        Serial.print(receivedChars);
        Serial.print("   ");
        Serial.print(millis());
        Serial.print('>');
            // change the state of the LED everytime a reply is sent
        digitalWrite(ledPin, ! digitalRead(ledPin));
        newData = false;
    }
}
//===============

void loop() {
    recvWithStartEndMarkers();
    replyToPython();
}

//===============*/

/*#define LED_pin 2
#define LED_errorPin 3

void setup() {
  Serial.begin(9600) ;
      pinMode(LED_pin, OUTPUT) ;
      pinMode(LED_errorPin, OUTPUT) ;
}

void loop() {
  if (Serial.available() > 0){
          String msg = Serial.readString() ;

          if (msg == "ON"){
              digitalWrite(LED_pin,HIGH) ;
          }else if (msg == "OFF"){
              digitalWrite(LED_pin,LOW) ;
          }else{
              digitalWrite(LED_errorPin, HIGH);
              delay(100);
              digitalWrite(LED_errorPin, LOW);
          }

      }
}*/

const int ledPin = 13; // Exemple : Connectez la LED au pin 13

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

void loop() {
    if (Serial.available() > 0) {
        char command = Serial.read();
        if (command == '1') {
            digitalWrite(ledPin, HIGH); // Allumer la LED
        } else if (command == '0') {
            digitalWrite(ledPin, LOW); // Éteindre la LED
        }
    }
}
