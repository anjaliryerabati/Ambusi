#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

//SoftwareSerial Serial1(18,19);

int  NIR1     = 22;
int  NIR2     = 24;
int  NIR3     = 26;
int  NRED     = 28;
int  NYELLOW  = 30;
int  NGREEN   = 32;


int  EIR1 = 23;
int  EIR2 = 25;
int  EIR3 = 27;
int  ERED     = 29;
int  EYELLOW  = 31;
int  EGREEN   = 33;


int  WIR1 = 48;
int  WIR2 = 50;
int  WIR3 = 52;
int  WRED     = 42;
int  WYELLOW  = 44;
int  WGREEN   = 46;


int  SIR1 = 49;
int  SIR2 = 51;
int  SIR3 = 53;
int  SRED     = 43;
int  SYELLOW  = 45;
int  SGREEN   = 47;


int ncnt=0,ecnt=0,scnt=0,wcnt=0;

char Card_id[14];
int i=0;
bool stringComplete = false;  // whether the string Read is complete


//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
void setup() {
  pinMode(NIR1,INPUT_PULLUP);
  pinMode(NIR2,INPUT_PULLUP);
  pinMode(NIR3,INPUT_PULLUP);
  pinMode(EIR1,INPUT_PULLUP);
  pinMode(EIR2,INPUT_PULLUP);
  pinMode(EIR3,INPUT_PULLUP);
  pinMode(WIR1,INPUT_PULLUP);
  pinMode(WIR2,INPUT_PULLUP);
  pinMode(WIR3,INPUT_PULLUP);
  pinMode(SIR1,INPUT_PULLUP);
  pinMode(SIR2,INPUT_PULLUP);
  pinMode(SIR3,INPUT_PULLUP);
  pinMode(NRED,OUTPUT);
  pinMode(NYELLOW,OUTPUT);
  pinMode(NGREEN,OUTPUT);
  pinMode(ERED,OUTPUT);
  pinMode(EYELLOW,OUTPUT);
  pinMode(EGREEN,OUTPUT);
  pinMode(WRED,OUTPUT);
  pinMode(WYELLOW,OUTPUT);
  pinMode(WGREEN,OUTPUT);
  pinMode(SRED,OUTPUT);
  pinMode(SYELLOW,OUTPUT);
  pinMode(SGREEN,OUTPUT);
  digitalWrite(NRED,HIGH);
  digitalWrite(NYELLOW,HIGH);
  digitalWrite(NGREEN,HIGH);
  digitalWrite(ERED,LOW);
  digitalWrite(EYELLOW,LOW);
  digitalWrite(EGREEN,LOW);
  digitalWrite(WRED,LOW);
  digitalWrite(WYELLOW,LOW);
  digitalWrite(WGREEN,LOW);
  digitalWrite(SRED,LOW);
  digitalWrite(SYELLOW,LOW);
  digitalWrite(SGREEN,LOW);
  Serial1.begin(115200);
  Serial.begin(9600);
 lcd.begin(16, 2);
 lcd.setCursor(3,0);
 lcd.print("Welcome to ");
 lcd.setCursor(5,1);
 lcd.print("AMBUSI");
}
void loop() {
  
              if(!digitalRead(NIR1)&&digitalRead(NIR2)&&digitalRead(NIR3))
              {
                ncnt=1;
              }
              else if(!digitalRead(NIR1)&&!digitalRead(NIR2)&&digitalRead(NIR3))
              {
                ncnt=2;
              }
              else if(!digitalRead(NIR1)&&!digitalRead(NIR2)&&!digitalRead(NIR3))
              {
                ncnt=3;
              }
              else
                ncnt=0;

            if(!digitalRead(EIR1)&&digitalRead(EIR2)&&digitalRead(EIR3))
              {
                ecnt=1;
              }
              else if(!digitalRead(EIR1)&&!digitalRead(EIR2)&&digitalRead(EIR3))
              {
                ecnt=2;
              }
              else if(!digitalRead(EIR1)&&!digitalRead(EIR2)&&!digitalRead(EIR3))
              {
                ecnt=3;
              }
              else
                ecnt=0;

              if(!digitalRead(SIR1)&&digitalRead(SIR2)&&digitalRead(SIR3))
              {
                scnt=1;
              }
              else if(!digitalRead(SIR1)&&!digitalRead(SIR2)&&digitalRead(SIR3))
              {
                scnt=2;
              }
              else if(!digitalRead(SIR1)&&!digitalRead(SIR2)&&!digitalRead(SIR3))
              {
                scnt=3;
              }
              else
                scnt=0;

              if(!digitalRead(WIR1)&&digitalRead(WIR2)&&digitalRead(WIR3))
              {
                wcnt=1;
              }
              else if(!digitalRead(WIR1)&&!digitalRead(WIR2)&&digitalRead(WIR3))
              {
                wcnt=2;
              }
              else if(!digitalRead(WIR1)&&!digitalRead(WIR2)&&!digitalRead(WIR3))
              {
                wcnt=3;
              }
              else
                wcnt=0;
              if (stringComplete) 
             {
              i=0;
              lcd.clear();
              lcd.print("Amblnce Detected");
              lcd.setCursor(0,1);
              lcd.print("            ");
              digitalWrite(NRED,HIGH);
              digitalWrite(NYELLOW,LOW);
              digitalWrite(NGREEN,HIGH);
              digitalWrite(ERED,LOW);
              digitalWrite(EYELLOW,LOW);
              digitalWrite(EGREEN,HIGH);
              digitalWrite(WRED,LOW);
              digitalWrite(WYELLOW,HIGH);
              digitalWrite(WGREEN,LOW);
              digitalWrite(SRED,LOW);
              digitalWrite(SYELLOW,HIGH);
              digitalWrite(SGREEN,LOW);
              delay(1000);
              digitalWrite(NRED,LOW);
                  digitalWrite(NYELLOW,HIGH);
                  digitalWrite(NGREEN,HIGH);
                  digitalWrite(ERED,LOW);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,HIGH);
                  digitalWrite(WRED,LOW);
                  digitalWrite(WYELLOW,LOW);
                  digitalWrite(WGREEN,HIGH);
                  digitalWrite(SRED,LOW);
                  digitalWrite(SYELLOW,LOW);
                  digitalWrite(SGREEN,HIGH);
              delay(2000);
              //memset(Card_id,'\0',11);
              stringComplete = false;
              delay(3000);
            }
          else
        {
                if(ncnt>ecnt&&ncnt>scnt&&ncnt>wcnt)
                {
                  lcd.clear();
                  lcd.print("Traffic in North");
                  digitalWrite(NRED,HIGH);
                  digitalWrite(NYELLOW,LOW);
                  digitalWrite(NGREEN,HIGH);
                  digitalWrite(ERED,LOW);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,HIGH);
                  digitalWrite(WRED,LOW);
                  digitalWrite(WYELLOW,HIGH);
                  digitalWrite(WGREEN,LOW);
                  digitalWrite(SRED,LOW);
                  digitalWrite(SYELLOW,HIGH);
                  digitalWrite(SGREEN,LOW);
                  delay(1000);
                  digitalWrite(NRED,LOW);
                  digitalWrite(NYELLOW,HIGH);
                  digitalWrite(NGREEN,HIGH);
                  digitalWrite(ERED,LOW);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,HIGH);
                  digitalWrite(WRED,LOW);
                  digitalWrite(WYELLOW,LOW);
                  digitalWrite(WGREEN,HIGH);
                  digitalWrite(SRED,LOW);
                  digitalWrite(SYELLOW,LOW);
                  digitalWrite(SGREEN,HIGH);
                  delay(5000);
                }
                else if(ecnt>ncnt&&ecnt>scnt&&ecnt>wcnt)
                {
                  lcd.clear();
                  lcd.print("Traffic in East");
                  digitalWrite(NRED,HIGH);
                  digitalWrite(NYELLOW,LOW);
                  digitalWrite(NGREEN,HIGH);
                  digitalWrite(ERED,LOW);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,HIGH);
                  digitalWrite(WRED,LOW);
                  digitalWrite(WYELLOW,HIGH);
                  digitalWrite(WGREEN,LOW);
                  digitalWrite(SRED,LOW);
                  digitalWrite(SYELLOW,HIGH);
                  digitalWrite(SGREEN,LOW);
                  delay(1000);
                  digitalWrite(NRED,HIGH);
                  digitalWrite(NYELLOW,HIGH);
                  digitalWrite(NGREEN,LOW);
                  digitalWrite(ERED,HIGH);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,LOW);
                  digitalWrite(WRED,LOW);
                  digitalWrite(WYELLOW,LOW);
                  digitalWrite(WGREEN,HIGH);
                  digitalWrite(SRED,LOW);
                  digitalWrite(SYELLOW,LOW);
                  digitalWrite(SGREEN,HIGH);
                  delay(5000);
                }
                else if(scnt>ncnt&&scnt>ecnt&&scnt>wcnt)
                {
                  lcd.clear();
                  lcd.print("Traffic in South");
                  digitalWrite(NRED,HIGH);
                  digitalWrite(NYELLOW,LOW);
                  digitalWrite(NGREEN,HIGH);
                  digitalWrite(ERED,LOW);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,HIGH);
                  digitalWrite(WRED,LOW);
                  digitalWrite(WYELLOW,HIGH);
                  digitalWrite(WGREEN,LOW);
                  digitalWrite(SRED,LOW);
                  digitalWrite(SYELLOW,HIGH);
                  digitalWrite(SGREEN,LOW);
                  delay(1000);
                  digitalWrite(NRED,HIGH);
                  digitalWrite(NYELLOW,HIGH);
                  digitalWrite(NGREEN,LOW);
                  digitalWrite(ERED,LOW);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,HIGH);
                  digitalWrite(WRED,LOW);
                  digitalWrite(WYELLOW,LOW);
                  digitalWrite(WGREEN,HIGH);
                  digitalWrite(SRED,HIGH);
                  digitalWrite(SYELLOW,LOW);
                  digitalWrite(SGREEN,LOW);
                  delay(5000);
                }
                else if(wcnt>ncnt&&wcnt>ecnt&&wcnt>scnt)
                {
                  lcd.clear();
                  lcd.print("Traffic in West");
                  digitalWrite(NRED,HIGH);
                  digitalWrite(NYELLOW,LOW);
                  digitalWrite(NGREEN,HIGH);
                  digitalWrite(ERED,LOW);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,HIGH);
                  digitalWrite(WRED,LOW);
                  digitalWrite(WYELLOW,HIGH);
                  digitalWrite(WGREEN,LOW);
                  digitalWrite(SRED,LOW);
                  digitalWrite(SYELLOW,HIGH);
                  digitalWrite(SGREEN,LOW);
                  delay(1000);
                  digitalWrite(NRED,HIGH);
                  digitalWrite(NYELLOW,HIGH);
                  digitalWrite(NGREEN,LOW);
                  digitalWrite(ERED,LOW);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,HIGH);
                  digitalWrite(WRED,HIGH);
                  digitalWrite(WYELLOW,LOW);
                  digitalWrite(WGREEN,LOW);
                  digitalWrite(SRED,LOW);
                  digitalWrite(SYELLOW,LOW);
                  digitalWrite(SGREEN,HIGH);
                  delay(5000);
                } 
                else
                {
                  lcd.clear();
                  lcd.print("Traffic Yet to ");
                  lcd.setCursor(0,1);
                  lcd.print("  be Detected ");
                  digitalWrite(NRED,HIGH);
                  digitalWrite(NYELLOW,HIGH);
                  digitalWrite(NGREEN,HIGH);
                  digitalWrite(ERED,LOW);
                  digitalWrite(EYELLOW,LOW);
                  digitalWrite(EGREEN,LOW);
                  digitalWrite(WRED,LOW);
                  digitalWrite(WYELLOW,LOW);
                  digitalWrite(WGREEN,LOW);
                  digitalWrite(SRED,LOW);
                  digitalWrite(SYELLOW,LOW);
                  digitalWrite(SGREEN,LOW);
                  delay(1000);
                  
                }
                Serial.println("  ");
                Serial.print("*");
                Serial.print(ncnt,DEC);
                Serial.print(",");
                Serial.print(ecnt,DEC);
                Serial.print(",");
                Serial.print(wcnt,DEC);
                Serial.print(",");
                Serial.print(scnt,DEC);
                Serial.print("#");
                Serial.println("  ");
                
  }
} 




void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    Card_id[i] = inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (i == 12) {
      Card_id[++i]='\0';
      stringComplete = true;
      i=0;
    }
    else
    i++;
  }
}

