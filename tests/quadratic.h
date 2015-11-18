#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFERSIZE 30

typedef struct {
	double a;
	double b;
	double c;
} COEFS;

typedef struct {
	char a[BUFFERSIZE];
	char b[BUFFERSIZE];
	char c[BUFFERSIZE];
} ARGS;

typedef struct{
	double root[2];
	int complex;
	int equal;
	int real;
} ROOTS;

void *getArgs(int, char**);
void *getCoefs(ARGS*);
void *solveQ(COEFS*);

void setExpect(double x);
double mockSqrt();


#endif /* QUADRATIC_H */
