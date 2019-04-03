/*
 ============================================================================
 Name        : store.h
 Author      : Asier Lejarza
 Version     : 0.1
 Description : store file of the test for Eaton Prague
 ============================================================================
 */
#ifndef SRC_STORE_H_
#define SRC_STORE_H_


// Funtions
int store_rover(int *rovers, int lenght, int rover);
struct Data store_data(struct Data data, char *eleme, int percent);
int percentage_calc(int percentage_old, int percentage_new, int counts);

#endif /* SRC_STORE_H_ */
