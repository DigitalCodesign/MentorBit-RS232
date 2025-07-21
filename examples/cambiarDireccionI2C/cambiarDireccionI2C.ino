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
        Este sketch muestra un ejemplo para cambiar la dirección I2C del módulo MentorBit RS-232

*/

// Se incluye la libreria MentorBitRS232
#include <MentorBitRS232.h>

// Se define la direccion I2C del módulo
#define I2C_RS232_ADDR 0x20

// Se define la nueva direccion I2C del módulo
#define NEW_I2C_RS232_ADDR 0x30

// Se crea el objeto RS_232 de la clase MentorBitRS232
MentorBitRS232 RS_232;

void setup(){
    // Se inicializa el módulo RS-232
    RS_232.begin(I2C_RS232_ADDR);

    // Se inicializa el puerto serial a 9600 baudios
    Serial.begin(9600);

    // Se empieza el proceso del cambio de direccion I2C
    RS_232.cambiarI2CAddr(NEW_I2C_RS232_ADDR);

    // Enciar mensajes de información
    Serial.println(" Se ha cambiado la dirección I2C del módulo ");
    Serial.print(" Antigua dirección I2C -> ");
    Serial.println(I2C_RS232_ADDR, HEX);
    Serial.print(" Nueva dirección I2C -> ");
    Serial.println(NEW_I2C_RS232_ADDR, HEX);
}

void loop(){

}