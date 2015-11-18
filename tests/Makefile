t1: t1.o qargs.o qcoefs.o quadratic.o cunit.o mocksqrt.o quadratic.h 
	gcc -o t1 t1.o qargs.o qcoefs.o quadratic.o cunit.o mocksqrt.o -Wall -pedantic -lm -std=c99

t1.o: t1.c quadratic.h cunit.h
	gcc -c t1.c -Wall -pedantic -lm -std=c99

t2: t2.o qargs.o qcoefs.o quadratic.o cunit.o mocksqrt.o quadratic.h 
	gcc -o t2 t2.o qargs.o qcoefs.o quadratic.o cunit.o mocksqrt.o -Wall -pedantic -lm -std=c99

t2.o: t2.c quadratic.h cunit.h
	gcc -c t2.c -Wall -pedantic -lm -std=c99

t3: t3.o qargs.o qcoefs.o quadratic.o cunit.o mocksqrt.o quadratic.h 
	gcc -o t3 t3.o qargs.o qcoefs.o quadratic.o cunit.o mocksqrt.o -Wall -pedantic -lm -std=c99

t3.o: t3.c quadratic.h cunit.h
	gcc -c t3.c -Wall -pedantic -lm -std=c99

qargs.o: qargs.c quadratic.h
	gcc -c qargs.c -Wall -pedantic -lm -std=c99

qcoefs.o: qcoefs.c quadratic.h
	gcc -c qcoefs.c -Wall -pedantic -lm -std=c99

quadratic.o: quadratic.c quadratic.h
	gcc -c quadratic.c -Wall -pedantic -lm -std=c99

cunit.o: cunit.c cunit.h
	gcc -c cunit.c -Wall -pedantic -lm -std=c99

mocksqrt.o: mocksqrt.c quadratic.h
	gcc -c mocksqrt.c -Wall -pedantic -lm -std=c99

test1: t1
	./t1

test2: t2
	./t2

test3: t3
	./t3

clean:
	rm *.o t1 t2 t3