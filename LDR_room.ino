int button = 4;
int buzzer = 9;
int LDR_1 = A0;
int LDR_2 = A5;

int buttonState = 0;
int buttonPushCounter = 0;
int lastButtonState = 0;

bool LDR1 = LOW;
bool LDR2 = LOW;
 
int people = 0;
void setup()
{
  pinMode(LDR_1, INPUT);
  pinMode(LDR_2, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);    //9600 bits/sec
}
 
void loop()
{   
    buttonState = digitalRead(button);
  if (buttonState != lastButtonState)
  {
    if (buttonState == HIGH)
    {
      buttonPushCounter++;
      Serial.println(buttonPushCounter);
    }
    delay(50);
  }
 
 lastButtonState = buttonState;
 
 if (buttonPushCounter %2 != 0)
 {
     if((analogRead(LDR_1) < 700) && (analogRead(LDR_2) > 700) && (LDR1 == LOW) && (LDR2 == LOW))
    {
      LDR1 = HIGH;
    }
    delay(100);
    if((analogRead(LDR_1) > 700) && (analogRead(LDR_2) < 700) && (LDR1 == HIGH) &&  (LDR2 == LOW))
    {
      while(analogRead(LDR_2) < 700)
      {}
      people++ ;
      Serial.print("NUMBER OF PEOPLE IN THE ROOM IS ");
      Serial.println(people);
      LDR1 = LOW;
      LDR2 = LOW;
    }
     if((analogRead(LDR_2) < 700) && (analogRead(LDR_1) > 700) && (LDR1 == LOW) && (LDR2 == LOW))
    {
      LDR2 = HIGH;
    }
    delay(100);
    if((analogRead(LDR_2) > 700) && (analogRead(LDR_1) < 700) && (LDR2 == HIGH) &&  (LDR1 == LOW))
    {
      while(analogRead(LDR_1) < 700)
      {}
      if (people > 0)
      {
        people--;
      }
      Serial.println("NUMBER OF THE PEOPLE IN THE ROOM IS ");
      Serial.println(people);
      LDR1 = LOW;
      LDR2 = LOW;
    }
    if (people >5)
    {
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
    }
 }

    delay(50);
}
