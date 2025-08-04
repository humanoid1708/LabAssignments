int ledPin = 10;
int buzzer = 7;
int tempPin = A0;
float voltage;
int temp;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensorVal = analogRead(A0);
  voltage = sensorVal * (5.0/1024.0);
  temp = (voltage - 0.5) * 100.0;
  Serial.print(temp);
  Serial.println();

  if(temp >= 100) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzer, LOW);
  }
  delay(500);
}
