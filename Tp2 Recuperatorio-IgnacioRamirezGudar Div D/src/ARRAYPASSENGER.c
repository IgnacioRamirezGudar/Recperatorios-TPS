/*
 * ARRAYPASSANGER.c
 *
 *  Created on: 28 jun. 2022
 *      Author: ignac
 */

#include "ARRAYPASSENGER.h"

#define LONGITUD_DESEADA 6

int rangoDelcodigo(int minimo, int maximo);
void generarFlyCode(int longitud, char *code);

static int generateID = -1;
static int generateSpace = -1;

int GenerateId(){

	generateID++;

	return generateID;

}

int GenerateSpace(){

	generateSpace++;

	return generateSpace;

}


int addPassenger(Passenger ListPassenger[], int len, char name[],char lastName[],float price,int typePassenger, char destino[], int statusFlight){

	int posList;
	char flycodigo[LONGITUD_DESEADA + 1] = "";

	posList = GenerateSpace();

	ListPassenger[posList].id = GenerateId();
	strcpy(ListPassenger[posList].name,name);
	strcpy(ListPassenger[posList].lastname, lastName);
	ListPassenger[posList].price = price;
	ListPassenger[posList].typePassenger = typePassenger;
	strcpy(ListPassenger[posList].destino,destino);
	ListPassenger[posList].statusFlight = statusFlight;
	generarFlyCode(LONGITUD_DESEADA, flycodigo);
	strcpy(ListPassenger[posList].flycode, flycodigo);
	ListPassenger[posList].isEmpty = 1;

	return 0;
}


int findPassengerById(Passenger ListPassenger[], int len,int id){

	int retorno;

	for(int i = 0; i <= len; i++){
		if(ListPassenger[i].id == id){
			if(ListPassenger[i].isEmpty == 1){
				retorno = 0;
			} else{
				retorno = 1;
			}
		}
	}

	return retorno;
}

int changeDataPassengerById(Passenger ListPassenger[], int len,int id){

	return 0;
}

/*
 * GENERO UN CODIGO DE VUELO ALEATORIO
 */

int rangoDelcodigo(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}


void generarFlyCode(int longitud, char *code){
    char letrasYnumeros[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    for (int i = 0; i < longitud; i++){
        int codigoDeVueloAleatorio = rangoDelcodigo(0, (int) strlen(letrasYnumeros) - 1);
        code[i] = letrasYnumeros[codigoDeVueloAleatorio];
    }
}
