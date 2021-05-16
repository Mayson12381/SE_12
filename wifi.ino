#include <LiquidCrystal.h>

const int buttonOnPin = 2;
const int buttonOffPin = 3;
const int lampOnPin = 12;
const int lampOffPin = 13;
int buttonOnState = 0;
int buttonOffState = 0;
int pirPin = 10;
int pirValue;

const int rs = 4, en = 5, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);
  pinMode(lampOnPin, OUTPUT);
  pinMode(lampOffPin, OUTPUT);
  digitalWrite(lampOnPin, LOW);
  digitalWrite(lampOffPin, LOW);

  lcd.begin(16, 2);
  lcd.print("Initializing...");

  delay(60000);
  lcd.begin(16, 2);
  lcd.print("Floor Lamp - Off");
  lcd.setCursor(0,1);
  lcd.print("<-ON   Off->");
}

void loop() {
  pirValue = digitalRead(pirPin);
  Serial.println(pirValue);
  buttonOnState = digitalRead(buttonOnPin);
  buttonOffState = digitalRead(buttonOffPin);
  if (buttonOnState == HIGH) {
    digitalWrite(lampOnPin, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Floor Lamp - On ");
  } if (buttonOffState == HIGH) {
    digitalWrite(lampOffPin, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Floor Lamp - Off");
  } else {
    digitalWrite(lampOffPin, LOW);
    digitalWrite(lampOnPin, LOW);
  }
}
