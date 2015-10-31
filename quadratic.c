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
	int complex = 0;
	int equal = 0;
	int numbers = 0;
} ROOTS;

void *getArgs(int, char*[]);
void *getCoefs(ARGS*);
void solveQ(COEFS*);

int main(int argc, char *argv[]){
	ARGS *args = getArgs(argc, argv);
	COEFS *coefs = getCoefs(args);
	ROOTS *roots = solveQ(coefs);

	/* Print roots */

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

void *getCoefs(ARGS *args){
	COEFS *coefs = malloc(sizeof(COEFS));
	coefs-> a = atof(args-> a);
	coefs-> b = atof(args-> b);
	coefs-> c = atof(args-> c);

	return coefs;
}

void solveQ(COEFS* coefs){
	ROOTS *roots = malloc(sizeof(ROOTS));
	/* reformat */
	// float root[2], d = b * b - 4 * a * c;
  
	// if(d < 0){
	// 	printf("Roots are complex: ");
	// 	printf("%.3f%+.3fi",-b/(2*a),sqrt(-d)/(2*a));
	// 	printf(", %.3f%+.3fi",-b/(2*a),-sqrt(-d)/(2*a));

	// }else if(d==0){
	// 	root[0] = -b /(2* a);
	// 	printf("Roots are equal: %.3f ", root[0]);

	// }else{
	// 	root[0] = ( -b + sqrt(d)) / (2* a);
	// 	root[1] = ( -b - sqrt(d)) / (2* a);
	// 	printf("Roots are real numbers: %.3f , %.3f",root[0],root[1]);
	// }
	return roots;
}
