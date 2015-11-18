#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFERSIZE 30

typedef struct {
	float a;
	float b;
	float c;
} COEFS;

typedef struct {
	char a[BUFFERSIZE];
	char b[BUFFERSIZE];
	char c[BUFFERSIZE];
} ARGS;

typedef struct{
	float root[2];
	int complex;
	int equal;
	int real;
} ROOTS;

void *getArgs(int, char**);
void *getCoefs(ARGS*);
void *solveQ(COEFS*);

void setExpect(float x);
float mockSqrt();


#endif /* QUADRATIC_H */
