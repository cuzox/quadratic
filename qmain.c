#include "quadratic.h"

int main(int argc, char *argv[]){
	ARGS *args = getArgs(argc, argv);
	COEFS *coefs = getCoefs(args);
	ROOTS *roots = solveQ(coefs);

	if (roots-> complex){
		printf("Roots are complex: ");
		printf("%.3f%+.3fi", roots-> root[0],roots-> root[1]);
		printf(", %.3f%+.3fi\n", roots-> root[0], -roots-> root[1]);
	}else if(roots-> equal){
		printf("Roots are equal: %.3f ", roots-> root[0]);

	}else if (roots-> real){
		printf("Roots are real numbers: %.3f , %.3f", roots-> root[0], roots-> root[1]);
	}
}