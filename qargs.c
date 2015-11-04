#include "quadratic.h"

//Returns string of arguments
//which are later turned into coefs
//test this for proper input format


void *getArgs(int argc, char *argv[]){
	int result;
	char input[BUFFERSIZE*3];
	ARGS* args = malloc(sizeof(ARGS));

	if (argc == 4){
		strncpy(argv[1], args-> a, BUFFERSIZE);
		strncpy(argv[2], args-> b, BUFFERSIZE);
		strncpy(argv[3], args-> c, BUFFERSIZE);
	}else{

		do{
			printf("Enter a,b and c sepparated by a space: ");
			fgets( input, sizeof(input), stdin);
			result = sscanf(input, "%s %s %s", &args->a, &args->b, &args->c);
			if (result != 3)
				printf("Input not entered in correct format.\n");
		}while(result < 1);
	}

	return args;
}