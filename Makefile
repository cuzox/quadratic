# Constants
CC = gcc
CFLAGS = -Wall -pedantic -lm -std=c99

# Main executable
qmain: qmain.o qargs.o qcoefs.o quadratic.o quadratic.h 
	$(CC) -o qmain qmain.o qargs.o qcoefs.o quadratic.o $(CFLAGS)

# Source files
qmain.o: qmain.c quadratic.h
	$(CC) -c qmain.c $(CFLAGS)

qargs.o: qargs.c quadratic.h
	$(CC) -c qargs.c $(CFLAGS)

qcoefs.o: qcoefs.c quadratic.h
	$(CC) -c qcoefs.c $(CFLAGS)

quadratic.o: quadratic.c quadratic.h
	$(CC) -c quadratic.c $(CFLAGS)

# Clean all generated files
clean:
	rm -f *.o qmain