/*
NT1Ks Fox Box Keyer - 12/2012
http://www.nt1k.com
 
This program will key the radio and send an ID in CW at 700Hz
followed up by a 5 second tone to allow others to find the
transmitter.
*/
 
int const CWLED = 13; // LED to show CW Connect to PIN 13
int const TXLED = 12; // LED to show TX is active to PIN 12
int const CW = 11; // Hook up Microphone to PIN 11
int const TX = 9; // Hook TX up to PIN 9
int const SW = 7; // Momentary Pushbutton to PIN 7
 
int TONEHZ = 700; // Tone of the CW Signal 
int DAHLENGTH = 120; // Change for faster/slower CW
int BEEPLENGTH = 5000; // Length of soild tone in ms
int MSGSPACE = 60000; // Space Between Transmissions
 
int val= 0;
int old_val =0;
int state = 0;
 
 
char message[] = "DE NT1K FOX HUNT K"; //Message Beint Sent
 
// Following Makes the DAH tone
 
void dah() {
        digitalWrite(CWLED, HIGH); // Turns LED on
        tone(CW, TONEHZ); // Sending out tone at 700hz
        delay(DAHLENGTH);
        digitalWrite(CWLED, LOW); // Turns off LED
        noTone(CW); // Turns off Tone
 
}
 
// Following Makes the DIT tone
 
void dit() {
        digitalWrite(CWLED, HIGH);
        tone(CW, TONEHZ);
        delay(3*DAHLENGTH);
        digitalWrite(CWLED, LOW);
        noTone(CW);
        delay(DAHLENGTH)
}
 
// Following is the Space Between Letters
 
void letterBreak() {
        delay(2*DAHLENGTH)
}
 
// Following is the Space Between Words
 
void wordBreak() {
        delay(4*DAHLENGTH)
}
 
// Following replaces the each char with its morse code equiv
 
void send(char letter) {
  switch (letter) {
    case 'A':
    case 'a': dit(); dah(); break;
    case 'B':
    case 'b': dah(); dit(); dit(); dit(); break;
    case 'C':
    case 'c': dah(); dit(); dah(); dit(); break;
    case 'D':
    case 'd': dah(); dit(); dit(); break;
    case 'E':
    case 'e': dit(); break;
    case 'F':
    case 'f': dit(); dit(); dah(); dit(); break;
    case 'G':
    case 'g': dah(); dah(); dit(); break;
    case 'H':
    case 'h': dit(); dit(); dit(); dit(); break;
    case 'I':
    case 'i': dit(); dit(); break;
    case 'J':
    case 'j': dit(); dah(); dah(); dah(); break;
    case 'K':
    case 'k': dah(); dit(); dah(); break;
    case 'L':
    case 'l': dit(); dah(); dit(); dit(); break;
    case 'M':
    case 'm': dah(); dah(); break;
    case 'N':
    case 'n': dah(); dit(); break;
    case 'O':
    case 'o': dah(); dah(); dah(); break;
    case 'P':
    case 'p': dit(); dah(); dah(); dit(); break;
    case 'Q':
    case 'q': dah(); dah(); dit(); dah(); break;
    case 'R':
    case 'r': dit(); dah(); dit(); break;
    case 'S':
    case 's': dit(); dit(); dit(); break;
    case 'T':
    case 't': dah(); break;
    case 'U':
    case 'u': dit(); dit(); dah(); break;
    case 'V':
    case 'v': dit(); dit(); dit(); dah(); break;
    case 'W':
    case 'w': dit(); dah(); dah(); break;
    case 'X':
    case 'x': dah(); dit(); dit(); dah(); break;
    case 'Y':
    case 'y': dah(); dit(); dah(); dah(); break;
    case 'Z':
    case 'z': dah(); dah(); dit(); dit(); break;
    case '0': dah(); dah(); dah(); dah(); dah(); break;
    case '1': dit(); dah(); dah(); dah(); dah(); break;
    case '2': dit(); dit(); dah(); dah(); dah(); break;
    case '3': dit(); dit(); dit(); dah(); dah(); break;
    case '4': dit(); dit(); dit(); dit(); dah(); break;
    case '5': dit(); dit(); dit(); dit(); dit(); break;
    case '6': dah(); dit(); dit(); dit(); dit(); break;
    case '7': dah(); dah(); dit(); dit(); dit(); break;
    case '8': dah(); dah(); dah(); dit(); dit(); break;
    case '9': dah(); dah(); dah(); dah(); dit(); break;
    case '.': dit(); dah(); dit(); dah(); dit(); dah(); break;
    case ',': dah(); dah(); dit(); dit(); dah(); dah(); break;
    case '?': dit(); dit(); dah(); dah(); dit(); dit(); break;
    case '-': dah(); dit(); dit(); dit(); dit(); dah(); break;
    case '/': dah(); dit(); dit(); dah(); dit(); break;
    case '\'': dah(); dah(); dah(); dit(); dit(); dit(); break;
    case ' ': wordBreak(); break;
  }
  letterBreak();
}
 
// Following is the setup for the loop
 
void setup() {
        pinMode (LED, OUTPUT); // Defines that the LED is an OUTPUT
        pinMode (SW, INPUT); // Defines that the Switch is an INPUT
}
 
// Following is the acutal program using the above information
 
void loop(){
       
 
        val = digitalRead(SW); // Looking for information from the switch
 
        if ((val == HIGH) && old_val == LOW)) {
                state = 1 - state;
                delay (1000);
        }
 
        old_val = val;
 
        if ((val == LOW) && old_val == HIGH)) {
                state = 1 + state;
        }
 
        // When the button is pushed, it will perform the following
 
        if (state == 1) {
 
                digitalWrite(TX, HIGH); // Turns on transmitter PTT
                digitalWrite(TXLED, HIGH); // Turns on the TX LED
 
                for (byte j=0; j<sizeof(message);) {
                        send(message[j]);
                }
 
                delay(4*DAHLENGTH);
                tone(CW, TONEHZ, BEEPLENGTH); // Sends Solid Tone Then Shuts Tone OFF 
                digitalWrite(TX, LOW);  // Turns off TX
                digitalWrite(TXLED, LOW);
                delay(MSGSPACE); // Wait time untill repeat
 
 
        } else {
         digitalWrite(CWLED, LOW)
         digtialWrite(TX, LOW)
         digitalWrite(TXLED, LOW)
        }
}