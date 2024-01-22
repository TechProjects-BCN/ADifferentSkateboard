int interruptor1 = 5; //blanc
int interruptor2 = 4; //negre
int ledverd = 3;
int ledvermell = 2;
int valor1 = 0;
int valor2 = 0;
int ENA = 6;
int IN1 = 8;
int IN2 = 9;

int ENB = 12;
int IN3 = 10;
int IN4 = 11;

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

void forward() { 
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, vel);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, vel);
}
 void backward (){
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
  valor1 = digitalRead(interruptor1); //white button state pressed(0/LOW) not pressed(1/HIGH)
  valor2 = digitalRead(interruptor2); //black button skate pressed(0/LOW) not pressed(1/HIGH)
  Serial.println(vel); //print velocity
  Serial.println (valor1); //print white button state
  Serial.println (valor2); //print black button state
    if (valor1 == LOW && vel <= 255){ //if white button is pressed, and velocity is less than 255(maximum)
      vel = vel + 1; //increase veocity by 1
      delay (100); //wait 0.1 seconds
      } //when the button is not pressed or the velocity reaches 255 it stops incresing
    if (valor2 == LOW && vel <= -255){ //if black button is pressed and velocity is less than 255(maximum)
      vel = vel-1; //decrease velocity by 1
      delay (100); //wait 0.1 seconds
      }

  forward();
  // if (valor1 == HIGH && valor2 == LOW){ //if button white is pressed and button black is not pressed, move forward
  //   digitalWrite (ledverd, HIGH);
  //   digitalWrite (ledvermell, LOW);
  //   Serial.println("Endavant");
  //   forward();
  // }
  // else if (valor1 == LOW && valor2 == HIGH){ //if button white is not pressed and button black is pressed, move backward
  //   digitalWrite(ledverd, LOW);
  //   digitalWrite (ledvermell, HIGH);
  //   Serial.println("Endarrere");
  //   backward();
  // }
  // else{ 
  //   digitalWrite(ledverd, LOW);
  //   digitalWrite (ledvermell, LOW);
  //   Serial.println ("Parar"); 
  //   parar();  
  //}
  //sempre endavant i només canvia la velocitat positiva (endavant) negativa (endarrere). No van falta les altres funcions.
}