/*
 * UTN.h
 *
 *  Created on: 8 jun. 2022
 *      Author: Compumar
 */

#ifndef UTN_H_
#define UTN_H_
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int getInt(int* pResultado);
int esNumerica(char* cadena, int limite);
int myGets(char* cadena, int longitud);
int utn_getNombre(char array[], int tamanio, char* mensaje, char* mensajeError, int reintentos );
int getNombre (char pResultado[], int tamanio);
int esNombre (char array [], int tamanio);
int getNumeroFlotante(float* pResultado, char mensaje[], char errorMensaje[], float minimo, float maximo, int reintentos);
int getFloat(float* pResultado);
int esFlotante(char* cadena,int limite);
int getAlfanumerico(char inPut[],char mensaje[], char errorMensaje[],int tamano, int reintentos);


#endif /* UTN_H_ */
