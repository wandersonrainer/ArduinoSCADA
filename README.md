# Projeto 01: Sistema SCADA para monitoramento de tags na plataforma Arduino

## Visão Geral

Este projeto utiliza uma plataforma Arduino para fazer interface com dispositivos externos de forma a criar 6 tags, sendo duas analógicas e quatro digitais. O objetivo é criar um programa para a plataforma que permita obter os valores das tags e enviar estes valores para um sistema SCADA.
Esta integração pode ter vários desdobramentos no que diz respeito á supervisão das tags e a implementação de rede entre várias plataformas Arduino.

## Componentes Utilizados

- Arduino Uno
- Cabo USB
- Protoboard
- 2 push-button NA (2 terminais)
- 2 resistores 330R - 1/4 W
- 2 LEDs
- 1 potenciômetro 10k linear
- 1 sensor LM35

## Funcionalidades Principais

Este sistema incial tem como objetivo apenas o teste de hardware para posterior integração com o sistema SCADA. Embora o sistema tenha sensores analógicos, a programação preliminar não faz a leitura completados sensores. São apenas testes para verificação da integridade do hardware.

## Esquema de Conexão

![Esquema de Conexão](esquema_conexao.png)

## Código Fonte

```cpp
//codigo para teste do hardware do Proj. 01

#define bot1  2
#define bot2  3
#define LED1  7
#define LED2  6

int temp,pot;

void setup() {
  Serial.begin(9600);
  pinMode(bot1,INPUT_PULLUP);
  pinMode(bot2,INPUT_PULLUP);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
}

void loop() {
  bool botao1 = digitalRead(bot1);
  bool botao2 = digitalRead(bot2);
  if(!botao1)
    digitalWrite(LED1,1);
  else
    digitalWrite(LED1,0);
  
  if(!botao2)
    digitalWrite(LED2,1);
  else
    digitalWrite(LED2,0);
  pot = analogRead(A2);
  temp = analogRead(A3);
  Serial.print("POT: ");
  Serial.println(pot);
  Serial.print("TEMP: ");
  Serial.println(temp);
  Serial.println("\n");
  delay(300);
}
```

## Observações finais
Este programa faz o teste dos botões e dos LEDs. Além disso, envia pela porta serial, com baud rate de 9600 bps, a leitura analógica dos pinos A2 e A3, referentes ao potenciômetro e ao sensor LM35, respectivamente. Porém, as conversões não são transformadas, por enquanto, em tensão e temperatura.
