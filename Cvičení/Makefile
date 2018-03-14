PROGRAM = maxinarr
CC = gcc
SRCS = main.c assignRandoms.c IndexNejvetsiho.c printHelp.c
HEADERS = ${SRCS:.c=.h}
OBJS = ${SRCS:.c=.o}
LIBD =.\include

.PHONY: all clean	

All: $(PROGRAM)

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@
$(PROGRAM): $(OBJS)
	$(CC) $? -o $@
clean:
	rm -f  $(PROGRAM) $(OBJS)
	 
