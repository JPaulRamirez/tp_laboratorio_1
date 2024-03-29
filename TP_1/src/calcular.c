/*
 * calcular.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Paul Ramirez Benites
 */
#include <stdio.h>
#include <stdlib.h>


void pedirNumeroEntero(int *numero, int min, int max)
{
   printf("\nIngrese un opcion de (1-6): ");
   fflush(stdin);
   scanf("%d", numero);

        while(*numero < min || *numero > max)
        {
        	printf("\nOpci�n incorrecta, reingrese una opcion: ");
            fflush(stdin);
            scanf("%d", numero);
        }

}
int pedirOpcion(float km, float precioAerolineas, float precioLatam)
{
	int min =1;
	int max =6;
	int opcion;
	// Menu de opciones
	printf("\n1. Ingresar Kilometros: (km = %.2f)\n"
			"2. Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f)\n"
			"3. Calcular todos los costos:\n"
			"4. Informar Resultados\n"
			"5. Carga forzada de datos\n"
			"6. Salir \n",km,precioAerolineas,precioLatam);

	pedirNumeroEntero(&opcion, min,max);//Llamo la funcion para validar un entero
	return opcion;
}

float kilometrosIngresados(float kilometros)
{
	printf("\nIngrese los kilometros: ");
	scanf("%f", &kilometros);
	fflush(stdin);
	while(kilometros<=0)
	{
		printf("\nErorr, reingrese los kilometros: ");
		scanf("%f", &kilometros);
		fflush(stdin);
	}
	return kilometros;
}

float precioAerolineasIngresados(float precioAerolineas)
{
	printf("Ingrese los precios del vuelos de Aerolineas: ");
	fflush(stdin);
	scanf("%f", &precioAerolineas);
	while(precioAerolineas<=0)
	{
		printf("Erorr, reingrese los precios del vuelos de Aerolineas: ");
		fflush(stdin);
		scanf("%f", &precioAerolineas);
	}
	return precioAerolineas;
}

float precioLatamIngresados(float precioLatam)
{
	printf("Ingrese los precios del vuelos de Latam: ");
	scanf("%f", &precioLatam);
	fflush(stdin);
	while(precioLatam<=0)
	{
		printf("Erorr, reingrese los precios del vuelos de Latam: ");
		fflush(stdin);
		scanf("%f", &precioLatam);
	}
	return precioLatam;
}

float descuentoDebito(float precio)
{
	float precioConDescuento;

	precioConDescuento=precio-(precio*10)/100;

	return precioConDescuento;

}
float interesCredito(float precio)
{
	float precioConInteres;

	precioConInteres=precio+(precio*25)/100;

	return precioConInteres;

}
float Bitcoin(float precio)
{
	float precioBitcoin;

	precioBitcoin=precio/4606954.55;//(1BTC -> 4606954.55 Pesos Argentinos)

	return precioBitcoin;
}
float Unitario(float precio, float kilometros)
{
	float precioUnitario;

	precioUnitario=precio/kilometros;

	return precioUnitario;

}
float diferenciaDePrecio(float diferenciaAerolineas, float diferenciaLatam)
{
	float prDiferencia;

	if(diferenciaAerolineas > diferenciaLatam)
	{
		prDiferencia=diferenciaAerolineas-diferenciaLatam;
		return prDiferencia;
	}
	else
	{
		prDiferencia=diferenciaLatam-diferenciaAerolineas;
		return prDiferencia;
	}

}

void informarResultados(float km,float diferenciaLatamYAreolineas,float prLatam, float prAerolineas, float prDebitoLatam, float prCreditoLatam, float prBitcoinLatam,float unitarioLatam,float prDebitoAerolineas, float prCreditoAerolineas, float prBitcoinAerolineas,float unitarioAerolineas)
{
		printf("\nKMs ingresados: %.1f km\n",km);

		printf("\nPrecio Aerolineas: $ %.2f\n"
				"a)Precio con tarjeta debito: $ %.2f\n"
				"b)Precio con tarjeta de credito: $ %.2f\n"
				"c)Precio pagando con bitcoin: %.2f BTC\n"
				"d)Precio unitario: $ %.2f\n",prAerolineas,prDebitoAerolineas,prCreditoAerolineas,prBitcoinAerolineas,unitarioAerolineas);

		printf("\nPrecio Latam: $ %.2f\n"
				"a)Precio con tarjeta debito: $ %.2f\n"
				"b)Precio con tarjeta de credito: $ %.2f\n"
				"c)Precio pagando con bitcoin: %.2f BTC\n"
				"d)Precio unitario: $ %.2f\n",prLatam,prDebitoLatam,prCreditoLatam,prBitcoinLatam,unitarioLatam);

		printf("\nLa diferencia de precio es : $ %.2f\n",diferenciaLatamYAreolineas);

}
void cargaForzada(float km, float Aerolineas, float Latam)
{
	float kilometrosIngresados;

	float descuentoAerolineas;
	float interesAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;

	float diferenciaLatamYAreolineas;

	float descuentoLatam;
	float interesLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;

	kilometrosIngresados = (km);
	descuentoAerolineas = descuentoDebito(Aerolineas);
	interesAerolineas = interesCredito(Aerolineas);
	bitcoinAerolineas = Bitcoin(Aerolineas);
	precioUnitarioAerolineas = Unitario(Aerolineas,km);

	descuentoLatam = descuentoDebito(Latam);
	interesLatam = interesCredito(Latam);
	bitcoinLatam = Bitcoin(Latam);
	precioUnitarioLatam = Unitario(Latam,km);

	diferenciaLatamYAreolineas=diferenciaDePrecio(Aerolineas, Latam);

	informarResultados(kilometrosIngresados, diferenciaLatamYAreolineas, Latam, Aerolineas, descuentoLatam, interesLatam, bitcoinLatam, precioUnitarioLatam, descuentoAerolineas, interesAerolineas, bitcoinAerolineas, precioUnitarioAerolineas);

}
