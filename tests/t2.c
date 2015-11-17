/*
 * Tester t2
 * Tests input to getCoefs()
 * Tests output from getCoefs()
 */

#include <stdlib.h>
#include "cunit.h"
#include "quadratic.h"

int main(int argc, char *argvp[]){

	/* initialize cunit framework */
	cunit_init();

	/* temporary variables */
	COEFS *coefs;	/* struct to be returned by getCoefs */
	ARGS *args = malloc(sizeof(ARGS));	/* struct pointer to be passed to getCoefs */
	double a, b, c;

	/* checks for coefs coming back correctly */
	strncpy(args->a, "-5.0", BUFFERSIZE);
	strncpy(args->b, "6", BUFFERSIZE);
	strncpy(args->c, "1.0", BUFFERSIZE);
	a = -5.0;
	b = 6.0;
	c = 1.0;
	coefs = getCoefs(args); 
	assert_feq("Floats not equal Error", a, coefs->a);
	assert_feq("Floats not equal Error", b, coefs->b);
	assert_feq("Floats not equal Error", c, coefs->c);
	
	/* checks for coefs not equal */
	strncpy(args->a, "-5.0", BUFFERSIZE);
	strncpy(args->b, "6", BUFFERSIZE);
	strncpy(args->c, "1.1", BUFFERSIZE);
	a = 5.0;
	b = 6.04;
	c = 0;
	coefs = getCoefs(args); 
	assert_nfeq("Floats Equal Error", a, coefs->a);
	assert_nfeq("Floats Equal Error", b, coefs->b);
	assert_nfeq("Floats Equal Error", c, coefs->c);

	/* free allocated memory */
	free(args);

	/* notify testing is complete */
	printf("Test t2 complete\n");

	return 0;
}