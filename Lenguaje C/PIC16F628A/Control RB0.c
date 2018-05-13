/*******************************************************************************
 * Archivo: Control RB0.c
 * Contribuidor: Joel Buenrostro
 * Fecha: 05/05/2018
 * Dispositivo: PIC16F628A
 * Entorno: MPLAB X IDE v4.15
 * Compilador: XC8 C Compiler v1.45
 * Descripcion: Configura el purto B como salida y alterna el pin RB0 entre un 
 * estado bajo y un estado alto.
 ******************************************************************************/
/*******************************************************************************
 *Librerias
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
/*******************************************************************************
 * Bits de configuracion
 ******************************************************************************/
#pragma config FOSC = INTOSCIO  // INTOSCIO // Bits de selección del oscilador (oscilador INTOSC: función de E / S en el pin RA6 / OSC2 / CLKOUT, función de E / S en RA7 / OSC1 / CLKIN)
#pragma config WDTE = OFF       // Bit de activación del temporizador de vigilancia (WDT desactivado)
#pragma config PWRTE = OFF      // Bit de habilitación del temporizador de encendido (PWRT habilitado)
#pragma config MCLRE = OFF      // RA5 / MCLR / VPP Pin Seleccionar bit de función (la función de pin RA5 / MCLR / VPP es MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD activado)
#pragma config LVP = OFF        // Bit de habilitación de programación de bajo voltaje (pin RB4 / PGM tiene función de E / S digital, HV en MCLR se debe usar para programación)
#pragma config CPD = OFF        // Bit de protección de código de memoria EE (protección de código de memoria de datos desactivada)
#pragma config CP = OFF         // Flash Program Code Code Bit de protección (protección de código desactivada)
/*******************************************************************************
 *Frecuencia del oscilador
 ******************************************************************************/
#define _XTAL_FREQ 4000000
/******************************************************************************/

void main(void) {
	TRISB = 0b00000000;			//Configura el puerto B como salida

	while (1) {				//Bucle infinito
		PORTBbits.RB0 = 0;		//Pone RB0 en estado bajo
		__delay_ms(500);		//Crea un retardo de 500 milisegundos
		PORTBbits.RB0 = 1;		//Pone RB0 en estado alto
		__delay_ms(500);		//Crea un retardo de 500 milisegundos
	}
    return;
}
