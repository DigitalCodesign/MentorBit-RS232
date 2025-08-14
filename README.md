# MentorBit-RS232

Esta librería está diseñada para que puedas recibir y procesar fácilmente datos desde un dispositivo que se comunica mediante el protocolo **RS-232**, a través de un módulo que reenvía esa información a tu placa MentorBit mediante el **protocolo I2C**.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del MentorBit módulo RS-232.](https://github.com/DigitalCodesign/MentorBit-RS232/blob/main/assets/Modulo_RS232.png)

Este módulo es ideal para recibir comandos o mensajes desde otros dispositivos industriales, sensores avanzados o controladores que usan comunicación **RS-232**, y reenviarlos al microcontrolador MentorBit usando **I2C**.

---

## Descripción

### ¿Qué es el módulo RS-232 para MentorBit?

Este módulo permite que dispositivos que se comunican mediante **RS-232** puedan enviar mensajes a MentorBit.  
El módulo se encarga de convertir esos mensajes y reenviarlos por I2C al microcontrolador.  
Además, incorpora un **buffer de recepción** para almacenar los mensajes temporalmente hasta que el microcontrolador los lea.

---

### ¿Qué hace esta librería?

La librería **MentorBit-RS232** permite:

- Inicializar la comunicación con el módulo vía I2C.
- Leer mensajes almacenados en el buffer.
- Consultar el número de bytes disponibles.

---

### ¿Qué puedes construir con este módulo?

- Puentes de comunicación entre equipos industriales RS-232 y sistemas educativos MentorBit.
- Interfaces de control serial remoto.
- Proyectos de captura y análisis de datos RS-232.
- Emuladores de terminal con recepción I2C.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el **módulo RS-232** a uno de los **puertos I2C** de la placa MentorBit utilizando el conector JST de 4 pines.  
La conexión RS-232 debe realizarse con el dispositivo externo emisor de los datos.

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-RS232*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-RS232/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Leer datos recibidos

Este ejemplo lee los datos almacenados en el buffer RS-232 y los imprime por el monitor serie.

```cpp
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
```

---

## Funciones Principales

- `void begin(uint8_t i2c_addr)`  
  Inicializa el módulo RS-232 para su posterior uso.

- `void cambiarI2CAddr(uint8_t new_i2c_addr)`  
  Cambia la dirección I2C del módulo.

- `void apagarLedError()`  
  Apaga el led de error I2C del módulo.

- `void enviarMsg(uint8_t* data, uint8_t size)`  
  Envia un determinado mensaje por el RS-232.

- `void recibirMensaje(uint8_t* data)`  
  Lee el mensaje almacenado en el buffer (recibido por el protocolo RS-232).

- `uint8_t mensajesPendientes()`  
  obtiene el valor de mensajes que hay en el buffer.

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo RS-232](https://digitalcodesign.com/shop/00040042-mentorbit-modulo-rs-232-8735#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/1xpJSe1OL8msftRP943SXIG-nVAUvhp-H/view?usp=drive_link)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/file/d/1uGK_XR2OkaDOtXhkT3JDV2ZrHZpmPziB/view?usp=drive_link)
