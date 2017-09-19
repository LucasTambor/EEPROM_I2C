/***********************************
Rotinas para EEPROM I²C

por Lucas Tamborrino
19/09/2017    

************************************/

#ifndef _EEPROM_I2C
#define _EEPROM_I2C

#include <Arduino.h>
#include <Wire.h>

class EEPROM_I2C
{
    public:
        EEPROM_I2C(uint8_t deviceAdress); //Geralmente 0x50

        uint8_t write(uint32_t Mem_Adress, uint8_t Valor); //Salva valor no endereço dado e retorna 1 ao final da operação

        uint8_t write_String(uint32_t Mem_Adress, String Valor); //Salva string a partir do endereço inicial dado e retorna numero de bytes

        uint8_t write_List(uint32_t Mem_Adress, uint8_t *List, uint8_t Num_bytes); //Recebe ponteiro da Lista e numero de bytes a ser gravado no endereço

        uint8_t read(uint32_t Mem_Adress);//Le um byte no endereço recebido

        String read_String(uint32_t Mem_Adress, uint8_t Num_bytes); //Recebe numero de bytes para ser lido e retorna uma String com o conteudo

        uint8_t read_List(uint32_t Mem_Adress, uint8_t *List, uint8_t Num_bytes); //Escreve numero de bytes lidos do endereço no pointeiro da lista


    private:
        uint8_t _deviceAdress;
        uint8_t data_Byte;
};





#endif//_EEPROM_I2C
