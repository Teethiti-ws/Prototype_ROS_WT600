int dir1 = 51;

int dir2 = 50;

int pwm1 = 6;

int pwm2 = 7;

int en1 = 8;

int en2 = 9;

void setup()
{
  Serial.begin(9600);

  pinMode(dir1,OUTPUT);

  pinMode(dir2,OUTPUT);

  pinMode(pwm1,OUTPUT);

  pinMode(pwm2,OUTPUT);
  
  pinMode(en1,OUTPUT);

  pinMode(en2,OUTPUT);

  digitalWrite(en1, LOW);
  digitalWrite(en2, LOW);
}

void loop()
{
  analogWrite(pwm1, 150);
  analogWrite(pwm2, 150);

  digitalWrite(dir1, HIGH);

  digitalWrite(dir2, HIGH);
  delay(3000);
  
  analogWrite(pwm1, 150); 
  analogWrite(pwm2, 150); 

  digitalWrite(dir1, HIGH);

  digitalWrite(dir2, LOW);
  delay(3000);
  
  analogWrite(pwm1, 150); 
  analogWrite(pwm2, 150); 

  digitalWrite(dir1, LOW);

  digitalWrite(dir2, HIGH);
  delay(3000);
  
  analogWrite(pwm1, 150); 
  analogWrite(pwm2, 150); 

  digitalWrite(dir1, LOW);

  digitalWrite(dir2, LOW);
  delay(3000);

  analogWrite(pwm1, 0); 
  analogWrite(pwm2, 0); 
  delay(3000);
}
