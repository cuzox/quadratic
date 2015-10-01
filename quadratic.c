#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solveQ(float, float, float);

int main(int argc, char *argv[]){
	int result;
	char input[100];
	float a;
	float b;
	float c;
	if (argc > 1){
		a = atof(argv[1]);
		b = atof(argv[2]);
		c = atof(argv[3]);

	}else{
		do{
			printf("Enter a,b and c sepparated by a space: ");
			fgets( input, sizeof(input), stdin);
			result = sscanf(input, "%f %f %f", &a, &b, &c);
			if (result < 1){ 	
				printf("Input error.\n");
			}

		}while(result < 1);
	}

	solveQ(a,b,c);
}

void solveQ(float a, float b, float c){
	float root[2], d = b * b - 4 * a * c;
  
	if(d < 0){
		printf("root are complex: ");
		printf("%.3f%+.3fi",-b/(2*a),sqrt(-d)/(2*a));
		printf(", %.3f%+.3fi",-b/(2*a),-sqrt(-d)/(2*a));

	}else if(d==0){
		root[0] = -b /(2* a);
		printf("root are equal: %.3f ", root[0]);

	}else{
		root[0] = ( -b + sqrt(d)) / (2* a);
		root[1] = ( -b - sqrt(d)) / (2* a);
		printf("root are real numbers: %.3f , %.3f",root[0],root[1]);
	}

}
