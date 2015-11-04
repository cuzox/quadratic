/*
 * Main tester
 */

#include <stdlib.h>
#include "../quadratic.h"
#include "../quadratic.c"

void assert_eq(char*, int, int);

int main(int argc, char *argvp[]){

	COEFS coefs; /* a, b and c for the quadratic equation */
	ROOTS roots; /* root struct with x1 and x2 */
	ROOTS *ret; /* return value from quadratic.c */
	double x1, x2; /* temporary variables */

	x1 = 3.1;
	x2 = 3.3;
	coefs.a = 1.0;
	coefs.b = -x1 + -x2;
	coefs.c = x1 * x2;
	ret = solveQ(&coefs);
	assert_eq("ret", ret->real, 1);
	//assert_feqrerr("x1", ret->root[0], x2, 10.0 * cunit_dmacheps);

	return 0;
}

void assert_eq(char *str, int a, int b) {
  	if( a != b ) {
    	fprintf(stderr, "%s, %d !== %d\n", str, a, b);
	}  
}