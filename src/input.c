/*
 ============================================================================
 Name        : input.c
 Author      : Asier Lejarza
 Version     : 0.1
 Description : input file of the test for Eaton Prague
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "store.h"


// Init
int rover_size = 0;


/******************
 *  get_input_init
 *  Get the Plateau size [x, y]
 *  Separated with a comma
 ******************/
void get_input_init(){
	printf("Please, write the plateau size [x, y]: ");
	while(1){
		if(scanf("%d, %d", &px, &py) == 2 && px > 0 && py > 0){
			return;
		}
		scanf("%*[^\n]"); // In order to show printf just once
		printf("\nPlease, write the plateau size in the correct format [x, y]: ");
	}
}

/******************
 *  get_input
 *  Get different inputs:
 *  	a) store data received from rovers
 *  	b) get data
 *  	c) finish
 *  @result: -1 if the programm has to finish
 ******************/
int get_input(){
	struct Data data[px][py];

	printf("\nEnter or get data. Plateau size is [%d, %d]. Rovers: %d\n", px, py, rover_size);

	/* Exit from the program */
	if(scanf("%s", data_input) == 1 && (strcmp(data_input, "exit") == 0 || strcmp(data_input, "bye") == 0)){
		return -1;
	}
	/* Enter data from any Rover */
	else if(strlen(data_input) <= MAX_ROVER_LENGTH && data_input[0] == 'R' && data_input[1] >= '0' && data_input[1] <= '9' && data_input[2] >= '0' && data_input[2] <= '9'){
		current_rover = (data_input[1] - 48) * 10 + data_input[2] - 48;
		if(scanf("%d%d", &x, &y) == 2 && px >= x && x >= 0 && py >= y && y >= 0){
			if(scanf("%s", element) == 1 && strlen(element) <= MAX_ELEMENT_LENGTH){
				if(scanf("%d", &percentage) == 1 && percentage > 0 && percentage <= 100){
					// Store Rover
					rover_size = store_rover(rovers, rover_size, current_rover);
					// Store the data
					data[x][y] = store_data(data[x][y], element, percentage);
				}
				else{
					printf("\nWrong percentage, it should be between 1%% and 100%%");
				}
			}
			else{
				printf("\nWrong element length (max 4 letters)");
			}
		}
		else{
			printf("\nWrong position, try again");
		}
	}
	/* Get data from any position */
	else if(data_input[0] == 'G' && data_input[1] == 'E' && data_input[2] == 'T'){
		if(scanf("%d%d", &x, &y) == 2 && px >= x && x >= 0 && py>= y && y >= 0){
			// Output:
			if(data[x][y].counts > 0 && data[x][y].reliability == true){
				printf("Good data: %.4s with %d%% measured %d time(s)\n", data[x][y].element, data[x][y].percentage, data[x][y].counts);
			}
			else{
				printf("\nPosition not measured or Unreliable data measured");
			}
		}
		else{
			printf("\nWrong position to get. Is it inside the plateau?");
		}
	}
	/* Wrong typed data */
	else{
		printf("\nNo valid data.\nPlease, write a Rover message (RXX x y element percentage)\nor any get command (GET x y)");
	}

	return 0;
}



