/******************************************************************************************
*File: Control RB0.c
*Author: Joel Buenrostro
*Date: 15/04/2018
*Device: PIC16F84A
*Environment: CCS C Compiler v5.015
*Compiler: PCM Compiler v5.015
*Descripcion: Codigo que configura el pin RB1 como salida y lo activa en estado bajo, 
*espera 500 milisegundos y cambia a estado alto y espera 500 milisegundos nuevamente.
******************************************************************************************/
#include <16f84a.h>
/******************************************************************************************
*Bits de configuracion
******************************************************************************************/
#fuses XT,NOWDT,PUT,NOPROTECT
/******************************************************************************************
*Frecuencia de oscilador y configuracion de puertos
******************************************************************************************/
#use delay (clock= 4000000)
/*****************************************************************************************/

void main(VOID) {
   set_tris_b (0xFD);         //Configuramos RB1 como salida (Binario:11111101)
   DO{
      output_low (PIN_B1);    //Pone RB1 en estado logico bajo
      delay_ms (500);         //Espera 500 milisegundos
      output_high (PIN_B1);   //Pone RB1 en estado logico alto
      delay_ms (500);         //Espera 500 milisegundos
   }WHILE (TRUE);             //Se repite dentro de un bucle infinito
}
