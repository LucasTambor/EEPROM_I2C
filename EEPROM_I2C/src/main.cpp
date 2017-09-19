/***********************************
Rotina Teste para biblioteca EEPROM_I2C

por Lucas Tamborrino
19/09/2017    
************************************/

#include <Arduino.h>
#include <inttypes.h>
#include "EEPROM_I2C.hpp"

EEPROM_I2C EEPROM_I2C(0x50);
String texto = "TESTE PORRA!";
uint8_t Lista_teste[10] = {1,2,3,4,5,6,7,8,9,10};
uint8_t Lista_Lida[10];


void setup() {
    Serial.begin(9600);

    Serial.println("Escrevendo 1 BYTE na EEPROM no end 10: ");
    EEPROM_I2C.write(10, 120);

    Serial.println("Escrevendo String na EEPROM no end 20: ");
    EEPROM_I2C.write_String(20, texto);

    Serial.println("Escrevendo Lista na EEPROM no end 30: ");
    EEPROM_I2C.write_List(32, Lista_teste, 10);
}

void loop() {
    Serial.println("lendo byte em end = 10: ");
    Serial.println(EEPROM_I2C.read(10));
    Serial.println("Lendo String na EEPROM no end 20: ");
    Serial.println(EEPROM_I2C.read_String(20, 12));
    Serial.println("Lendo Lista na EEPROM no end 32: ");
    EEPROM_I2C.read_List(32, Lista_Lida, 10);
    for(int x = 0; x<10; x++)
    {
        Serial.println(Lista_Lida[x]);
    }

    delay(500);
}
