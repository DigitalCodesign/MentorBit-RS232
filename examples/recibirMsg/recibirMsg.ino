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
        Este sketch muestra un ejemplo de recepción de mensajes con el módulo  MentorBit RS-232

*/

// Se incluye la libreria MentorBitRS232
#include <MentorBitRS232.h>

// Se define la direccion I2C del módulo
#define I2C_RS232_ADDR 0x20

// Se crea el objeto RS_232 de la clase MentorBitRS232
MentorBitRS232 RS_232;

// Se crean las variables necesarias
uint8_t cantidadMsg = 0;
uint8_t msg[30];

void setup(){
    // Se inicializa el módulo RS-232
    RS_232.begin(I2C_RS232_ADDR);

    // Se inicializa el puerto serial a 9600 baudios
    Serial.begin(9600);
}

void loop(){
    // Evaluar si hay mensajes disponibles
    cantidadMsg = RS_232.mensajesPendientes();
    if(cantidadMsg > 0){
        RS_232.recibirMensaje(msg);
        Serial.println(" Mensaje recibido: ");
        for(uint8_t i = 0; i < sizeof(msg) ; i++){
            Serial.print(" ");
            Serial.print(msg[i]);
            Serial.print(" ||");
            if( ( i % 5 ) == 4){
                Serial.println("");
            }
        }
    }
}