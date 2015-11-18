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

	/* temporary variables */
	ROOTS *roots;	/* struct to be returned by solveQ */
	COEFS *coefs = malloc(sizeof(COEFS));	/* struct to be passed to solveQ */
	double x1, x2;	/* scratch variables */

	/* test mock object */
	setExpect(3.0);
	assert_feq("mockSqrt", 3.0, mockSqrt());

	/* test mock object for correctness through repetitive calls */
	setExpect(7.0);
	assert_feq("mockSqrt", 7.0, mockSqrt());
	assert_feq("mockSqrt", 7.0, mockSqrt());
	assert_feq("mockSqrt", 7.0, mockSqrt());

	/*
	 * Test for equation with real solutions 
	 * Allows for one base 10 least significant digit of error 
	 */
	setExpect(.2);
	x1 = 3.1;
	x2 = 3.3;
	coefs->a = 1.0;
	coefs->b = -x1 + -x2;
	coefs->c = x1 * x2;
	roots = solveQ(coefs);
	assert_eq("ret", roots->real, 1);
	assert_feqrerr("x1", roots->root[0], x2, 10.0 * cunit_dmacheps);
	assert_feqrerr("x2", roots->root[1], x1, 10.0 * cunit_dmacheps);
	
	/*
	 * Test for equation with one real solution 
	 * Allows for one base 10 least significant digit of error 
	 */
	setExpect(0);
	x1 = 3;
	x2 = 3;
	coefs->a = 1.0;
	coefs->b = -x1 + -x2;
	coefs->c = x1 * x2;
	roots = solveQ(coefs);
	assert_eq("ret", roots->equal, 1);
	assert_feqrerr("x1", roots->root[0], x2, 10.0 * cunit_dmacheps);
	assert_feqrerr("x2", roots->root[1], x1, 10.0 * cunit_dmacheps);

	/*
	 * Test for equation with complex solutions 
	 * Allows for one base 10 least significant digit of error 
	 */
	setExpect(1.732050808);
	x1 = -0.633974596;
	x2 = -2.366025404;
	coefs->a = 1.0;
	coefs->b = -x1 + -x2;
	coefs->c = 3;
	roots = solveQ(coefs);
	assert_eq("ret", roots->complex, 1);
	assert_feqrerr("x1", roots->root[0] + roots->root[1], x1, 10.0 * cunit_dmacheps);
	assert_feqrerr("x2", roots->root[0] - roots->root[1], x2, 10.0 * cunit_dmacheps);

	/* notify testing complete */
	printf("Test t3 complete\n");

	return 0;
}
