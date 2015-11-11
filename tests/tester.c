/*
 * Main tester
 */

#include <stdlib.h>
#include "cunit.h"
#include "quadratic.h"

int main(int argc, char *argvp[]){

	cunit_init();

	COEFS *coefs;
	COEFS coefs2; /* a, b and c for the quadratic equation */
	// ROOTS roots; /* root struct with x1 and x2 */
	ROOTS *ret; /* return value from quadratic.c */
	/* temporary variables */
	double x1, x2;
	float a, b, c;
	int a1;
	char **a2;
	int i;
	ARGS *args;
	/* getArgs unit tests */
	a1 = 4;
	//fprintf(stderr, "entering malloc\n");
	a2 = calloc(3, sizeof(char*));
	for(i = 0; i < 3; i++){
		a2[i] = (char *)calloc(BUFFERSIZE, sizeof(char*));
	}
	//test to make sure strings come back the same 
	a2[1] = "-5";
	a2[2] = "6.4";
	a2[3] = "0";
	args = getArgs(a1, a2);
	assert_seq("String not Equal Error", args->a, "-5");
	assert_seq("String not Equal Error", args->b, "6.4");
	assert_seq("String not Equal Error", args->c, "0");

	//test to make sure it doesnt pass on everything
	a2[1] = "5";
	a2[2] = "6";
	a2[3] = "1";
	args = getArgs(a1, a2);
	assert_nseq("String Equal Error", args->a, "2");
	assert_nseq("String Equal Error", args->b, "2");
	assert_nseq("String Equal Error", args->c, "2");

	/* getCoefs unit tests */
	//checks for coefs coming back correctly
	ARGS *args2 = malloc(sizeof(ARGS));
	strncpy(args2->a, "-5", BUFFERSIZE);
	strncpy(args2->b, "6", BUFFERSIZE);
	strncpy(args2->c, "1.1", BUFFERSIZE);
	a = -5.0;
	b = 6.0;
	c = 1.1;
	coefs = getCoefs(args2); 
	assert_feq("Floats not equal Error", a, coefs->a);
	assert_feq("Floats not equal Error", b, coefs->b);
	assert_feq("Floats not equal Error", c, coefs->c);
	
	//checks for coefs not equal
	strncpy(args2->a, "-5.0", BUFFERSIZE);
	strncpy(args2->b, "6", BUFFERSIZE);
	strncpy(args2->c, "1.1", BUFFERSIZE);
	a = 5.0;
	b = 6.04;
	c = 0;
	coefs = getCoefs(args2); 
	assert_nfeq("Floats Equal Error", a, coefs->a);
	assert_nfeq("Floats Equal Error", b, coefs->b);
	assert_nfeq("Floats Equal Error", c, coefs->c);

	/* solveQ unit tests */
	x1 = 3.1;
	x2 = 3.3;
	coefs2.a = 1.0;
	coefs2.b = -x1 + -x2;
	coefs2.c = x1 * x2;
	ret = solveQ(&coefs2);
	assert_eq("ret", ret->real, 1);
	// assert_feqrerr("x1", ret->root[0], x2, 10.0 * cunit_dmacheps);


	printf("Test complete\n");
	return 0;
}
