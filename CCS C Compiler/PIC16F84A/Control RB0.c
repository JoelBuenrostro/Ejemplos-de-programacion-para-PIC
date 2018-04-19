/******************************************************************************************
*Archivo: Control RB0.c
*Contribuidor: Joel Buenrostro
*Fecha: 15/04/2018
*Dispositivo: PIC16F84A
*Entorno: CCS C Compiler v5.015
*Compilador: PCM Compiler v5.015
*Descripcion: Codigo que configura el pin RB0 como salida y lo activa en estado bajo, 
*espera 500 milisegundos y cambia a estado alto y espera 500 milisegundos nuevamente
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
   set_tris_b (0xFE);         //Configuramos RB0 como salida (Binario:11111110)
   DO{
      output_low (PIN_B0);    //Pone RB0 en estado logico bajo
      delay_ms (500);         //Espera 500 milisegundos
      output_high (PIN_B0);   //Pone RB0 en estado logico alto
      delay_ms (500);         //Espera 500 milisegundos
   }WHILE (TRUE);             //Se repite dentro de un bucle infinito
}