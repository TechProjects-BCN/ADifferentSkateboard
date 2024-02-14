int interruptor1 = 5; //blanc
int interruptor2 = 4; //negre
int valor1 = 0;
int valor2 = 0;
int ENA = 6;
int IN1 = 8;
int IN2 = 9;

int ENB = 12;
int IN3 = 10;
int IN4 = 11;

int vel = 0;

int  R = 13;
int  G = 3;
int  B = 2;
//int i = 0;
int FACTOR = 3;

void setup() {
  pinMode (interruptor1, INPUT);
  pinMode (interruptor2, INPUT);

  Serial.begin (9600);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (R, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (B, OUTPUT);
  vel=0;
}

void forward() { 
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, abs(vel));
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, vel);
}
 void backward (){
   digitalWrite (IN1, HIGH);
   digitalWrite (IN2,LOW );
   analogWrite (ENA, abs(vel) );
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
   
  if (valor2 == LOW && vel > -255){ //if black button is pressed and velocity is less than 255(maximum)
    vel = vel-2; //decrease velocity by 1
    delay (100); //wait 0.1 seconds
  }

  if (valor1 == LOW && vel < 255){ //if white button is pressed, and velocity is less than 255(maximum)
    vel = vel + 2; //increase veocity by 1
    delay (100); //wait 0.1 seconds
  } //when the button is not pressed or the velocity reaches 255 it stops incresing

  if (vel>0){
    forward();
  }
  if (vel<0){
    backward();
  }
//colors
  if ((vel <= -255 && vel > -200)){ //1 vermell
    R = 255;
    G = 0; 
    B = 0;
  }

  else if ((vel > -200 && vel <= -150 )){ //2 taronja
    R = 255;
    G = 128; 
    B = 0;
  }
  else if ((vel <= -150 && vel > -100)){ //3 yellow
    R = 255;
    G = 255; 
    B = 0;
  }
  else if ((vel <= -100 && vel > -50)){ //4 light green
    R = 128;
    G = 255; 
    B = 0;
  }
  else if ((vel <= -50 && vel > 0)){ //5 green
    R = 0;
    G = 255; 
    B = 125;
  }
  else if ((vel <= 0 && vel > 50)){ //6 turquoise
    R = 0;
    G = 255; 
    B = 255;
  }

 else if ((vel <= 50 && vel > 100)){ //7 light blue
    R = 0;
    G = 128; 
    B = 255;
  }

 else if ((vel <= 100 && vel > 150)){ //8 blue
    R = 0;
    G = 0; 
    B = 255;
  }     

 else if ((vel <= 150 && vel > 200)){ //9 purple
    R = 125;
    G = 0; 
    B = 255;
  }

 else if ((vel <= 200 && vel > 255)){ //10 pink
    R = 255;
    G = 0; 
    B = 255;
  }
 else { //14
    R = 255;
    G = 0; 
    B = 0;
  }
}