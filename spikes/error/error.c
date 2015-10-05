#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void absoluteError(float, float);
void relativeError(float, float);

int main(int argc, char *argv[]){
	if(argc < 1){
		printf("No input detected.\n");
		exit(EXIT_FAILURE);
	}

	float pi, radius, area;
	pi = atof(argv[1]);
	radius = atof(argv[2]);
	area = PI * radius * radius;

	absoluteError(area, pi * (radius * radius));
	relativeError(area, pi * (radius * radius));

	return 0;
}

void absoluteError(float expected, float actual){
	printf("Absolute error is %9.9f\n", fabs(expected - actual));
}

void relativeError(float expected, float actual){
	printf("Relative error is %9.9f%%\n", ((fabs(expected - actual)) / (fabs(expected) + fabs(actual))) * 100);
}