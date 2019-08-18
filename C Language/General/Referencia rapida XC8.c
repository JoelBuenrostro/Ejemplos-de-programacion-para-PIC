//Registros para configurar pines como salidas o como entradas
TRISx                               //Registro TRISx
TRISB=0b00000000;                   //Todos los pines como salida en binario
TRISB=0b11111111;                   //Todos los pines como entrada en binario
TRISB=0;                            //Todos los pines como salida en decimal
TRISB=255;                          //Todos los pines como entrada en decimal
TRISB=0x00                          //Todos los pines como salida en hexadecimal
TRISB=0xff;                         //Todos los pines como entrada en hexadecimal

//Indica si se quiere configurar un solo pin como salida o como entrada
TRISB &=~ (1<<0);                   //RB0 como salida
TRISBbits.TRISB0=0;                 //RB0 como salida
TRISB &=~ (1<<5);                   //RB5 como salida
TRISBbits.TRISB5=0;                 //RB5 como salida
TRISB &=~ ((1<<1)|(1<<4)|(1<<7));   //RB1, RB4 y RB7 como salidas

//Indica si se quiere configurar un solo pin como entrada
TRISB |=(1<<0);                     //RB0 como entrada
TRISBbits.TRISB0=1;                 //RB0 como entrada
TRISB |= (1<<5);                    //RB5 como entrada
TRISBbits.TRISB5=1;                 //RB5 como entrada
TRISB |= ((1<<1)|(1<<4)|(1<<7));    //RB1, RB4 y RB5 como entradas

//Registro para configurar un estado bajo o alto en una pin de salida
PORTx                               //Registro PORTx
PORTB=0b11111111;                   //Pone todos los pines del puerto B en estado alto en binario
PORTB=0b01010101;                   //Pone los pines pares en estado alto
PORTB |= (1<<3);                    //RB3 en estado alto
PORTBbits.RB3=1;                    //RB3 en estado alto
PORTB |= ((1<<2)|(1<<5));           //RB2 y RB5 en estado alto

ADCON1=0x0F;                        //Todos los pines como entrda o salida digital

//Retardos
__delay_ms(tiempo);                 //Reliza pausas en milisegundos
__delay_us(tiempo);                 //Realiza pausas en microsegundos

//Prototipo de funcion main()
int main(void) {				          	//Definir la funcion principal
	while(1)				                	//Bucle infinito
		proceso();		               		//Tareas a realizar
}

//Archivo de cabecera generico
#include <xc.h>				          		//Archivo para accesar a los SFRs

//Direccionamiento absoluto
int scanMode __at(0x200);	        	//Localiza una variable en una direccion de memoria

//Memoria lejana
__far int serialNo;			            //Indica variables o funciones que se localizan en un espacio de memoria "lejana"

//Memoria cercana
__near int serialNo;	          		//Indica variables o funciones que se localizn en un espacio de memoria "cercano"

//Objetos persistentes
__persistent int serialNo;	      	//Indica variables que no deberian ser limpiadas por el runtime

//xdata y ydata
__xdata char data[16];	        		//Indica variables que estan ubicada en regiones de memoria especiales
__ydata char coeffs[4];				

//Objetos en bancos de memoria
__bank(0) char inicio;			        //Incdica variables que se ubican en un banco de memoria en particular

//Alineamiento de objetos
__align(2) int espacio;		        	//Se asegura que la variable comienze en una direccion que es multiplo de 2

//EEPROM
__eeprom int serialNo;		         	//Indica que la variable debe ser posicionada en memoria EEPROM

//Funciones de interrupcion
__interrupt(low_priority) void getData(void) {		//Indica que una funcion actuara como una rutina de servicio de interupcion
	if (TMR0IE && TMR0IF) {
		TRM0IF=0;
		++tick_count;
	}
}

//Objetos en depreciacion
void __deprecate getValue(int mode) {			//Indica una funcion que se pretende eliminar o evitar
	//tareas
}

//Asignar objetos a secciones
int __section("comSec") commonFlag;	      //Indica que el objeto debe ser localizado en la seccion nombrada

//Especificar bits de configuracion
#pragma config WDT=ON, WDTPS=0x1A	        //Directiva usada para definir los bits de configuracion

//MACROS definida por el CCI
__XC__ 					                          //Compilado con XC compiler
__CCI__				                          	//Compilador es compatible con CCI
__XC##__ 				                          //El compilador especifico usado puede ser 8, 16 o 32
__DEVICEFAMILY__			                    //La familia del dispositivo seleccionado
__DEVICENAME__				                    //El nombre del dispositivo seleccionado

//Ensamblador insertado
asm("MOVLW _foobar");		                	//Es usado para insertar codigo ensamblador en una linea de C
