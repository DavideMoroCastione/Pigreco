#include <LiquidCrystal.h>

#define buttonAvvia 1
#define buttonRecord 2
#define buttonA 7
#define buttonB 8
#define buttonC 9
#define buttonD 10
#define buttonE 13
int record;
int vite;
int caso;

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

void setup() {
  // put your setup code here, to run once:

  pinMode(buttonAvvia, INPUT);
  pinMode(buttonRecord, INPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(buttonC, INPUT);
  pinMode(buttonD, INPUT);
  pinMode(buttonE, INPUT);
  lcd.begin(16, 2);
  vite = 3;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  caso = random(1, 5);

  
}

void spawna(int bottone) {
  
}







