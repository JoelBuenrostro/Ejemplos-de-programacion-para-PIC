//Los compiladores MPLAB® XC ofrecen macros para invocar el modo de suspensión. 
//Aquí se proporciona un ejemplo para cada compilador de C que muestra la función de macro de suspensión para ese compilador.
//Tenga en cuenta que son sensibles a mayúsculas y minúsculas.

/****************************************************************************
* Entrar en modo de Suspensión
* Esta macro emite la instrucción SLEEP para apagar el oscilador del sistema
* e ingresar al modo de operación de baja potencia.
****************************************************************************/

#if defined(__XC8__)
	SLEEP();

#elif defined(__XC16__)
	Sleep();
	//o
	__builtin_pwrsav(0);
	Idle();

	//o
	__builtin_pwrsav(1);

#elif defined(__XC32__)
	//Espera instruccion
	_wait();
#endif
