/******************************************************************************************
*File: Control RB0.c
*Author: Joel Buenrostro
*Date: 15/04/2018
*Device: PIC16F84A
*Environment: CCS C Compiler v5.015
*Compiler: PCM Compiler v5.015
*Description: Code that configures pin RB0 as output and activates it in low state,
* wait 500 milliseconds and switch to high state and wait 500 milliseconds again
******************************************************************************************/
#include <16f84a.h>
/******************************************************************************************
*Configuration Bits
******************************************************************************************/
#fuses XT, NOWDT, PUT, NOPROTECT
/******************************************************************************************
*Frecuency and Ports configuration
******************************************************************************************/
#use delay(clock = 4000000)
/*****************************************************************************************/

void main(VOID)
{
   set_tris_b(0xFE); //Configure RB0 to be an output (Binary:11111110)
   DO
   {
      output_low(PIN_B0);  //Set RB0 in low logic state
      delay_ms(500);       //Wait 500 miliseconds
      output_high(PIN_B0); //Set RB0 in high logic state
      delay_ms(500);       //Wait 500 miliseconds
   }
   WHILE(TRUE); //Infinite loop
}
