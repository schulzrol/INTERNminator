PROGRAM = maxinarr
CC = gcc
MAINSRC = NejvetsiVNahPoli.c
SRCS =  toNumber.c assignRandoms.c IndexNejvetsiho.c printHelp.c
HEADERS = ${SRCS:.c=.h}
OBJS = ${SRCS:.c=.o} $(MAINSRC:.c=.o) 
OBJDIR = ./obj
LIBD =./include
CFLAGS = -O0 -ggdb -Wall -Werror

.PHONY: all clean	

all: $(PROGRAM)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f  $(PROGRAM) $(OBJS)
