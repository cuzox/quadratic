#include "quadratic.h"
//mock object, you can set what you expect and it will return that
float expected;

void setExpect(float x){
	expected = x;
}

float mockSqrt(){
	return expected;
}

