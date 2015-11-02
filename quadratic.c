#include "quadratic.h"

/*Does calculation from given struct of coefs
 *Returns struct of roots
 *Testing needs completed to ensure the right answer is coming back out
 */

void *solveQ(COEFS* coefs){
	ROOTS *roots = malloc(sizeof(ROOTS));
	float d = coefs-> b * coefs-> b - 4 * coefs-> a * coefs-> c;
  
	if(d < 0){
		roots-> root[0] = -coefs-> b/(2*coefs-> a);
		roots-> root[0] = sqrt(-d)/(2*coefs-> a);
		roots-> complex = 1;

	}else if(d==0){
		roots-> root[0] = -coefs-> b /(2* coefs-> a);
		roots-> equal = 1;

	}else{
		roots-> root[0] = ( -coefs-> b + sqrt(d)) / (2* coefs-> a);
		roots-> root[1] = ( -coefs-> b - sqrt(d)) / (2* coefs-> a);
		roots-> real = 1;
	}

	return roots;
}
