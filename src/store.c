/*
 ============================================================================
 Name        : store.c
 Author      : Asier Lejarza
 Version     : 0.1
 Description : store file of the test for Eaton Prague
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "store.h"


/******************
 *  store_rover
 *  Save the different rover numbers from where we are receiving data
 *  @param: rovers. Array of all the rovers we had received any message
 *  @param: length. Total number of different rovers
 *  @param: current_rover. The last rover from where we have received a message. We have to add to the array if it isn´t there
 *  @result: The new array of rovers. There is 2 options: it could be the same array, or we could have added the last rover
 ******************/
int store_rover(int *rovers, int length, int current_rover){
	for(int i = 0; i < length; i++){
		if(rovers[i] == current_rover){
		   return length;
		}
	}
	rovers[length] = current_rover;
	return ++length;
}

/******************
 *  store_data
 *  Save all the data of the grid
 *  @param: data. The previous  data
 *  @param: eleme. The received element
 *  @param: percent. The received percentage
 *  @result: The new struct of the data, updated
 ******************/
struct Data store_data(struct Data data, char *eleme, int percent){
	// Is the first measurement of this position? If yes: Init counts
	if((data.percentage < 1 || data.percentage > 100 || data.reliability > 1 || data.reliability < 0) && data.percentage != -1){
		data.counts = 0;
	}
	data.counts++;

	// There is already any measurement or is first measurement
	if((strcmp(data.element, eleme) == 0 && data.percentage != -1) || data.counts == 1){
		strcpy(data.element, eleme);
		data.percentage = percentage_calc(data.percentage, percent, data.counts);
		data.reliability = true;
	}
	else{
		data.percentage = -1; // Unreliable grid forever
	    data.reliability = false;
	}

	return data;
}

/******************
 *  percentage_calc
 *  Calculate the average percentage
 *  @param: percentage_old. The old average percentage
 *  @param: percentage_new. The new percentage read
 *  @param: counts. Number of times received the percentage
 *  @result: The new percentage
 ******************/
int percentage_calc(int percentage_old, int percentage_new, int counts){
	int result = -1;

	if(counts == 1){
		result = percentage_new;
	}
	else if(counts > 1){
		result = (percentage_old * (counts - 1) + percentage_new) / counts;
	}
	else{
		// Do nothing
	}

	return result;
}

