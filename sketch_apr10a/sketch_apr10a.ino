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
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(!fine) {
    if(digitalRead(buttonAvvia) == LOW){}
    else
      if(digitalRead(buttonAvvia) == HIGH){
        caso = random(1, 6);
        fine = true;
      }
  }
  lcd.setCursor(0, 0);
  lcd.print("Vite:" + vite);
  while(vite > 0){
     if(caso == 1){
         piGreco(1, buttonA, record, "π", vite);
     }
     else if(caso == 2){
         piGreco(5, buttonB, record, "π", vite);
     }
     else if(caso == 3){
         piGreco(9, buttonC, record, "π", vite);
         
     }
     else if(caso == 4){
         piGreco(12, buttonD, record, "π", vite);  
     }
     else if(caso == 5){
         piGreco(16, buttonE, record, "π", vite);
     }
     else if(caso == 6){
       lcd.setCursor(random(), 1);
       lcd.print("+");
       int a = random(buttonA || buttonB || buttonC || buttonD || buttonE);
       if(digitalRead(a) == HIGH) {
          vite ++;
       }
    }
  }
  lcd.clear();
  morte(vite);
  fine = false;
  vite = 5;
  
}

void piGreco(int a, int bottone, int record, String n, int vite) {

    lcd.setCursor(a, 1);
    lcd.print(n);
    if(digitalRead(bottone) == HIGH){
       record++;
    }
    else {
       vite --;
       lcd.setCursor(0, 0);
       lcd.print("Vite:" + vite);
    }
}

void morte(int vite) {
  
    if(vite == 0){
       lcd.setCursor(2, 0);
       lcd.print("Haiperso");
    }
}


