/***********************************
Rotinas para EEPROM I²C

por Lucas Tamborrino
19/09/2017

************************************/

#include "EEPROM_I2C.hpp"



//**************************************************************************************************

EEPROM_I2C::EEPROM_I2C(uint8_t deviceAdress) //Geralmente 0x50
{
    _deviceAdress = deviceAdress;
    Wire.begin();

}

//**************************************************************************************************

uint8_t EEPROM_I2C::write(uint32_t Mem_Adress, uint8_t Valor) //Salva valor no endereço dado e retorna 1 ao final da operação
{
    Wire.beginTransmission(_deviceAdress);
    Wire.write(Mem_Adress >> 8);  // Manda MSB do endereço
    Wire.write(Mem_Adress & 0xFF); // Manda LSB do endereço
    Wire.write(Valor);
    Wire.endTransmission();
    return 1;
}

//**************************************************************************************************

uint8_t EEPROM_I2C::write_String(uint32_t Mem_Adress, String Valor) //Salva string a partir do endereço inicial dado e retorna numero de bytes
{
    for (uint8_t x=0; x<Valor.length(); x++){
        write(Mem_Adress + x, Valor.charAt(x));
        delay(6); //Write Cycle Time = 5ms
    }
    return Valor.length();
}

//**************************************************************************************************

uint8_t EEPROM_I2C::write_List(uint32_t Mem_Adress, uint8_t *List, uint8_t Num_bytes) //Recebe ponteiro da Lista e numero de bytes a ser gravado no endereço
{
    for (uint8_t x=0; x<Num_bytes; x++){
        write(Mem_Adress + x, List[x]);
        delay(6);
    }
    return 1;
}

//**************************************************************************************************

uint8_t EEPROM_I2C::read(uint32_t Mem_Adress)//Le um byte no endereço recebido
{
    Wire.beginTransmission(_deviceAdress);
    Wire.write(Mem_Adress >> 8);  // Manda MSB do endereço
    Wire.write(Mem_Adress & 0xFF); // Manda LSB do endereço
    Wire.endTransmission();
    Wire.requestFrom(_deviceAdress, 1); //Requisita 1 byte do dispositivo
    if (Wire.available()){
        data_Byte = Wire.read();
    }
    Wire.endTransmission();
    return data_Byte;
}

//**************************************************************************************************

String EEPROM_I2C::read_String(uint32_t Mem_Adress, uint8_t Num_bytes) //Recebe numero de bytes para ser lido e retorna uma String com o conteudo
{
    uint8_t valores_lidos[Num_bytes];

    for (uint8_t x=0; x<Num_bytes; x++){
        valores_lidos[x] = read(Mem_Adress + x);
    }

    return valores_lidos;


}

//**************************************************************************************************

uint8_t EEPROM_I2C::read_List(uint32_t Mem_Adress, uint8_t *List, uint8_t Num_bytes) //Escreve numero de bytes lidos do endereço no ponteiro da lista recebida
{
    for (uint8_t x=0; x<Num_bytes; x++){
        List[x] = read(Mem_Adress + x);
    }
    return 1;
}
