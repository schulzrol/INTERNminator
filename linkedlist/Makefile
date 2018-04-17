PROGRAM = llist
CC = gcc
MAINSRC = main.c
CFLAGS = -Wall -ggdb
SRCS = clearlist.c insert.c pop.c printlist.c push.c traverseRight.c traverseLeft.c insertlist.c
HEADERS = ${SRCS:.c=.h} defs.h
OBJS = ${SRCS:.c=.o} $(MAINSRC:.c=.o) 

.PHONY: all clean debug	

all: $(PROGRAM)

%.o: %.c $(HEADERS)
	$(CC) -c $< $(CFLAGS) -o $@
$(PROGRAM): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -f  $(PROGRAM) $(OBJS)
#debug:
#	CFLAGS += -ggdb
