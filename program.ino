
#define trigPin 6  
#define echoPin 5
#define buzzer 2
#define ledred 4
#define ledgreen 3
float new_delay; 
int sound  = 500;

void setup() 
{
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ledred,OUTPUT);
  pinMode(ledgreen,OUTPUT);
  
}


void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  new_delay= (distance *3) +30;
  Serial.print(distance);
  Serial.println("  cm");
  if (distance < 50)
  {
   digitalWrite(buzzer,HIGH);
   delay(new_delay);
   digitalWrite(buzzer,LOW);
   digitalWrite(ledred, HIGH);
   digitalWrite(ledgreen, LOW);
   sound = 1000;
 
  }
  else
  {
    digitalWrite(buzzer,LOW);
	digitalWrite(ledgreen, HIGH);
  digitalWrite(ledred, LOW);

  }
  
 delay(200);
}