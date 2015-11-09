tester: tester.o qargs.o qcoefs.o quadratic.o cunit.o quadratic.h 
	gcc -o tester tester.o qargs.o qcoefs.o quadratic.o cunit.o -Wall -pedantic -lm -std=c99

tester.o: tester.c quadratic.h cunit.h
	gcc -c tester.c -Wall -pedantic -lm -std=c99

qargs.o: qargs.c quadratic.h
	gcc -c qargs.c -Wall -pedantic -lm -std=c99

qcoefs.o: qcoefs.c quadratic.h
	gcc -c qcoefs.c -Wall -pedantic -lm -std=c99

quadratic.o: quadratic.c quadratic.h
	gcc -c quadratic.c -Wall -pedantic -lm -std=c99

cunit.o: cunit.c cunit.h
	gcc -c cunit.c -Wall -pedantic -lm -std=c99

clean:
	rm *.o tester