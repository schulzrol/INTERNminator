PROGRAM = NIM
MAINSRC = nim.c
CC = gcc

.PHONY : all clean

all : $(PROGRAM)

$(PROGRAM) : $(MAINSRC)
	$(CC) -c $^ -o $@

clean:
	rm -f $(PROGRAM) $(MAINSRC:.c=.o)
