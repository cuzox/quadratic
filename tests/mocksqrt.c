/* mock object for sqrt(), 
 * you can set what you expect 
 * and it will return that 
 */

#include "quadratic.h"

double expected;

void setExpect(double x){
	expected = x;
}

double mockSqrt(){
	return expected;
}

