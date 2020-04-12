CC=gcc
CFLAGS= -g -Wall
TARGETS=main
OBJECTS=main.c stock.o
.SUFFIXES=.c .o

main_debug:$(TARGETS)
main_debug:DEBUGOPTION=-DDEBUG

$(TARGETS):$(OBJECTS)
	$(CC) $(CFLAGS) $(DEBUGOPTION) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) $(DEBUGOPTION) -c $< -o $@

clean:
	rm *.o $(TARGETS)
