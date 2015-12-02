# Constants
CC = gcc
CFLAGS = -Wall -pedantic -lm -std=c99

# Functional tests
tf: qmain.o qargs.o qcoefs.o qsolve.o quadratic.h cunit.o cunit.h
	$(CC) -o tf qmain.o qargs.o qcoefs.o qsolve.o cunit.c $(CFLAGS)

tf.o: tf.c quadratic.h cunit.h
	$(CC) -c tf.c $(CFLAGS)

# Unit tests
# t1 depends on qargs.c
t1: t1.o qargs.o cunit.o quadratic.h 
	$(CC) -o t1 t1.o qargs.o cunit.o $(CFLAGS)

t1.o: t1.c quadratic.h cunit.h
	$(CC) -c t1.c $(CFLAGS)

# t2 depends on qcoefs.c
t2: t2.o qcoefs.o cunit.o quadratic.h 
	$(CC) -o t2 t2.o qcoefs.o cunit.o $(CFLAGS)

t2.o: t2.c quadratic.h cunit.h
	$(CC) -c t2.c $(CFLAGS)

# t3 depends on quadratic.c and mocksqrt.c
t3: t3.o quadratic.o cunit.o mocksqrt.o quadratic.h 
	$(CC) -o t3 t3.o quadratic.o cunit.o mocksqrt.o $(CFLAGS)

t3.o: t3.c quadratic.h cunit.h
	$(CC) -c t3.c $(CFLAGS)

# Run tests
test1: t1
	./t1

test2: t2
	./t2

test3: t3
	./t3

testf: tf
	./tf < input.txt > output.txt
	diff output.txt expected.txt

# Source files
qmain.o: qmain.c quadratic.h
	$(CC) -c qmain.c $(CFLAGS)

qargs.o: qargs.c quadratic.h
	$(CC) -c qargs.c $(CFLAGS)

qcoefs.o: qcoefs.c quadratic.h
	$(CC) -c qcoefs.c $(CFLAGS)

quadratic.o: quadratic.c quadratic.h
	$(CC) -c quadratic.c $(CFLAGS)

qsolve.o: qsolve.c quadratic.h
	$(CC) -c qsolve.c $(CFLAGS)

cunit.o: cunit.c cunit.h
	$(CC) -c cunit.c $(CFLAGS)

mocksqrt.o: mocksqrt.c quadratic.h
	$(CC) -c mocksqrt.c $(CFLAGS)

# Clean all generated files
clean:
	rm -f *.o t1 t2 t3 tf