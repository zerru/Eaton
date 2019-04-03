/*
 ============================================================================
 Name        : input.h
 Author      : Asier Lejarza
 Version     : 0.1
 Description : input file of the test for Eaton Prague
 ============================================================================
 */
#ifndef SRC_INPUT_H_
#define SRC_INPUT_H_

#define MAX_ROVER_LENGTH 3
#define MAX_ELEMENT_LENGTH 4
typedef int bool;
enum { false, true };

// Variables
int px, py, x, y, rover, percentage;
int current_rover;
int rover_size;
int rovers[100];
char data_input[MAX_ROVER_LENGTH];
char element[MAX_ELEMENT_LENGTH];

struct Data {
   int percentage;
   int counts;
   char element[MAX_ELEMENT_LENGTH];
   bool reliability;
   bool first;
};

// Funtions
void get_input_init();
int get_input();



#endif /* SRC_INPUT_H_ */
