/*
 * ARRAYPASSANGER.h
 *
 *  Created on: 28 jun. 2022
 *      Author: ignac
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	char destino[51];
	int statusFlight;
	int isEmpty;
}typedef Passenger;

int addPassenger(Passenger ListPassenger[], int len, char name[],char lastName[],float price,int typePassenger, char destino[], int statusFlight);

int findPassengerById(Passenger ListPassenger[], int len,int id);

int changeDataPassengerById(Passenger ListPassenger[], int len,int id);

#endif /* ARRAYPASSENGER_H_ */
