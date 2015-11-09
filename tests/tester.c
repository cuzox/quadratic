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
	int a1;
	char **a2;
	int i;

	/* getArgs unit tests */
	a1 = 4;
	fprintf(stderr, "entering malloc\n");
	a2 = calloc(3, sizeof(char*));
	for(i = 0; i < 3; i++){
		a2[i] = (char *)calloc(BUFFERSIZE, sizeof(char*));
	}
	fprintf(stderr, "leaving malloc\n"); 
	a2[1] = "5";
	a2[2] = "6";
	a2[3] = "1";
	fprintf(stderr, "assigned values\n");
	ARGS *args = getArgs(a1, a2);
	fprintf(stderr, "entering asserts\n");
	assert_seq("ret", args->a, "5");
	assert_seq("ret", args->b, "6");
	assert_seq("ret", args->c, "1");

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