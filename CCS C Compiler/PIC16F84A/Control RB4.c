/******************************************************************************************
*Archivo: Control RB4.c
*Contribuidor: Joel Buenrostro
*Fecha: 05/05/2018
*Dispositivo: PIC16F84A
*Entorno: CCS C Compiler v5.015
*Compilador: PCM Compiler v5.015
*Descripcion: Codigo que configura el pin RB4 como salida y lo activa en estado bajo, 
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
   set_tris_b (0xEF);         //Configuramos RB4 como salida (Binario:11101111)
   DO{
      output_low (PIN_B4);    //Pone RB4 en estado logico bajo
      delay_ms (500);         //Espera 500 milisegundos
      output_high (PIN_B4);   //Pone RB4 en estado logico alto
      delay_ms (500);         //Espera 500 milisegundos
   }WHILE (TRUE);             //Se repite dentro de un bucle infinito
}
