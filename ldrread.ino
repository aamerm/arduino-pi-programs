

int LDR = 0;
int LDRValue=0;
int light=500;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  LDRValue=analogRead(LDR);
  Serial.print("LDR Value is: ");
  Serial.println(LDRValue);
  delay(1000);
  if(LDRValue<light)
  {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
}
