/****************************************************************************************************************************************
 * Archivo: Pin PORTD.c
 * Contribuidor: Joel Buenrostro
 * Fecha: 15/04/2018
 * Dispositivo: PIC18F4550
 * Entorno: MPLAB X IDE v4.15
 * Compilador: XC8 C Compiler v1.45
 * Descripcion: Codigo que configura RD1 como salida y cambia de estado alto a estado bajo cada segundo
 *
 ***************************************************************************************************************************************/
/****************************************************************************************************************************************
 * Bits de configuracion
 ***************************************************************************************************************************************/
// CONFIG1L
#pragma config PLLDIV = 5       // Bits de selección del preescalador PLL (Divide por 5 (entrada del oscilador de 20 MHz))
#pragma config CPUDIV = OSC1_PLL2// Bits de Selección del Posicionador del Reloj del Sistema ([Oscilador Principal: / 1] [96 MHz PLL Src: / 2])
#pragma config USBDIV = 1       // Bit de selección de reloj USB (solo en modo USB de velocidad completa; UCFG: FSEN = 1) (la fuente del reloj USB viene directamente del bloque del oscilador primario sin escala previa)
// CONFIG1H
#pragma config FOSC = HS        // Bits de selección del oscilador (oscilador HS (HS))
#pragma config FCMEN = OFF      // Bit de habilitación de monitor de reloj a prueba de fallas (Monitor de reloj a prueba de fallas desactivado)
#pragma config IESO = OFF       // Bit de conmutación del oscilador interno / externo (modo de conmutación del oscilador desactivado)
// CONFIG2L
#pragma config PWRT = ON        // Bit de habilitación del temporizador de encendido (PWRT habilitado)
#pragma config BOR = ON         // Habilita los bits Brown-out Reset(Brown-out Reset habilitado solo en hardware (SBOREN está deshabilitado))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (configuración mínima 2.05V)
#pragma config VREGEN = OFF     // Bit de habilitación del regulador de voltaje USB (regulador de voltaje USB desactivado)
// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)
// CONFIG3H
#pragma config CCP2MX = ON      // Bit MUX CCP2 (la entrada / salida CCP2 se multiplexa con RC1)
#pragma config PBADEN = OFF     // Bit de habilitación A / D de PORTB (los pines PORTB <4: 0> se configuran como E / S digital al reiniciar)
#pragma config LPT1OSC = OFF    // Temporizador de baja potencia 1 Bit de habilitación del oscilador (temporizador 1 configurado para una mayor potencia de funcionamiento)
#pragma config MCLRE = ON       // Bit habilitado para pin MCLR (pin MCLR habilitado; pin de entrada RE3 deshabilitado)
// CONFIG4L
#pragma config STVREN = ON      // Stack Full / Underflow(Stack full / underflow causará Reset)
#pragma config LVP = OFF        // Bit habilitado ICSP de una sola fuente (ICSP de una sola fuente deshabilitado)
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
/****************************************************************************************************************************************
 *Librerias y Frecuencia del oscilador
 ***************************************************************************************************************************************/
#include <xc.h>
#include "pic18f4550.h"
#define _XTAL_FREQ 20000000
/***************************************************************************************************************************************/

void main(void) {
    LATD = 0;                   //Limpia el puerto D
    TRISDbits.RD1 = 0;          //Pone el pin RD1 como salida
    
    while(1) {                  //Bucle infinito
        PORTDbits.RD1 = 1;      //Pone el pin RD1 en estado alto
        __delay_ms(1000);       //Espera 1000 milisegundos
        PORTDbits.RD1 = 0;      //Pone el pin RD1 en estado bajo
        __delay_ms(1000);       //Espera 1000 milisegundos
    }
}
