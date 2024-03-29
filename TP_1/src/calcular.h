/*
 * calcular.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Paul Ramirez Benites
 */

#ifndef CALCULAR_H_
#define CALCULAR_H_
/**
 * @brief Esta funcion valida enteros.
 * @param *numero Recibe la dirrecion de memoria de una variable tipo int.
 * @param min Recibe un minimo de una variable de tipo int.
 * @param max Recibe un maximo de una variable de tipo int.
 */

void pedirNumeroEntero(int *numero, int min, int max);

/**
 * @brief Esta funcion se ingresa una opcion.
 * @param km Recibe el float que corresponde a los kilometros ingresados.
 * @param precioAerolineas Recibe el float que corresponde los datos de Aerolineas ingresados.
 * @param precioLatam Recibe el float que corresponde los datos de Latam ingresados.
 * @return Devuelve el valor del opcion correspondiente de 1 a 6.
 */
int pedirOpcion(float km, float precioAerolineas, float precioLatam);

/**
 * @brief Esta fuci�n se ingresa los kilometros.
 * @param kilometros Recibe el float que corresponde a los kilometros ingresados.
 * @return Devuelve los kilometros ingresados.
 */
float kilometrosIngresados(float kilometros);
/**
 * @brief Esta funci�n se ingresa los precios de Aerolineas ingresados.
 * @param precioAerolineas Recibe el float que corresponde los datos de Aerolineas ingresados.
 * @return Devuelve el valor correctamente de los precios ingresados de Aerolineas.
 */
float precioAerolineasIngresados(float precioAerolineas);
/**
 * @brief Esta funci�n se ingresa los precios de Latam ingresados.
 * @param precioLatam Recibe el float que corresponde los datos de Latam ingresados.
 * @return Devuelve el valor correctamente de los precios ingresados de Latam.
 */
float precioLatamIngresados(float precioLatam);

/**
 * @brief Esta funci�n informa los resultados de Aerolineas y de Latam.
 * @param km  Recibe una variable tipo float que se va mostrar.
 * @param diferenciaLatamYAreolineas  Recibe una variable tipo float que se va mostrar.
 * @param prLatam  Recibe una variable tipo float que se va mostrar.
 * @param prAerolineas  Recibe una variable tipo float que se va mostrar.
 * @param prDebitoLatam  Recibe una variable tipo float que se va mostrar.
 * @param prCreditoLatam  Recibe una variable tipo float que se va mostrar.
 * @param prBitcoinLatam  Recibe una variable tipo float que se va mostrar.
 * @param unitarioLatam  Recibe una variable tipo float que se va mostrar.
 * @param prDebitoAerolineas  Recibe una variable tipo float que se va mostrar.
 * @param prCreditoAerolineas  Recibe una variable tipo float que se va mostrar.
 * @param prBitcoinAerolineas  Recibe una variable tipo float que se va mostrar.
 * @param unitarioAerolineas  Recibe una variable tipo float que se va mostrar.
 */
void informarResultados(float km,float diferenciaLatamYAreolineas,float prLatam, float prAerolineas, float prDebitoLatam, float prCreditoLatam, float prBitcoinLatam,float unitarioLatam,float prDebitoAerolineas, float prCreditoAerolineas, float prBitcoinAerolineas,float unitarioAerolineas);


/**
 * @brief Esta funci�n hace el descuento del precio ingresado.
 * @param precio  Recibe el float que corresponde del precio ingresados.
 * @return Devuelve el resultado del precio en descuento.
 */
float descuentoDebito(float precio);


/**
 * @brief Esta funci�n hace un interes del precio ingresado.
 * @param precio Recibe el float que corresponde del precio ingresados.
 * @return Devuelve el resultado del precio en interes.
 */
float interesCredito(float precio);


/**
 * @brief Esta funcion calcula el precio con bitcoin
 * @param precio Recibe el float que corresponde del precio ingresados.
 * @return Devuelve el resultado del precio bitcoin.
 */
float Bitcoin(float precio);


/**
 * @brief Esta funci�n calcula el precio unitario
 * @param precio Recibe el float que corresponde del precio ingresados.
 * @param kilometros Recibe el float que corresponde a los kilometros ingresados.
 * @return Devuelve el resultado del precio unitario
 */
float Unitario(float precio, float kilometros);


/**
 * @brief Esta funci�n calcula la diferencia del precio Aerolineas con Latam.
 * @param diferenciaAerolineas Recibe el float que corresponde los datos de aerolineas ingresados.
 * @param diferenciaLatam Recibe el float que corresponde los datos de latam ingresados.
 * @return Devuelve el resultado de la diferencia entre los precios de Aerolineas y Latam.
 */
float diferenciaDePrecio(float diferenciaAerolineas, float diferenciaLatam);


/**
 * @brief Esta funci�n se encarga de mostrar exactamente los resultado sin ingresar ninguna opci�n previamente.
 * @param km Recibe el float que corresponde a los kilometros ingresados.
 * @param Aerolineas Recibe el float que corresponde los datos de aerolineas ingresados.
 * @param Latam Recibe el float que corresponde los datos de latam ingresados.
 */
void cargaForzada(float km, float Aerolineas, float Latam);

#endif /* CALCULAR_H_ */
