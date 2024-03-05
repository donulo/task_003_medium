CC = gcc
CFLAGS := ${CFLAGS}
CFLAGS += -Wall -Werror -Wextra
LIBS = lib/lib_file.c lib/lib_string.c lib/misc.c

all: clean simple_db

simple_db: $(LIBS) simple_db.o
	$(CC) $(CFLAGS) $(LIBS) simple_db.o -o ../bin/simple_db

simple_db.o: main.c
	$(CC) -c main.c -o simple_db.o

clean:
	rm -rf *.o
