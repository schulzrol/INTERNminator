PROGRAM = maxinarr

All: $(PROGRAM)
.PHONY: all clean	

%.o: %.c
	gcc -c -o $@  $< 
$(PROGRAM): NejvetsiVNahPoli.o
	gcc $? -o $@
clean:
	rm -f  $(PROGRAM) *.o
	 
