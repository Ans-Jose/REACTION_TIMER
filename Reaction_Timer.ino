#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 1;
const int buzzerPin = 6;
const int ledPin = 7;

unsigned long startTime;
unsigned long reactionTime;
bool flag = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Reaction Timer");
  delay(3000);
  lcd.clear();

  beep(1, 150); //oru vattam beep with an interval of 150s
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Get ready...");
  digitalWrite(ledPin, LOW);
  delay(1000);

  if (digitalRead(buttonPin) == LOW) {
    lcd.clear();
  }
}lcd.print("Too Early!");
keep(2, 100);
delay(2000);
lcd.clear();
return;

delay(random(2000, 5000));

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("GO!");
digitalWrite(ledPin, HIGH);
startTime = millis();//returns the number of milliseconds since the arduino board began running the program
flag = true;

while (flag) {
  if (digitalRead(buttonPin) == LOW) {
    reactionTime = millis() - startTime;
    flag = false;
  }
}
digitalWrite(ledPin, LOW);

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Your Time:");
lcd.setCursor(2, 1);
lcd.print(reactionTime);
lcd.print(" ms");

beep(2, 200);
delay(5000);
lcd.clear();

void beep(int times, int duration) {
  for (int i = 0; i < times; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(duration);
    digitalWrite(buzzerPin, LOW);
    delay(duration);
  }
}