int inches = 0;
int cm = 0;

long readUlSensor(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
void setup()
{
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  cm = 0.01723 * readUlSensor(10,4);
  inches = cm / 2.54;
  Serial.print(inches);
  Serial.print("in, \n");
  delay(50);

  if (inches < 10) {
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
}