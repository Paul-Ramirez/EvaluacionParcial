/*
 * MASTER
 * AUTOR: RAMIREZ PAUL
 */
 #include<Wire.h>
 #include<LiquidCrystal.h>

int cont=0;
String salida,salida2;
String dato2;
char vocales[5];
char aux;

void setup() {
  Wire.begin();//indica que es el master
  Serial.begin(9600);
  Serial.println("Ingrese mensaje: ");
  Wire.onReceive(receiveEvent);//evento de recepcion

}

void loop() {
  if(Serial.available()>0){//verifica el dato en la terminal
    char dato=Serial.read();//lectura del dato en la terminal
    Wire.beginTransmission(4);//inicia trnsmison hacia la posicion 4
    Wire.write(dato);//escribe el dato
    Wire.endTransmission();//finaliza transmision
  }
}



//metodo de envio
void receiveEvent(int bytes){//evento de recepcion
  while(Wire.available()){//determina si hay bytes para leer
    char dato=Wire.read();//lee el dato
    switch(dato){//impresion de las vocales<
      case 'a':
      salida=salida+"a";
      break;
      case 'e':
      salida=salida+"e";
      break;
      case 'i':
      salida=salida+"i";
      break;
      case 'o':
      salida=salida+"o";
      break;
      case 'u':
      salida=salida+"u";
      break;  
    }
    
  }
  Serial.println(salida);//se imprime la codificacion
  Wire.requestFrom(4,4);//recupera informacion desde el esclavo
  if(Serial.available()>0){//verifica el dato en la terminal
    salida2=Serial.read();//se lee el dato en la terminal
  }
  
  
}
