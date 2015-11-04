all: qargs qcoefs quadratic qmain

qmain: qargs.o qcoefs.o quadratic.o qmain.c quadratic.h 
	gcc -o qmain qmain.c -Wall -pedantic -lm -std=c99

qargs.o: qargs.c 
	gcc -c qargs.c 

qcoefs.o: qcoefs.c 
	gcc -c qcoefs.c 

quadratic.o: quadratic.c 
	gcc -c quadratic.c 