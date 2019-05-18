#include <LiquidCrystal.h>

#define buttonAvvia 1
#define buttonRecord 2
#define buttonA 7
#define buttonB 8
#define buttonC 9
#define buttonD 10
#define buttonE 13
int vite;
int caso;
bool fine;
int record;
int partite;
int record2;
bool finito;
int t1;
int t2;

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
  vite = 5;
  fine = false;
  record = 0;
  partite = 0;
  record2 = 0;
  finito = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(fine == false) {
    if(digitalRead(buttonAvvia) == LOW){}
    else
      if(digitalRead(buttonAvvia) == HIGH){
        caso = random(1, 6);
        fine = true;
        partite++;
      }
  }
  lcd.setCursor(0, 0);
  lcd.print("Vite:" + vite);
  while(vite > 0){
     if(caso == 1){
         piGreco(1, buttonA, record, "π", vite, buttonB, buttonC, buttonD, buttonE);
     }
     else if(caso == 2){
         piGreco(5, buttonB, record, "π", vite, buttonA, buttonC, buttonD, buttonE);
     }
     else if(caso == 3){
         piGreco(9, buttonC, record, "π", vite, buttonA, buttonB, buttonD, buttonE);
     }
     else if(caso == 4){
         piGreco(12, buttonD, record, "π", vite, buttonA, buttonB, buttonC, buttonE);  
     }
     else if(caso == 5){
         piGreco(16, buttonE, record, "π", vite, buttonA, buttonB, buttonC, buttonD);
     }
     else if(caso == 6){
      lcd.setCursor(8, 1);
      lcd.print("+");
      if(digitalRead(buttonC) == HIGH){
        vite++;
        lcd.setCursor(0, 0);
        lcd.print("Vite:" + vite);
      }
     }
  }
  lcd.clear();
  morte(vite);
  premere(buttonRecord, record, partite, record2);
  fine = false;
  vite = 5;
  finito = false;
  
}

void piGreco(int a, int bottone, int record, String n, int vite, int bottone1, int bottone2, int bottone3, int bottone4) {

    t1 = millis();
    lcd.setCursor(a, 1);
    lcd.print(n);
    t2 = millis();
    while(finito == false){
    if(digitalRead(bottone) == HIGH){
       record++;
       finito = true;
    }
    else if(digitalRead(bottone1) == HIGH || digitalRead(bottone2) == HIGH || digitalRead(bottone3) == HIGH || digitalRead(bottone4) == HIGH || (t2 - t1) > 1200){
       vite --;
       lcd.setCursor(0, 0);
       lcd.print("Vite:" + vite);
       finito = true;
    }
  }
}

void morte(int vite) {
  
    if(vite == 0){
       lcd.setCursor(2, 0);
       lcd.print("Haiperso");
       
    }
}

void premere(int bottone, int record, int partite, int record2) {

  lcd.clear();
  while(digitalRead(bottone) == HIGH) {
    if(record > record2){
      lcd.setCursor(0, 0);
      record2 = record;
      lcd.print(record2);
    }
    lcd.setCursor(1, 0);
    lcd.print(partite); 
  }
}

