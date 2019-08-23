;-------------------------------------------------------------------------------------------
;File: Pin PORTA.asm
;Author: Joel Buenrostro
;Date: 10/04/2018
;Environment: MPLAB X IDE v4.15
;Compiler: mpasm (v5.77)
;Description: Code that configures port A as output and activates pin RA0 in a high state 
;until the power supply of the PIC is eliminated.
;-------------------------------------------------------------------------------------------
;Device
		List P=16F84A	
		#include "p16f84a.inc"
;-------------------------------------------------------------------------------------------
;Configuration Bits
		__CONFIG _FOSC_XT & _WDTE_OFF & _PWRTE_ON & _CP_OFF
;External oscillator, Watchdog off, Power up timer on, Code protection off
;-------------------------------------------------------------------------------------------
;Label	 Instruction	Operand 	     Comments
;-------------------------------------------------------------------------------------------
		    ORG		    0	         	 ;Start the program at address 0
START       BCF		    STATUS,RP0	     ;We select bank 0
		    CLRF		PORTA		     ;We clean the outputs of port A
		    BSF		    STATUS,RP0	     ;We select the bank 1
		    MOVLW		B'00000000'	     ;We load a binary number in W
	     	MOVWF		TRISA		     ;We configure the entire port as output
		    BCF		    STATUS,RP0	     ;We select bank 0
MAIN    	MOVLW		B'00000001'	     ;We load a binary number in W
		    MOVWF		PORTA		     ;We move what is loaded in W to the PORTA register
		    GOTO		PRINCIPAL	     ;We jump  TO MAIN
		    END				             ;The program ends
