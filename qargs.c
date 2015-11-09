#include "quadratic.h"

//Returns string of arguments
//which are later turned into coefs
//test this for proper input format


void *getArgs(int argc, char **argv){
	int result;
	char input[BUFFERSIZE*3];
	ARGS* args = malloc(sizeof(ARGS));

	if (argc == 4){
		strncpy(args->a, argv[1], BUFFERSIZE);
		strncpy(args->b, argv[2], BUFFERSIZE);
		strncpy(args->c, argv[3], BUFFERSIZE);
	}else{

		do{
			printf("Enter a, b and c separated by a space: ");
			fgets( input, sizeof(input), stdin);
			result = sscanf(input, "%s %s %s", args->a, args->b, args->c);
			if (result != 3)
				printf("Input not entered in correct format.\n");
		}while(result < 1);
	}

	return args;
}