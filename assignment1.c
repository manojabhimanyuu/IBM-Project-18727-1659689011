int redLed = 1;
int greenLed = 2;
int buzzer = 0;
int smokeA0 = A5;
int temperature = A1;
int blueLed = 7;
int sensorThres = 400;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(temperature, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  int analogSensor1 = analogRead(temperature);
  Serial.print("Pin A5:");
  Serial.print("Pin A1:");
  Serial.println(analogSensor);
  Serial.println(analogSensor);
  if (analogSensor > sensorThres || analogSensor1 > 23)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed,HIGH);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(blueLed, LOW);
    noTone(buzzer);
  }
  delay(100);
}