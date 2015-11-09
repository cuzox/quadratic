qmain: qmain.o qargs.o qcoefs.o quadratic.o quadratic.h 
	gcc -o qmain qmain.o qargs.o qcoefs.o quadratic.o -Wall -pedantic -lm -std=c99

qmain.o: qmain.c quadratic.h
	gcc -c qmain.c -Wall -pedantic -lm -std=c99

qargs.o: qargs.c quadratic.h
	gcc -c qargs.c -Wall -pedantic -lm -std=c99

qcoefs.o: qcoefs.c quadratic.h
	gcc -c qcoefs.c -Wall -pedantic -lm -std=c99

quadratic.o: quadratic.c quadratic.h
	gcc -c quadratic.c -Wall -pedantic -lm -std=c99

clean:
	rm *.o qmain