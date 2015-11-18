/* 
 * Main program driver, calls all other functions
 * and prints results.
 */

#include "quadratic.h"

extern void *getArgs(int, char**);
extern void *getCoefs(ARGS*);
extern void *solveQ(COEFS*);

int main(int argc, char *argv[]){
	ARGS *args = getArgs(argc, argv);
	COEFS *coefs = getCoefs(args);
	ROOTS *roots = solveQ(coefs);

	if (roots-> complex){
		printf("Roots are complex: ");
		printf("%.8f%+.8fi", roots->root[0], roots->root[1]);
		printf(", %.8f%+.8fi\n", roots->root[0], -roots->root[1]);
	}else if(roots-> equal){
		printf("Roots are equal: %.8f\n", roots->root[0]);
	}else if (roots-> real){
		printf("Roots are real numbers: %.8f , %.8f\n", roots->root[0], roots->root[1]);
	}

	return 0;
}