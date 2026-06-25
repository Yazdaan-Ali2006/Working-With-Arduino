void setup()
{
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
}
void loop()
{
digitalWrite(8, HIGH);
digitalWrite(9, LOW);
delay(3000); //Wait for 3000 millisecond(s)
  digitalWrite(8,LOW);
digitalWrite(9, LOW);
delay(3000);  //Wait for 3000 millisecond(s)
digitalWrite(9, HIGH);
digitalWrite(8, LOW);
delay(3000); //Wait for 3000 millisecond(s)
    digitalWrite(8,LOW);
digitalWrite(9, LOW);
delay(3000); //Wait for 3000 millisecond(s)
}
