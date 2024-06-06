/*
MIT License

Copyright (c) 2024 Martynezys

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9
#define LED1 8
#define LED2 7
#define LED3 6
#define LED4 5
#define LED5 4
#define LED6 A1
#define LED7 A2
#define LED8 A3

const int ledPins[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};
const int buttonPin1 = 2;  
const int buttonPin2 = 3; 
const int dipSwitchPin1 = A0; 
const int dipSwitchPin2 = A6; 
const int dipSwitchPin3 = A7;
int binaryCounter = 0; 
int bellPin = 12;

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494

const int colors[][3] = {
  {255, 0, 0},   // Red
  {255, 165, 0}, // Orange
  {255, 255, 0}, // Yellow
  {0, 255, 0},   // Green
  {0, 255, 255}, // Cyan
  {0, 0, 255},   // Blue
  {128, 0, 128}, // Purple
  {255, 0, 255}  // Pink
};



void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
 
  pinMode(bellPin, OUTPUT);

  pinMode(buttonPin1, INPUT_PULLUP); 
  pinMode(buttonPin2, INPUT_PULLUP); 


  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);

  digitalWrite(bellPin, HIGH);
}

void loop() {
  int switchState1 = analogRead(dipSwitchPin1); 
  int switchState2 = analogRead(dipSwitchPin2); 
  int switchState3 = analogRead(dipSwitchPin3);



  if (switchState1 < 500) { 
    ledoff();
  }

  if (switchState2 < 500) {
    tiger();
  }

  if (switchState3 < 500) {
    fadingRainbow();
  }
    if (digitalRead(buttonPin2) == LOW) {
    ledon();
    delay(200); 
  }


    if (digitalRead(buttonPin1) == LOW) {
    incrementBinary(); 
    delay(200); 
  }


  updateLEDs();
}

void incrementBinary() {
  binaryCounter++;
  binaryCounter %= 256; 
}

void updateLEDs() {
  for (int i = 0; i < 8; i++) {
    if (binaryCounter & (1 << i)) { 
      digitalWrite(ledPins[i], HIGH); 
    } else {
      digitalWrite(ledPins[i], LOW); 
    }
  }
}

void tiger() {
  tone(bellPin, 988, 250);
  delay(1000);
  tone(bellPin, 988, 250);
  delay(400);
  tone(bellPin, 880, 250);
  delay(400);
  tone(bellPin, 988, 250);
  delay(1000);
  
  tone(bellPin, 988, 250);
  delay(400);
  tone(bellPin, 880, 250);
  delay(400);
  tone(bellPin, 988, 250);
  delay(1000);
  
  tone(bellPin, 988, 250);
  delay(400);
  tone(bellPin, 880, 250);
  delay(400);
  tone(bellPin, 784, 1000);
  delay(1000);
  tone(bellPin, 880, 1000);
  delay(1000);
}

void playBuzzerTone() {
  tone(bellPin, 1000); 
  delay(500);            
  noTone(bellPin);   
}

void playSong() {
  int melody[] = {
    NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4, 
    NOTE_D4, NOTE_D4, NOTE_D4, 
    NOTE_E4, NOTE_G4, NOTE_G4, 
    NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4, 
    NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4
  };
  int noteDurations[] = {
    4, 4, 4, 4, 4, 4, 2, 
    4, 4, 2, 
    4, 4, 2, 
    4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 1 
  };


  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {

    int noteDuration = 250 / noteDurations[thisNote];
    tone(bellPin, melody[thisNote], noteDuration);
    delay(noteDuration * 1.30); 
    noTone(bellPin); 
  }
}


void blue() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(1000); 
}

void green() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000);
}

void red() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000); 
}

void ledoff() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000);
}

void ledon() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);
  delay(1000); 
}

void fadingRainbow() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);
  for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
    int nextColorIndex = (i + 1) % (sizeof(colors) / sizeof(colors[0])); 


    for (int j = 0; j <= 255; j += 5) {
      analogWrite(RED_PIN, colors[i][0] + (colors[nextColorIndex][0] - colors[i][0]) * j / 255);
      analogWrite(GREEN_PIN, colors[i][1] + (colors[nextColorIndex][1] - colors[i][1]) * j / 255);
      analogWrite(BLUE_PIN, colors[i][2] + (colors[nextColorIndex][2] - colors[i][2]) * j / 255);
      delay(15); 
    }
  }
}