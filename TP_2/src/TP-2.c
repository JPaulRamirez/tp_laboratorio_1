/*
 ============================================================================
 Name        : TP-2.c
 Author      : Paul Ramirez Benites
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "Passenger.h"

#define TAM 2000
#define CHAR 50
int main(void)
{
	setbuf(stdout, NULL);
	int contadorId=0;
	int buscarEspacio;
	int auxId;
	int indiceId;
	int opcion;
	int opcionCaseCuatro;
	int orden;
	int ordenDos;
	float auxTotal;
	float auxPromedio;
	int auxSuperanPromedio;
	int bandera=0;

	Passenger arrayPasajeros[TAM];



	if(initPassengers(arrayPasajeros,TAM)==0)
	{
		do
		{
			utn_getNumero(&opcion, "1. ALTAS. \n2. MODIFICAR. \n3. BAJA. \n4. INFORMAR.\n5. SALIR.\nIngrese una opcion: ","\nOpciones invalida\n",1,5,3);
			switch(opcion)
			{
			case 1:
					if(addPassenger(arrayPasajeros, TAM, CHAR,&contadorId)==0 && findEmptyFree(arrayPasajeros, TAM,&buscarEspacio)==0)
					{
						printf("\nLos pasajeros a sido de ALTA!!\n\n");
						bandera=1;
					}
					else
					{
						printf("\nNo que da mas espacio\n\n");
					}
				break;

			case 2:
					if(bandera)
					{
						if(printPassengers(arrayPasajeros, TAM)==0 && utn_getNumero(&auxId, "Que Id de pasajeros queres modificar? : ","\nOpciones invalida\n",0,TAM,5) == 0
						&& findPassengerById(arrayPasajeros, TAM, auxId, &indiceId)==0)
						{

							printPassenger(arrayPasajeros[indiceId]);
							modifyPassenger(&arrayPasajeros[indiceId], CHAR);
							printf("\nLa modificacion del pasajero fue un exito!!\n\n");
						}
						else
						{
							printf("\nError al modificar\n\n");
						}
					}
					else
					{
						printf("\nTe falta ingresar datos, ingrese una alta!!\n\n");
					}

				break;


			case 3:
				if(bandera)
				{
					if(utn_getNumero(&auxId, "Ingrese el id que quieras dar de baja: ","\nOpciones invalida",1,TAM,3)==0)
					{
						findPassengerById(arrayPasajeros,TAM,auxId,&indiceId);
						removePassenger(arrayPasajeros, TAM, indiceId);
					}
					else
					{
						printf("\nError al dar de baja al pasajero\n\n");
					}
				}
				else
				{
					printf("\nNo hay niguna ID de pasajeros, ingrese una alta!!\n\n");
				}

				break;

			case 4:
				if(bandera)
				{
					if(utn_getNumero(&opcionCaseCuatro, "\n1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
																		"\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
																		"\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
																		"\n.Ingrese una opcion: ", "\nError", 1, 3, 3)==0)
					{
						switch(opcionCaseCuatro)
						{
						case 1:
							if(utn_getNumero(&orden, "\n0.(descendente)\n1.(ascendente)\nIngrese una opcion:", "\nError", 0, 1, 3)==0)
							{
								sortPassengers(arrayPasajeros, TAM, orden);
								if(orden==0)
								{
									printf("\nLa lista se ordeno en decendente\n");
								}
								else
								{
									printf("\nLa lista se ordeno en ascendente\n");
								}
								printPassengers(arrayPasajeros, TAM);
							}
							break;

						case 2:
							if(totalPrice(arrayPasajeros, TAM, &auxTotal)==0
								&& PromedioPrice(TAM, auxTotal, &auxPromedio)==0
								&& SuperanPricePromedio(arrayPasajeros, TAM, auxPromedio, &auxSuperanPromedio)==0)
							{
								printf("\nEl total es: %.2f\nEl promedio de precios es: %.2f\nPasajeros que superan promedio: %d\n",auxTotal,auxPromedio,auxSuperanPromedio);
							}
							else
							{
								printf("\nError en los precios\n");
							}
							break;

						case 3:
							if(utn_getNumero(&ordenDos, "\n0.(descendente)\n1.(ascendente)\nIngrese una opcion:", "\nError", 0, 1, 3)==0)
								{
									sortPassengersByCode(arrayPasajeros, TAM, ordenDos);
									if(ordenDos==0)
									{
										printf("\nLa lista se ordeno en decendente\n");
									}
									else
									{
										printf("\nLa lista se ordeno en ascendente\n");
									}
									printActiveFlights(arrayPasajeros, TAM);
								}
							break;

						}

					}
				}
				else
				{
					printf("\nNo se puede informar si no se ingreso ninguna alta!\n");
				}

				break;

			case 5:

				break;
			}

		}while(opcion != 5);
	}

	return EXIT_SUCCESS;
}
