/*
 * Tester t3
 * Tests input to solveQ()
 * Tests output from solveQ()
 * Uses mock object for sqrt()
 */

#include "cunit.h"
#include "quadratic.h"

int main(int argc, char *argvp[]){

	/* initialize cunit framework */
	cunit_init();
	setExpect(-.2);

	/* temporary variables */
	ROOTS *roots;	/* struct to be returned by solveQ */
	COEFS *coefs = malloc(sizeof(COEFS));	/* struct to be passed to solveQ */
	double x1, x2;	/* scratch variables */

	/* allows for one base 10 least significant digit of error */
	x1 = 3.1;
	x2 = 3.3;
	coefs->a = 1.0;
	coefs->b = -x1 + -x2;
	coefs->c = x1 * x2;
	roots = solveQ(coefs);
	assert_eq("ret", roots->real, 1);
	assert_feqrerr("x1", roots->root[0], x2, 10.0 * cunit_dmacheps);
	assert_feqrerr("x2", roots->root[1], x1, 10.0 * cunit_dmacheps);

	//test 2
	setExpect(1);
	x1 = 1;
	x2 = 1;
	coefs->a = 1.0;
	coefs->b = -x1 + -x2;
	coefs->c = x1 * x2;
	roots = solveQ(coefs);
	assert_eq("ret", roots->real, 1);
	assert_feqrerr("x1", roots->root[0], x2, 10.0 * cunit_dmacheps);
	assert_feqrerr("x2", roots->root[1], x1, 10.0 * cunit_dmacheps);
	/* notify testing complete */
	printf("Test t3 complete\n");

	return 0;
}
