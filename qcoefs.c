/* Returns struct of coefs a,b,c */

#include "quadratic.h"

void *getCoefs(ARGS *args){
	COEFS *coefs = malloc(sizeof(COEFS));
	coefs-> a = atof(args-> a);
	coefs-> b = atof(args-> b);
	coefs-> c = atof(args-> c);

	return coefs;
}