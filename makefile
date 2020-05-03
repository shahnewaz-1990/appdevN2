OBJ = screen.o testscreen.o comm.o 
APPNAME = testscreen

#linking rule
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lcurl
	
#compiling rule
%.o : %.c
	gcc -c -o $@ $<

#cleaning rule
clean:
	rm $(APPNAME) $(OBJ)
#archiving rule
zip :
	tar cf screen.tar *.c *.h makefile
