#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal ekran(0);

const int program = 2;
const int numWords = 5;

const int start = 4;
const int sicaklik = A0;
const int sure = A1;
const int led_on = 3;
const int led_off = 5;

int buttonState = 0;
int lastButtonState = 0;


String words[numWords] = {
  "COLORS",
  " WHITE",
  "COTTON",
  "  FAST",
  "  BUSY",
};

void setup()
{
  
  pinMode(program, INPUT_PULLUP); 
  pinMode(program, INPUT);
  pinMode(start, INPUT);
  pinMode(sicaklik, INPUT);
  pinMode(sure, INPUT);
  pinMode(led_on, OUTPUT);
  pinMode(led_off, OUTPUT);
  
  ekran.begin(16, 2);
  
  
  
}

void loop()
{
  
  buttonState = digitalRead(program); 

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      static int wordIndex = 0;
      ekran.setCursor(5, 0);
      ekran.print(words[wordIndex]);
      wordIndex = (wordIndex + 1) % numWords;
    }
    lastButtonState = buttonState;
  }
  
  int saat = analogRead(sure);
  float yikama_suresi = map(saat,0.0,1023.0,15,230)/100.0;
  
  int hours = int(yikama_suresi);
  int dakika = (yikama_suresi - hours)*60;
  
  if (dakika >=59){
    
    dakika = 0;
    
    hours = (hours + 1)%24;
  
  }
  
  ekran.setCursor(11,1);
  ekran.print(yikama_suresi);
  ekran.setCursor(11, 1);
  
  if (hours < 10) {
    ekran.print("0"); 
  }
  ekran.print(hours);
  ekran.print(":");
  if (dakika < 10) {
    ekran.print("0"); 
  }
  ekran.print(dakika);
  delay(100); 
  
  
  int derece = analogRead(sicaklik);
  int su_sicaklik = map(derece,0,1023,0,90);
  ekran.setCursor(5,1);
  ekran.print(su_sicaklik);
  ekran.setCursor(0,1);
  ekran.print("TEMP=");
  ekran.setCursor(12,0);
  ekran.print("TIME");
  ekran.setCursor(0,0);
  ekran.print("PROG=");
  
  
  
}