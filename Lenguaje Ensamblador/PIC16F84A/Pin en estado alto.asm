;-------------------------------------------------------------------------------------------
;Autor: Joel Buenrostro
;Fecha: 09/04/2018
;Entorno: MPLAB X IDE v4.15
;Compilador: mpasm (v5.77)
;Descripcion: Codigo que configura el puerto B como salida y activa el pin RB0 en estado 
;alto hasta que se elimine la alimentacion del PIC.
;-------------------------------------------------------------------------------------------
;Dispositivo
		List P=16F84A			;Dispositivo a utilizar
		#include "p16f84a.inc"		;Incluye las librerias
;-------------------------------------------------------------------------------------------
;Bits de configuracion
		__CONFIG _FOSC_XT & _WDTE_OFF & _PWRTE_ON & _CP_OFF
;Oscilador externo, Watchdog apagado, Power up timer encendido, Proteccion de codigo apagado
;-------------------------------------------------------------------------------------------
;Etiquetas	Instruccion	Operando	Comentario
;-------------------------------------------------------------------------------------------
		ORG		0		;Inicia el programa en la direccion 0
INICIO		BSF		STATUS,RP0	;Seleccionamos el banco 1
		CLRF		TRISB		;Configuramos PORTB como salida
		BCF		STATUS,RP0	;Seleccionamos el banco 0
PRINCIPAL	MOVLW		B'00000001'	;Cargamos un numero binario en W
		MOVWF		PORTB		;Movemos lo cargado en W al registro PORTB
		GOTO		PRINCIPAL	;Saltamos a PRINCIPAL
		END				;Termina el programa
