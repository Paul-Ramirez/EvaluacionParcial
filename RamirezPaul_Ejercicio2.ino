/*
 * Ejercicio 2
 * Autor Ramirez Paul
 * 
 */
 #include<Servo.h>
 Servo servo1;
 String dato;
 int giro;
 int btn1=5;
 int btn2=6;
 int btn3=7;
 int btn4=8;
 int btn5=9;

void setup() {
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  pinMode(btn3,INPUT);
  pinMode(btn4,INPUT);
  pinMode(btn5,INPUT);
  servo1.attach(6);
  attachInterrupt(0,activacion,LOW);
  Serial.begin(9600);
  Serial.println("Ingrese el valor de 0 al 100");
  

}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    giro=dato.toInt();
    
  }
  if(giro<100){
    servo1.write(giro);
    
  }else{
    Serial.println("Dato ingresado erroneo");
  }

}

void activacion(){
  
}
