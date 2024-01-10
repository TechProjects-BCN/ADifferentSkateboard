int interruptor1 = 9; //blanc
int interruptor2 = 8; //negre
int ledverd = 2;
int ledvermell = 3;
int valor1 = 0;
int valor2 = 0;
int ENA = 6;
int IN1 = 13;
int IN2 = 12;

int ENB = 5;
int IN3 = 11;
int IN4 = 10;

int vel = 0;

void setup() {
  pinMode (interruptor1, INPUT);
  pinMode (interruptor2, INPUT);
  pinMode (ledverd, OUTPUT);
  pinMode (ledvermell, OUTPUT);
  Serial.begin (9600);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void endavant() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, vel);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, vel);
}
 void endarrere(){
   digitalWrite (IN1, HIGH);
   digitalWrite (IN2,LOW );
   analogWrite (ENA, vel);
   digitalWrite (IN3, HIGH);
   digitalWrite (IN4, LOW);
   analogWrite (ENB, vel);  
}
void parar(){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 0);  
}

void loop() {
  valor1 = digitalRead(interruptor1);
  valor2 = digitalRead(interruptor2);  
  Serial.println(vel);
  Serial.println (valor1);
  Serial.println (valor2);
  //  if (valor1 == LOW && vel <= 255){
  //    vel = vel + 1;
  //    delay (100);
  //    }
  //  if (valor2 == LOW && vel <= -255){
  //    vel = vel-1;
  //    delay (100);
  //    }
  
  if (valor1 == HIGH && valor2 == LOW){
    digitalWrite (ledverd, HIGH);
    digitalWrite (ledvermell, LOW);
    Serial.println("Endavant");
    endavant();
  }
  else if (valor1 == LOW && valor2 == HIGH){
    digitalWrite(ledverd, LOW);
    digitalWrite (ledvermell, HIGH);
    Serial.println("Endarrere");
    endarrere();
  }
  else{
    digitalWrite(ledverd, LOW);
    digitalWrite (ledvermell, LOW);
    Serial.println ("Parar"); 
    parar();  
  }
}