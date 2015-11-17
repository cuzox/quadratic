/*
 * Tester t1
 * Tests input to getArgs()
 * Tests output from getArgs()
 */

#include <stdlib.h>
#include "cunit.h"
#include "quadratic.h"

int main(int argc, char *argvp[]){

	/* initialize cunit framework */
	cunit_init();

	/* temporary variables */
	int a1 = 4;		/* simulate argc, should always be 4 */
	char **a2;		/* simulate *argvp[] */
	int i;			/* for malloc loop */
	ARGS *args;		/* struct to be allocated and filled by getArgs() */

	/* allocate space for char** */
	a2 = calloc(3, sizeof(char*));
	for(i = 0; i < 3; i++){
		a2[i] = (char *)calloc(BUFFERSIZE, sizeof(char*));
	}

	/* test to make sure strings come back the same */ 
	a2[1] = "-5";
	a2[2] = "6.4";
	a2[3] = "0";
	args = getArgs(a1, a2);
	assert_seq("String not Equal Error", args->a, "-5");
	assert_seq("String not Equal Error", args->b, "6.4");
	assert_seq("String not Equal Error", args->c, "0");

	/* test to make sure it doesn't pass on bad data */
	a2[1] = "5";
	a2[2] = "6";
	a2[3] = "1";
	args = getArgs(a1, a2);
	assert_nseq("String Equal Error", args->a, "2");
	assert_nseq("String Equal Error", args->b, "2");
	assert_nseq("String Equal Error", args->c, "2");

	/* "free" space for char **a2 */
	a2 = NULL;

	/* tests finished confirmation */
	printf("Test t1 complete\n");

	return 0;
}
