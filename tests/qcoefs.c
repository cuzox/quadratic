#include "quadratic.h"

/* Returns struct of coefs a,b,c 
 * Testing needs to be completed to ensure proper floats are stored
 * More strict meassures could be taken in this method
 * to ensure values are floats.
 */
void *getCoefs(ARGS *args){
	COEFS *coefs = malloc(sizeof(COEFS));
	coefs-> a = atof(args-> a);
	coefs-> b = atof(args-> b);
	coefs-> c = atof(args-> c);

	return coefs;
}
