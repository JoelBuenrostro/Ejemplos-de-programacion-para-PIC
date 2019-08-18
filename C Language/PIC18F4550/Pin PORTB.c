/**************************************************************************************************************************************************************************************************************************
 * Archivo: Pin PORTB.c
 * Contribuidor: Joel Buenrostro
 * Fecha: 15/04/2018
 * Dispositivo: PIC18F4550
 * Entorno: MPLAB X IDE v4.15
 * Compilador: XC8 C Compiler v1.45
 * Descripcion: Configura el puerto B como salida y enciende y apaga LED conectados al mismo puerto (RB0-RB7)
 *
 *************************************************************************************************************************************************************************************************************************/
/**************************************************************************************************************************************************************************************************************************
 * Bits de configuracion
 *************************************************************************************************************************************************************************************************************************/
// CONFIG1L
#pragma config PLLDIV = 1       // Bits de selección del preescalador PLL (sin preescala (la entrada del oscilador de 4 MHz impulsa el PLL directamente))
#pragma config CPUDIV = OSC1_PLL2// Bits de Selección del Posicionador del Reloj del Sistema ([Oscilador Principal: / 1] [96 MHz PLL Src: / 2])
#pragma config USBDIV = 1       // Bit de selección de reloj USB (solo en modo USB de velocidad completa; UCFG: FSEN = 1) (la fuente del reloj USB viene directamente del bloque del oscilador primario sin escala previa)
// CONFIG1H
#pragma config FOSC = INTOSC_EC // Bits de selección del oscilador (oscilador interno, función CLKO en RA6, EC utilizado por USB (INTCKO))
#pragma config FCMEN = OFF      // Bit de habilitación de monitor de reloj a prueba de fallas (Monitor de reloj a prueba de fallas desactivado)
#pragma config IESO = OFF       // Bit de conmutación del oscilador interno / externo (modo de conmutación del oscilador desactivado)
// CONFIG2L
#pragma config PWRT = ON        // Bit de habilitación del temporizador de encendido (PWRT habilitado)
#pragma config BOR = ON         // Habilita los bits Brown-out Reset(Brown-out Reset habilitado solo en hardware (SBOREN está deshabilitado))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (configuración mínima 2.05V)
#pragma config VREGEN = OFF     // Bit de habilitación del regulador de voltaje USB (regulador de voltaje USB desactivado)
// CONFIG2H
#pragma config WDT = OFF        // Bit de habilitación del temporizador de vigilancia (WDT desactivado (el control se coloca en el bit SWDTEN))
#pragma config WDTPS = 32768    // Cronometro de reloj de vigilancia(1: 32768)
// CONFIG3H
#pragma config CCP2MX = ON      // Bit MUX CCP2 (la entrada / salida CCP2 se multiplexa con RC1)
#pragma config PBADEN = OFF     // Bit de habilitación A / D de PORTB (los pines PORTB <4: 0> se configuran como E / S digital al reiniciar)
#pragma config LPT1OSC = OFF    // Temporizador de baja potencia 1 Bit de habilitación del oscilador (temporizador 1 configurado para una mayor potencia de funcionamiento)
#pragma config MCLRE = ON       // Bit habilitado para pin MCLR (pin MCLR habilitado; pin de entrada RE3 deshabilitado)
// CONFIG4L
#pragma config STVREN = ON      // Stack Full / Underflow (Stack full / underflow causará Reset)
#pragma config LVP = ON         // Bit de habilitación del ICSP de una sola fuente (ICSP de suministro único habilitado)
#pragma config ICPRT = OFF      // Bit dedicado habilitado para la depuración / puerto de programación (ICPORT) (ICPORT desactivado)
#pragma config XINST = OFF      // Juego de instrucción extendido (extensión del conjunto de instrucciones y modo de direccionamiento indexado deshabilitado (modo Legacy))
// CONFIG5L
#pragma config CP0 = OFF        // Bit de protección de código (Bloque 0 (000800-001FFFh) no está protegido por código)
#pragma config CP1 = OFF        // Bit de protección de código (Bloque 1 (002000-003FFFh) no está protegido por código)
#pragma config CP2 = OFF        // Bit de protección de código (Bloque 2 (004000-005FFFh) no está protegido por código)
#pragma config CP3 = OFF        // Bit de protección de código (Bloque 3 (006000-007FFFh) no está protegido por código)
// CONFIG5H
#pragma config CPB = OFF        // Bit de protección del código del bloque de arranque (el bloque de arranque (000000-0007FFh) no está protegido por código)
#pragma config CPD = OFF        // Bit de protección de código EEPROM de datos (EEPROM de datos no está protegido por código)
// CONFIG6L
#pragma config WRT0 = OFF       // Bit de Protección de escritura (Bloque 0 (000800-001FFFh) no está protegido contra escritura)
#pragma config WRT1 = OFF       // Bit de Protección de escritura (Bloque 1 (002000-003FFFh) no está protegido contra escritura)
#pragma config WRT2 = OFF       // Bit de Protección de escritura (Bloque 2 (004000-005FFFh) no está protegido contra escritura)
#pragma config WRT3 = OFF       // Bit de Protección de escritura (Bloque 3 (006000-007FFFh) no está protegido contra escritura)
// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Bit de protección de escritura del bloque de arranque (el bloque de arranque (000000-0007FFh) no está protegido contra escritura)
#pragma config WRTD = OFF       // Bit de protección de escritura de EEPROM de datos (EEPROM de datos no está protegido contra escritura)
// CONFIG7L
#pragma config EBTR0 = OFF      // Bit de Protección de lectura de tabla (Bloque 0 (000800-001FFFh) no está protegido de las lecturas de tabla ejecutadas en otros bloques)
#pragma config EBTR1 = OFF      // Bit de Protección de lectura de tabla (Bloque 1 (002000-003FFFh) no está protegido de las lecturas de tabla ejecutadas en otros bloques)
#pragma config EBTR2 = OFF      // Bit de Protección de lectura de tabla (Bloque 2 (004000-005FFFh) no está protegido de las lecturas de tabla ejecutadas en otros bloques)
#pragma config EBTR3 = OFF      // Bit de Protección de lectura de tabla (Bloque 3 (006000-007FFFh) no está protegido de las lecturas de tabla ejecutadas en otros bloques)
// CONFIG7H
#pragma config EBTRB = OFF      // Bloquear Lectura de tabla (Boot block (000000-0007FFh) no está protegido de lecturas de tabla ejecutadas en otros bloques)
/*************************************************************************************************************************************************************************************************************************
 *Librerias y Frecuencia del oscilador
 ************************************************************************************************************************************************************************************************************************/
#include <xc.h>
#include <pic18f4550.h>
/************************************************************************************************************************************************************************************************************************/

void MSdelay(unsigned int);

void main(void) {
    OSCCON = 0x72;                      //Usa el oscilador interno a 8MHz
    TRISB = 0x00;                       //Configura PORTB como salida
    while (1) {                         //Bucle infinito
        LATB = 0xFF;                    //Enciende LED
        MSdelay(500);                   //Espera 500 milisegundos
        LATB = 0x00;                    //Apaga LED
        MSdelay(500);                   //Espera 500 milisegundos
    }
}

void MSdelay(unsigned int val) {        //Esta subrutina provee un retardo de 1 ms para una frecuencia de 8MHz
    unsigned int i, j;
    for (i=0; i<val; i++)
        for (j=0; j<165; j++);
}
