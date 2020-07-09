//Dices!!! for Arduino
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

const int d6 = 7;
const int d8 = 8;
const int d20 = 9;
const int timer = 13;
int dice;
bool timerGo = false;
int timeLeft = 60;


void setup() {
    //LCD
    lcd.begin(16,2);
    lcd.print("Dices!!!");
    lcd.setCursor(0,1);
    lcd.print("Make a roll.");
    
    //Dice buttons
    pinMode(d6, INPUT);
    pinMode(d8, INPUT);
    pinMode(d20, INPUT);
    pinMode(timer, INPUT);
}

void loop() {
  if(timerGo == true){
    if(timeLeft == 0) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Your timer is finished.");
      lcd.setCursor(0,1);
      lcd.print("Make a roll!");
      timerGo = false;
      timeLeft = 60;
    }
    else {
      timeLeft--;
      lcd.setCursor(0,1);
      lcd.print(timeLeft);
      lcd.print(" seconds");
      delay(1000);
    }
    
  }
  else {
    if(digitalRead(d6) == HIGH || digitalRead(d8) == HIGH || digitalRead(d20) == HIGH){
      if(digitalRead(d6) == HIGH) {
        dice = 6;
      }
      else if(digitalRead(d8) == HIGH) {
        dice = 8;
      }
      else if(digitalRead(d20) == HIGH) {
        dice = 20;
      }
      int roll = random(dice)+1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Your D");
      lcd.print(dice);
      lcd.print(" roll:");
      lcd.setCursor(0,1);
      lcd.print(roll);
      delay(100);
    }
    else if(digitalRead(timer) == HIGH) {
      timerGo = true;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Time left:");
      lcd.setCursor(0,1);
      lcd.print(timeLeft);
      lcd.print(" seconds");
      delay(1000);
    }
    else {
      delay(100);
    }
  }

}
