/*
 ============================================================================
 Name        : main.c
 Author      : Asier Lejarza
 Version     : 0.1
 Description : main file of the test for Eaton Prague
 ============================================================================
 */
#include "src/input.h"


/******************
 *  main
 ******************/
int main () {
	get_input_init();

	while(1){
		if(get_input() == -1){
			return 0;
		}
	}

    return 0;
}


