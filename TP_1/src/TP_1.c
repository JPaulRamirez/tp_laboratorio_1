/*
 ============================================================================
 Name        : TP-1.c
 Author      : Paul Ramirez Benites
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"


int main(void)
{
	setbuf(stdout, NULL);
	//Variables generales
	int opcion;
	float km = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int bandera = 0; // La bandera para informar al usuario que faltan cargar datos si bandera=1.
	//Variables de Aeolineas
	float descuentoAerolineas;
	float interesAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;
	//Variables de Latam
	float descuentoLatam;
	float interesLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;

	float diferenciaLatamYAerolineas;
	do
	{
		//system("CLS");
		opcion = pedirOpcion (km,precioAerolineas,precioLatam); // LLamo la fuci�n pedirOpcion

		switch(opcion)
		{
			//system("pause");
			case 1:// Ingresar Kilometros

				km = kilometrosIngresados (km); //LLama la fuci�n kilometros

			break;

			case 2:// Ingresar precio de vuelos

				precioAerolineas = precioAerolineasIngresados(precioAerolineas); //Llama la fuci�n precioAerolineasIngresados

				precioLatam = precioLatamIngresados(precioLatam); //Llama la fuci�n precioLatamIngresados

			break;

			case 3:// Calcular todos los costos

				if(km ==0 || precioAerolineas ==0 || precioLatam ==0)
				{
					printf("\nTe falta ingresar datos.\n\n");
				}
				else
				{
					descuentoAerolineas = descuentoDebito (precioAerolineas);
					interesAerolineas = interesCredito (precioAerolineas);
					bitcoinAerolineas = Bitcoin (precioAerolineas);
					precioUnitarioAerolineas = Unitario (precioAerolineas, km);

					descuentoLatam = descuentoDebito (precioLatam);
					interesLatam = interesCredito (precioLatam);
					bitcoinLatam = Bitcoin (precioLatam);
					precioUnitarioLatam = Unitario (precioLatam, km);

					diferenciaLatamYAerolineas = diferenciaDePrecio(precioAerolineas, precioLatam);

					printf("\nSe han calculado todo los costos.\n\n");
					//bandera1=0;
					bandera=1;
				}

			break;

			case 4:// Informar Resultados
				if(km !=0 && precioAerolineas !=0 && precioLatam !=0)
				{
					if(bandera) //bandera==0
					{
						//LLamo la fuci�n informarResultado.
						informarResultados(km, diferenciaLatamYAerolineas, precioLatam, precioAerolineas, descuentoLatam,interesLatam, bitcoinLatam, precioUnitarioLatam, descuentoAerolineas, interesAerolineas, bitcoinAerolineas, precioUnitarioAerolineas);

						//Igualo a 0 para que el usuario cuando ingrese otro dato nuevo, tendra que reiniciar con la opcion 3 para que los anteriores datos del case3 :informar resultados, no queden guardadas .
						bandera=0;
					}
					else
					{
						printf("\nTe falta calcular los datos (opcion 3).\n\n");
					}
				}
				else
				{
					printf("\nTe falta ingresar datos.\n\n");
				}
			break;

			case 5:// Carga forzada

				km = 7090;
				precioAerolineas = 162965;
				precioLatam = 159339;

				// Llamo la funci�n cargaForzada.
				cargaForzada(km,precioAerolineas,precioLatam);

				//Reinicio las variables de nuevo a 0 y no queden guardadas en las opciones de (x,y,z).

					km = 0;
					precioAerolineas = 0;
					precioLatam = 0;
			break;

			case 6:// Salir
			break;

			default:
				printf("\nOpci�n incorrecta.\n\n");
				break;
		}

	}while(opcion!=6 );

	return 0;
}
