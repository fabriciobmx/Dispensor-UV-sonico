/*
Projeto Arduino
Arduino com sensor de proximidade ultrasonico HHC-SRO4
*/

//Incluindo biblioteca Ultrasonic.h
#include "Ultrasonic.h"
 
//criando objeto ultrasonic e definindo as portas digitais
//do Trigger - 6 - e Echo - 7
Ultrasonic ultrasonic(6,7);
 
//Declaração das constantes referentes aos pinos digitais.
const int ledVerde = 13;
const int ledAmarelo = 12;
const int ledVermelho = 11;
 
long microsec = 0;
float distanciaCM = 0;
 
void setup() {
  Serial.begin(9600); //Inicializando o serial monitor
   
  //Definindo pinos digitais
  pinMode(ledVerde,OUTPUT); //13 como de saída.
  pinMode(ledAmarelo,OUTPUT); //12 como de saída.
  pinMode(ledVermelho,OUTPUT); //11 como de saída.
}
 
void loop() { 
  //Lendo o sensor
  microsec = ultrasonic.timing();
 
  //Convertendo a distância em CM
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);
 
  ledDistancia();
 
  Serial.print(distanciaCM);
  Serial.println(" cm");
  delay(1000);
}
 
//Método que centraliza o controle de acendimento dos leds.
void ledDistancia() {
   
  //Apagando todos os leds
  digitalWrite(ledVerde,LOW); 
  digitalWrite(ledAmarelo,LOW);
  digitalWrite(ledVermelho,LOW);
   

  //Acendendo o led adequado para a distância lida no sensor
  if (distanciaCM >= 51 and distanciaCM <=70 ) {
    digitalWrite(ledVerde,HIGH); 
  }
   
  if (distanciaCM <=50 and distanciaCM >= 20) {
    digitalWrite(ledAmarelo,HIGH);
  }
   
  if (distanciaCM < 20) {
    digitalWrite(ledVermelho,HIGH);
  }
}
