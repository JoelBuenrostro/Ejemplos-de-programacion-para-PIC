;-------------------------------------------------------------------------------------------
;Archivo: Pin PORTA.asm
;Contribuidor: Joel Buenrostro
;Fecha: 10/04/2018
;Entorno: MPLAB X IDE v4.15
;Compilador: mpasm (v5.77)
;Descripcion: Codigo que configura el puerto A como salida y activa el pin RA0 en estado 
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
INICIO		BCF		STATUS,RP0	;Seleccionamos el banco 0
		CLRF		PORTA		;Limpiamos las salidas del puerto A
		BSF		STATUS,RP0	;Seleccionamos el banco 1
		MOVLW		B'00000000'	;Cargamos un numero binario en W
		MOVWF		TRISA		;Configuramos todo el puerto como salida
		BCF		STATUS,RP0	;Seleccionamos el banco 0
PRINCIPAL	MOVLW		B'00000001'	;Cargamos un numero binario en W
		MOVWF		PORTA		;Movemos lo cargado en W al regitro PORTA
		GOTO		PRINCIPAL	;Saltamos  PRINCIPAL
		END				;Termina el programa
