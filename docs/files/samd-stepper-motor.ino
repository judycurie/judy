int step = 9;
int dir = 8;
int stepDelay = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(step, OUTPUT);
  pinMode(dir, OUTPUT);
  digitalWrite(step, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(dir, LOW);
  digitalWrite(step, LOW);
  delayMicroseconds(stepDelay);
  digitalWrite(step, HIGH);
  delayMicroseconds(stepDelay);


}
