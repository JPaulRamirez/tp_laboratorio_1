/*
 * Passenger.h
 *
 *  Created on: 8 jun. 2022
 *      Author: Compumar
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
typedef struct
{
    int id;
    char name[51];
    char lastname[51];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFlight;
    int isEmpaty;
}Passenger;
typedef struct
{
	char description[25];
	int idStatusFlight;

}eEstatusFlight;

typedef struct
{
	char description[25];
	int idTypePassenger;

}eTypePassenger;

int initPassengers(Passenger *list , int limite);

int findEmptyFree(Passenger *list,int limite, int *espacioLibre);
int addPassenger(Passenger*list,int tamanio,int tamanioChar,int* contadorId);
int modifyPassenger(Passenger *list,int tamanioChar);
int removePassenger(Passenger *list, int limite, int id);
int findPassengerById(Passenger *list,int limite,int id,int *indice);
int printPassengers(Passenger *list , int limite);
void printPassenger(Passenger list);
int sortPassengers(Passenger *list,int tamanio,int order);
//cuentas
int totalPrice(Passenger* list, int tamanio, float*total);
int PromedioPrice(int tamanio, float total, float*promedio);
int SuperanPricePromedio(Passenger* list, int tamanio, float promedio, int*acum);

int sortPassengersByCode(Passenger* list, int tamanio, int order);
int printActiveFlights(Passenger* list, int tamanio);





#endif /* PASSENGER_H_ */
