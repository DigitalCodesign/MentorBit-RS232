/*


            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    Autor: Digital Codesign
    Version: 1.0.0
    Fecha de creación: Julio de 2025
    Fecha de version: Julio de 2025
    Repositorio: https://github.com/DigitalCodesign/MentorBit-RS232
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit RS-232.
    Metodos principales:
        MentorBitRS232 -> Constructor de la clase
        begin -> inicializador del módulo
        cambiarI2CAddr -> Función para cambiar la dirección I2C del módulo RS-232
        apagarLedError -> Función para apagar el led de error de comunicaciones I2C del módulo RS-232
        enviarMsg -> Función para enviar un mensaje a través del RS-232
        recibirMsg -> Función para recibir un mensaje del buffer del módulo RS-232
        mensajesPendientes -> Función para evaluar cuantos mensajes quedan pendientes en el buffer del módulo RS-232
        
*/

#include "MentorBitRS232.h"

/*  
    Constructor de la clase
*/
MentorBitRS232::MentorBitRS232(){

}

/*
    Inicializador del módulo MentorBit RS-232
*/
void MentorBitRS232::begin(uint8_t i2c_addr){
    _i2c_addr = i2c_addr;
    Wire.begin();
}

/*
    Función para cambiar la dirección i2c del modulo de RS-232
*/
void MentorBitRS232::cambiarI2CAddr(uint8_t new_i2c_addr){
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0x49);
    Wire.write(i2c_addr);
    Wire.endTransmission();
    _i2c_addr = new_i2c_addr;
}

/*
    Función para apagar el led de error de comunicaciones I2C del modulo
*/
void MentorBitRS232::apagarLedError(){
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0x00);
    Wire.write(0x20);
    Wire.endTransmission();
}

/*
    Función para enviar un mensaje por RS-232
*/
void MentorBitRS232::enviarMsg(uint8_t* data, uint8_t size){
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0x00);
    Wire.write(0x31);
    for(uint8_t y = 0; y < size ; y++){
        Wire.write(data[y]);
    }
    Wire.endTransmission();
}

/*
    Función para recibir un mensaje por el RS-232
*/
void MentorBitRS232::recibirMensaje(uint8_t *data){
    _solicitarInfoMsg();
    delay(10);
    for (uint8_t i = 0; i < 32; i++){
        data[i] = 0x00;
    }
    uint8_t length = _longitudNextMsg() - 1;
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0x00);
    Wire.write(0x31);
    Wire.endTransmission();
    Wire.requestFrom(_i2c_addr,length);
    for (uint8_t i = 0; i < length; i++){
        data[i] = Wire.read();
    }
}

/*
    Función para evaluar el numero de mensajes pendientes en el buffer del modulo
*/
uint8_t MentorBitRS232::mensajesPendientes(){

    _solicitarInfoMsg();
    delay(100);
    uint8_t i = 0;
    uint8_t value[3];
    while(Wire.available()){
        value[i] = Wire.read();
        i++;
    }
    return value[1];
}

/*
    Función para evaluar la longitud del proximo mensaje que va a enviar el módulo RS-232
*/
uint8_t MentorBitRS232::_longitudNextMsg(){
    uint8_t i = 0;
    uint8_t value[3];
    while(Wire.available()){
        value[i] = Wire.read();
        i++;
    }
    return value[2];
}

/*
    Función para solicitar una trama de información al módulo
*/
void MentorBitRS232::_solicitarInfoMsg(){
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0x00);
    Wire.write(0x30);
    Wire.endTransmission();
    Wire.requestFrom(_i2c_addr,3);
}

void MentorBitRS232::configPort(const Port& port) {

_port.type = port.type;
_port.location = port.location;
_port.gpios[0] = port.gpios[0];
_port.gpios[1] = port.gpios[1];

pinMode(_port.gpios[0], OUTPUT);

}
