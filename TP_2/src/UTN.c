/*
 * UTN.c
 *
 *  Created on: 8 jun. 2022
 *      Author: Compumar
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"


int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int aux; //lo guarda


	if(pResultado != NULL && mensaje !=NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do{
			printf("%s",mensaje);
			if(getInt(&aux)==0 && (aux >= minimo && aux <= maximo))
			{
				*pResultado = aux;
				retorno=0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;

		}while(reintentos>=0);

	}
	return retorno;
}
int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer,sizeof(buffer))) //verifica si son numeros
	{
		retorno = 0;
		*pResultado = atoi(buffer); //los transforma
	}

	return retorno;
}
int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}
int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];
	if(cadena != NULL && longitud>0)
	{
	    fflush(stdin);
	    if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
	    {
	        if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
	        {
	           bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
			}
	        if(strnlen(bufferString,sizeof(bufferString))<=longitud)
	        {
			   strncpy(cadena, bufferString, longitud);
			   retorno=0;
			}
	    }
	}
	return retorno;
}

int utn_getNombre(char array[], int tamanio, char* mensaje, char* mensajeError, int reintentos )
{
	int retorno = -1;
	char buffer [tamanio];

	if (array != NULL && tamanio >0 &&  mensaje != NULL &&  mensajeError != NULL && reintentos>= 0){

		do{
			printf ("%s", mensaje);
			if (getNombre(buffer, tamanio) == 0){

				retorno = 0;
				strcpy(array,buffer);

				break;

				}
			else{
				printf ("%s", mensajeError);
				reintentos --;
			}

			}while(reintentos >= 0);

	}

	return retorno;
}

int getNombre (char pResultado[], int tamanio)
	{
		int retorno = -1;
		char buffer[tamanio];

		if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
				&& esNombre(buffer,sizeof(buffer))>0) // osea si se cumple la fx y me devuelve un verdadero
				{
					strcpy(pResultado,buffer);
					retorno = 0;
				}
		return retorno;
	}

int esNombre (char array [], int tamanio)
	{
		int retorno = -1;
		int i;

		if (array != NULL && tamanio > 0){

			for(i=0;i<tamanio && array[i] != '\0';i++)
			{

				array [i] = tolower (array [i]); // pasa el array a minusculas

				retorno = 1;

				if (array [i] < 'a' || array [i] > 'z'){

					retorno = 0; // ERROR
					break;
				} // FIN DEL IF
			} // FIN DEL FOR
		} // FIN VALIDACION

		return retorno;
	}

int getNumeroFlotante(float* pResultado, char mensaje[], char errorMensaje[], float minimo, float maximo, int reintentos)
 {
	 int retorno = -1;
	 float bufferFloat;

	 	do{
	 		printf("%s",mensaje);

	 		if(getFloat (&bufferFloat)==0 &&
	 		   bufferFloat >= minimo &&
	 		   bufferFloat <= maximo)
	 		{
	 			retorno = 0;
	 			*pResultado=bufferFloat;
	 			break;
	 		}
	 		printf("%s",  errorMensaje);
	 		reintentos--;
	 	}while(reintentos>=0);


	 	return retorno;
 }
int getFloat(float* pResultado)
 {
     int retorno=-1;
     char bufferString[50];

    if(pResultado != NULL &&
 	myGets(bufferString,sizeof(bufferString)) == 0 &&
 	esFlotante(bufferString,sizeof(bufferString)))
    {
		retorno=0;
		*pResultado = atof(bufferString) ;
    }

 	return retorno;

 }
int esFlotante(char* cadena,int limite)
{
	int retorno = 1;
	int flagDecimal=1;

	int i;
	if(cadena != NULL && limite>0)
	{
		for(i=0; i < limite && cadena[i] != '\0';i++)
		{
			if(i== 0 && (cadena[i]== '+' || cadena[i]=='-'))
			{
				continue;
			}
			if(flagDecimal==1 && i !=0 && cadena[i]=='.')
			{
				flagDecimal=0;
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int getAlfanumerico(char inPut[],char mensaje[], char errorMensaje[],int tamano, int reintentos)
 {
 	//decalro variables
 	char bufferChar[tamano];
 	int retorno;

 	//valido
 	if(inPut != NULL && mensaje != NULL && errorMensaje != NULL && tamano >= 1 && reintentos >= 0 )
 	{
		//creo bucle que se repita si reintentos>= 0 y retorno ==0
 		do{
 			 retorno = 0;
 			 //pido el ingreso de datos
 			 printf("\n %s",mensaje);
 			 fflush(stdin);
 		 	 gets(bufferChar);
 		 	 	 	 	 	 	 	 	 	 	 	 	 // printf("%d",strlen(bufferChar));
 		 	 //valido que lo ingresado no exceda
 			 if(strlen(bufferChar)<=tamano)
 			 {
 				 //recorro arrray
 				 for(int i=0;i<strlen(bufferChar);i++) //while(i<=strlen(bufferChar))
 				 {
 					 //niego alfanumerico
 					if(!isalnum(bufferChar[i]))
 					{
 						printf("\n %s",errorMensaje);
 						retorno = -1;
 						break;
 					}
 				 }
 				// printf("su contrsena es %s",bufferChar);
 			 }
 			 else
 			 {
 				 retorno = -1;
 			 }

 			 reintentos--;

 		 }while(reintentos>=0 && retorno==-1);

 		 if(retorno == 0)
 		 {
 			 strcpy(inPut,bufferChar);
 			//inPut = bufferChar;
 		 }
 	 }
 	return	retorno;
 }

