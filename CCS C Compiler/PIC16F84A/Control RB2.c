/******************************************************************************
*Archivo:Activar RB2
*Contribuidor: Joel Buenrostro
*Fecha: 19/04/2018
*Dispositivo: PIC16F84A
*Entorno: CCS C Compiler v5.015
*Compilador: PCM C Compiler v5.015
*Descripcion: Codigo que configura el pin RB2 como salida y lo activa en estado
*alto hasta que se elimine la alimentacion del PIC
******************************************************************************/
#include <16f84a.h>
/******************************************************************************
*Bits de configuracion
******************************************************************************/
#fuses XT,NOWDT,PUT,NOPROTECT
/******************************************************************************
*Frecuencia de oscilador y configuracion de puertos
******************************************************************************/
#use delay (clock= 4000000)
/*****************************************************************************/

void main(VOID) {
   set_tris_b (0xFB);         //Configuramos RB0 como salida (Binario:11111011)
   DO{
      output_low (PIN_B2);    //Pone RB0 en estado logico bajo
      delay_ms (500);         //Espera 500 milisegundos
      output_high (PIN_B2);   //Pone RB0 en estado logico alto
      delay_ms (500);         //Espera 500 milisegundos
   }WHILE (TRUE);             //Se repite dentro de un bucle infinito
}
