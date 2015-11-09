/*
 * Main tester
 */

#include <stdlib.h>
#include "cunit.h"
#include "quadratic.h"

int main(int argc, char *argvp[]){

	COEFS coefs; /* a, b and c for the quadratic equation */
	// ROOTS roots; /* root struct with x1 and x2 */
	ROOTS *ret; /* return value from quadratic.c */
	/* temporary variables */
	double x1, x2;
	// int x1;
	// char **x2;

	/* getArgs unit tests */
	// x1 = 3;
	// char *x2[3]; 
	// ARGS *args = getArts();

	/* getCoefs unit tests */

	/* solveQ unit tests */
	x1 = 3.1;
	x2 = 3.3;
	coefs.a = 1.0;
	coefs.b = -x1 + -x2;
	coefs.c = x1 * x2;
	ret = solveQ(&coefs);
	assert_eq("ret", ret->real, 1);
	// assert_feqrerr("x1", ret->root[0], x2, 10.0 * cunit_dmacheps);

	return 0;
}