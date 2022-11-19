/*
 * Passenger.c
 *
 *  Created on: 8 jun. 2022
 *      Author: Compumar
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"
#include "Passenger.h"

//inicio
int initPassengers(Passenger *list , int limite)
{
	int retorno=-1;

	if(list!=NULL && limite>0)
	{
		for(int i=0; i<limite; i++)
		{
			list[i].isEmpaty=1;// 1 LIBRE // 0 Ocupado

		}
		retorno=0;
	}
	return retorno;
}
//Buscar espacio libre
int findEmptyFree(Passenger *list,int limite, int *espacioLibre)
{
	int retorno=-1;

	if(list!=NULL && limite>0)
	{
		for(int i=0; i<limite;i++)
		{
			if(list[i].isEmpaty==1)
			{
				*espacioLibre=i;

				retorno=0;
			}
		}
	}
	return retorno;
}
//ALTAS
int addPassenger(Passenger*list,int tamanio,int tamanioChar,int* contadorId)
{
	int retorno=-1;
	int i;


	if(list!= NULL && tamanio>0 && tamanioChar>0 && contadorId!= NULL)
	{

		for(i=0; i<tamanio; i++)
		{

	     	if((list[i]).isEmpaty == 1)
			{

	     		utn_getNombre(list[i].name, tamanioChar, "\nIngrese el nombre:", "\nError al ingresar el nombre.", 3 );


	     		utn_getNombre(list[i].lastname, tamanioChar, "\nIngrese el apellido:", "\nError al el apellido.", 3 );


	     		getNumeroFlotante(&list[i].price, "\nIngrese el precio del vuelo: ", "\nError al ingresar el precio.", 0.0, 50000.0, 3);


				utn_getNumero(&list[i].typePassenger, "\nIngrese el tipo de pasajero: (1-Menor,2-Adulto,3-Tercera edad):", "\nError al ingresar el tipo de pasajero(1-Menor,2-Adulto,3-Tercera edad)", 1, 3, 3);


				utn_getNumero(&list[i].statusFlight, "\nIngrese el estado del vuelo (1-Cancelado,2-Activo,3-Demorado)", "\nError al ingresar el estado del vuelo(1-Cancelado,2-Activo,3-Demorado)", 1, 3, 3);

				getAlfanumerico(list[i].flycode, "\nIngrese el codigo de vuelo: ", "\nError al ingresar el codigo de vuelo.", tamanioChar, 3);
				//utn_getNumero(&list[i].flycode, "\nIngrese el codigo de vuelo: ", "\nError al ingresar el codigo de vuelo.", minimo, maximo, reintentos);
				fflush(stdin);


				*contadorId= 1+ *contadorId;
				list[i].id = *contadorId;
				list[i].isEmpaty = 0;


				break;
			}

		}
		retorno=0;
	}
	return retorno;
}

int modifyPassenger(Passenger *list,int tamanioChar)
{
	int retorno=-1;
	int opciones;

		printf("	****Modificar pasajero****   \n");

	do
	{
		if(!utn_getNumero(&opciones,"1. Nombre. \n2. Apellido. \n3. Precio. \n4. Tipo de pasajero.\n5. Estado de vuelo.\n6. Codigo de vuelo.\n7. Salir\nIngrese una opcion: ","\nOpciones invalida\n", 1, 7, 3))
		{
			switch(opciones)
			{
				case 1:
					if(utn_getNombre(list->name, tamanioChar, "\nIngrese el nombre:", "\nError al ingresar el nombre.", 3 )==0)
					{
						printf("\nLa modificacion del nombre fue exitosa\n");
					}
					else
					{
						printf("ERROR NOMBRE");
					}

					break;
				case 2:
					if(utn_getNombre(list->lastname, tamanioChar, "\nIngrese el apellido:", "\nError al el apellido.", 3 )==0)
					{
						printf("\nLa modificacion del apellido fue exitosa\n");
					}
					break;
				case 3:
					if(getNumeroFlotante(&list->price, "\nIngrese el precio del vuelo: ", "\nError al ingresar el precio.", 0.0, 50000.0, 3)==0)
					{
						printf("\nLa modificacion del precio fue exitosa\n");
					}
					break;
				case 4:
					if(utn_getNumero(&list->typePassenger, "\nIngrese el tipo de pasajero: (1-Menor,2-Adulto,3-Tercera edad):", "\nError al ingresar el tipo de pasajero(1-Menor,2-Adulto,3-Tercera edad)", 1, 3, 3)==0)
					{
						printf("\nLa modificacion del tipo pasajero fue exitosa\n");
					}
					break;
				case 5:
					if(utn_getNumero(&list->statusFlight, "\nIngrese el estado del vuelo (1-Cancelado,2-Activo,3-Demorado)", "\nError al ingresar el estado del vuelo(1-Cancelado,2-Activo,3-Demorado)", 1, 3, 3)==0)
					{
						printf("\nLa modificacion del estado de vuelo fue exitosa\n");
					}
					break;
				case 6:
					if(getAlfanumerico(list->flycode, "\nIngrese el codigo de vuelo: ", "\nError al ingresar el codigo de vuelo.", tamanioChar, 3)==0)
					{
						printf("\nLa modificacion del codigo fue exitosa\n");
					}
					break;
			}
			retorno=0;
		}
	}while(opciones!=7);

	return retorno;
}

//Borrar
int removePassenger(Passenger *list, int limite, int id)
{

	int retorno=-1;
	if(list != NULL && limite > 0 && id >= 0)
	{
		if(list[id].isEmpaty==0)
		{
			list[id].isEmpaty=1;
			printf("\nEmpleado elimincado correctamente\n");
			retorno=0;
		}
		else if(list[id].isEmpaty==1)
		{
			printf("\nEn este id no hay registrado ningun pasajero\n");
			retorno=-1;
		}
	}
	return retorno;

}

//BuscarId
int findPassengerById(Passenger *list,int limite,int id,int *indice)
{
	int retorno=-1;

	if(list != NULL && limite > 0 )
	{
		for(int i=0; i<limite; i++)
		{
			if(list[i].id == id && list[i].isEmpaty==0)
			{
				*indice=i;
				retorno=0;
				break;
			}

		}

	}
	return retorno;
}

//Imprimir Pasajeros
//Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
//descendente.
int printPassengers(Passenger *list , int limite)
{
	int retorno=-1;
	if(list != NULL && limite > 0)
	{
		printf("\n 				  **LISTADO EMPLEADOS** \n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO		TIPO PASAJERO 		ESTADO \n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		for(int i=0; i<limite; i++)
		{

			if(list[i].isEmpaty==0)
			{
				printPassenger(list[i]);
			}

		}
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		retorno=0;
	}
	return retorno;

}
void printPassenger(Passenger list)
{
	eTypePassenger auxTypePassenger[3]={{"Menor",1},{"Adulto",2},{"Tercera edad",3}};
	eEstatusFlight auxEstatusFlight[3]={{"Cancelado",1},{"Activo",2},{"Demorado",3}};
	int i;
	int j;

	for(i=0;i<3;i++)
	{
		if(list.typePassenger == auxTypePassenger[i].idTypePassenger)
		{
			break;
		}
	}
	for(j=0;j<3;j++)
	{
		if(list.statusFlight == auxEstatusFlight[j].idStatusFlight)
		{
			break;
		}
	}

	printf("\n%d	 	%s		 %s     		  %.2f	  	 %s    	 %s  		 %s \n",
			list.id, list.name, list.lastname, list.price,list.flycode, auxTypePassenger[i].description,auxEstatusFlight[j].description);

}

//Ordenar Pasajeros
int sortPassengers(Passenger *list,int tamanio,int order)
{
	int retorno=-1;

	Passenger auxPassenger;
	if(list!=NULL && tamanio>0)
	{
        for (int i = 0; i < tamanio -1; i++)
        {
            for (int j = i+1; j < tamanio; j++)
            {
            	if(order==0)//decreciente apellido Y tipo de pasajero
            	{
            		if((strcmp(list[i].lastname,list[j].lastname)<0)||
            		((strcmp(list[i].lastname,list[j].lastname)==0)&&(list[i].typePassenger<list[j].typePassenger)))
            		{
						 auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
					}
            	}
            	else// 1 creciente
            	{
            		if((strcmp(list[i].lastname,list[j].lastname)>0)||
					((strcmp(list[i].lastname,list[j].lastname)==0)&&(list[i].typePassenger>list[j].typePassenger)))
					{
						 auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
					}
            	}
            }
        }
        retorno=1;
	}
	return retorno;
}
int totalPrice(Passenger* list, int tamanio, float*total)
{
	int retorno=-1;
	float acumulador=0;
	if(list!=NULL && tamanio>0 && total!=NULL)
	{
		for(int i=0;i<tamanio;i++)
		{
			acumulador = acumulador + list[i].price;
		}

		*total=acumulador;

		retorno=0;
	}

	return retorno;
}

int PromedioPrice(int tamanio, float total, float*promedio)
{
	int retorno=-1;
	if(promedio!=NULL && tamanio>0 && total>0)
	{
		*promedio=total/tamanio;

		retorno=0;
	}
	return retorno;
}
int SuperanPricePromedio(Passenger* list, int tamanio, float promedio, int*acumuladorPrice)
{
	int retorno=-1;
	int aux=0;

	if(list!=NULL && tamanio>0 && acumuladorPrice!=NULL)
	{
		for(int i=0;i<tamanio;i++)
		{
			if(list[i].price > promedio)
			{
				aux++;
			}
			*acumuladorPrice=aux;
		}
		retorno=0;
	}
	return retorno;
}


//Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o
//descendente.
int sortPassengersByCode(Passenger* list, int tamanio, int order)
{
	int retorno=-1;

	Passenger auxPassenger;


	if(list!=NULL && tamanio>0)
	{
        for (int i = 0; i < tamanio -1; i++)
        {
            for (int j = i+1; j < tamanio; j++)
            {

            	if(order==0)
            	{
            		if((strcmp(list[i].flycode,list[j].flycode)<0)||
            		((strcmp(list[i].flycode,list[j].flycode)==0)&&(list[i].statusFlight<list[j].statusFlight)))
            		{
						 auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
					}
            		//printActiveFlights(list,tamanio);
            	}
            	else
            	{
            		if((strcmp(list[i].flycode,list[j].flycode)>0)||
					((strcmp(list[i].flycode,list[j].flycode)==0)&&(list[i].statusFlight>list[j].statusFlight)))
					{
						auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
					}
            	}
            }
        }
        retorno=0;
	}

	return retorno;
}
int printActiveFlights(Passenger* list, int tamanio)
{
	int retorno = -1;
	int flag = 1;
	if (list != NULL && list > 0)
	{
		printf("                     ***Lista de Pasajeros ***\n");
		printf("-----------------------------------------------------------------------------------------\n");
		printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO		TIPO PASAJERO 		ESTADO \n");
		printf("-----------------------------------------------------------------------------------------\n");
		for (int i = 0; i < tamanio; i++)
		{
			if (!list[i].isEmpaty && list[i].statusFlight==2)
			{
				printPassenger(list[i]);
				flag = 0;
			}
		}
		if (flag)
		{
			printf("No hay pasajeros para vuelos.\n");
		}
		retorno = 0;
	}
	printf("\n");
	return retorno;
}

