# MentorBitRS232

Librería para el control del módulo de comunicaciones para mMentorBit RS232.

## Descripción

La librería `MentorBitRS232` simplifica el uso y control del módulo MentorBit RS-232. La librería utiliza las librerias necesarias para poder utilizar el I2C y comunicarse con el módulo.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitRS232" e instálala.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitRS232.h>

    // Se define la direccion I2C del módulo
    #define I2C_RS232_ADDR 0x20

    // Se incluye la libreria MentorBitRS232
    MentorBitRS232 RS_232;

    // Se declara el vector del mensaje que se va a enviar
    uint8_t trama[10] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

    void setup() {
      // Se inicializa el módulo RS-232
      RS_232.begin(I2C_RS232_ADDR);

      // Enviar el mensaje
      RS_232.enviarMsg(trama);
    }

    void loop() {
      
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitRS232`: Crea un objeto `MentorBitRS232`.

### Métodos

* `bool begin(uint8_t i2c_addr)`: Inicializa el módulo con la dirección I2C indicada.
* `void cambiarI2CAddr(uint8_t new_i2c_addr)`: Cambiar la dirección I2C del módulo.
* `void apagarLedError()`: Apagar el led de error I2C.
* `void enviarMsg(uint8_t* data)`: Enviar mensaje a través del módulo RS232.
* `void recibirMensaje(uint8_t* data)`: Recibe un mensaje a través del módulo RS232.
* `void mensajesPendientes()`: Solicitar la cantidad de mensajes pendientes en el buffer del módulo.
