PROGRAM = maxinarr
CC = gcc
MAINSRC = NejvetsiVNahPoli.c
SRCS = isBlankLine.c toNumber.c assignRandoms.c IndexNejvetsiho.c
HEADERS = ${SRCS:.c=.h}
OBJS = ${SRCS:.c=.o} $(MAINSRC:.c=.o) 
OBJDIR = ./obj
LIBD =./include

.PHONY: all clean	

all: $(PROGRAM)

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@
$(PROGRAM): $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -f  $(PROGRAM) $(OBJS)
