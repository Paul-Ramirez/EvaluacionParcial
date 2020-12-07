/*
 *Esclavo
 *Autor: Ramirez Paul 
 *
*/

#include <Wire.h>
String salida;
String salida2;
String dato2;
char vocales[5];
char aux;

void setup() {
  Wire.begin(4);//indica que es el escalvo y se le da la posicion 4
  Serial.begin(9600);//inicializa comunicacion serial
  Wire.onReceive(receiveEvent);//recibir transmision de datos
  Wire.onRequest(requestEvent);//mensaje de respuesta
  

}

void loop() {
  delay(1000);
}


void receiveEvent(int bytes){//recibir transmision de datos
  //mientras haya bytes para ser leidos
  while(Wire.available()){
    char dato=Wire.read();//dato que se lee de la transmion
    switch(dato){//codificacion de los bytes ingresados
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
  //impresion por comunicacion serial
  Serial.println(salida);
  if(Serial.available()>0){//verifica si hay dato en la terminal
    salida2=Serial.read();//lee el dato en la termianal
  }
  
}

void requestEvent(){//evento de respuesta a la comunicacion
  //si existe algun dato en la terminal virtual
  if(Serial.available()>0){//verifica la informacion en la terminal
    char dato2=Serial.read();//lee el dato requerido
    Wire.beginTransmission(4);//inicia transmision con posicion 4
    Wire.write(dato2);//escribe el dato a enviar
    Wire.endTransmission();//finalizar transmision
    
  }
  for(int i=0;i<4;i++){
    dato2=vocales[i];
  }
  Serial.println(dato2);
}
