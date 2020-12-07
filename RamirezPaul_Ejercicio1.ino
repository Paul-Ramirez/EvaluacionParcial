/*
 * Ejercicio 1
 * Autor: Rmirez Paul
 */
int inicio=1;
volatile int dato;
int dato2;
int on;
int cont;
int i;
int j;
int pesocol,pesoarg,franco,dolar,real;
void setup() {
  Serial.begin(9600);
  Serial.println("INICIO");
  attachInterrupt(0,activacion1,LOW);
  attachInterrupt(1,activacion2,LOW);

}

void loop() {
  if(inicio==1){
    inicio=0;
    Serial.println("Ingrese valor euro");
  } 

}
//int0
void activacion1(){
  if(Serial.available()>0){
      dato=Serial.read();
      
    }
    //realiza la conversion
 pesocol=dato*4223;
 Serial.println(String("Peso colombiano: ")+String(pesocol));

 dolar=dato*1.21;
 Serial.println(String("Dolar: ")+String(dolar));
 

 real=dato*6.20;
 Serial.println(String("Real: ")+String(real));
 inicio=1;
}
//int1
void activacion2(){
  if(Serial.available()>0){//verifica el dato
      dato=Serial.read();
      
    }
    //realiza la conversion
  pesocol=dato*4223;
 Serial.println(String("Peso colombiano: ")+String(pesocol));

 franco=dato*1.08;
 Serial.println(String("Franco: ")+String(franco));
 

 pesoarg=dato*99.04;
 Serial.println(String("Peso Argentino: ")+String(pesoarg));

 
}
