
 #define Pin2  2 // Optocopler 1
 #define Pin3  3 // Optocopler 2 
 #define PWMA  9 
 #define AIN2  8 
 #define AIN1  7
 #define STBY  6 

 #define PWMB  10 
 #define BIN2  11 
 #define BIN1  12  

 int SpeedA = 200 , SpeedB = 200 ;
 int Duration = 3000 ;
 volatile int counter0 = 0 ; // Motor A
 volatile int counter1 = 0 ; // Motor B

 void setup() {
  Serial.begin(9600); 
  pinMode(Pin2, INPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(Pin3, INPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);  
  pinMode(STBY, OUTPUT); 
  digitalWrite(STBY, HIGH); 
  attachInterrupt(0, interruptFunction0, CHANGE);  
  attachInterrupt(1, interruptFunction1, CHANGE);
    
  analogWrite(PWMA, SpeedA) ;
  analogWrite(PWMB, SpeedB) ;
    
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);  
 }

 void loop() {

  delay(Duration) ;
  Serial.print(" counter0 = ") ;
  Serial.print(counter0) ;
  Serial.print(" counter1 = ") ;  
  Serial.print(counter1) ;  

  int del = counter0-counter1 ;
  
  if ( del >=0 ) { SpeedA = SpeedA*0.99 ; }
  else { SpeedA=SpeedA*1.01 ; }

  Serial.print("  del = ") ;
  Serial.print(del) ;
  Serial.print("   SppeedA = ") ;  
  Serial.print(SpeedA) ;  
  Serial.print("  SppeedB = ") ;  
  Serial.println(SpeedB) ;    
  
  analogWrite(PWMA, SpeedA) ;
  analogWrite(PWMB, SpeedB) ; 
   
  counter0 = 0 ;   counter1 = 0 ;
 }

  void interruptFunction0() 
  {   counter0++ ;  } 
  
  void interruptFunction1() 
  {   counter1++ ;  }
