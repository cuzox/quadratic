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

void *getArgs(int, char*[]);
void *getCoefs(ARGS*);
void *solveQ(COEFS*);

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

void *getArgs(int argc, char*argv[]){
	int result;
	char input[BUFFERSIZE*3];
	ARGS *args = malloc(sizeof(ARGS));

	if (argc == 4){
		strncpy(argv[1], args-> a, BUFFERSIZE);
		strncpy(argv[2], args-> b, BUFFERSIZE);
		strncpy(argv[3], args-> c, BUFFERSIZE);
	}else{

		do{
			printf("Enter a,b and c sepparated by a space: ");
			fgets( input, sizeof(input), stdin);
			result = sscanf(input, "%s %s %s", &args-> a, &args-> b, &args-> c);
			if (result != 3)
				printf("Input not entered in correct format.\n");
		}while(result < 1);
	}

	return args;
}

/* More strict meassures could be taken in this method
 * to ensure values are floats.
 */
void *getCoefs(ARGS *args){
	COEFS *coefs = malloc(sizeof(COEFS));
	coefs-> a = atof(args-> a);
	coefs-> b = atof(args-> b);
	coefs-> c = atof(args-> c);

	return coefs;
}

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
