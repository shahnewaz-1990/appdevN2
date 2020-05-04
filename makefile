OBJ = screen.o main.o comm.o sound.o 
APPNAME = sound

#linking rule
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lcurl -lm
#compiling rule
%.o : %.c
	gcc -c -o $@ $<

#cleaning rule
clean:
	rm $(APPNAME) $(OBJ)
#archiving rule
zip :
	tar cf screen.tar *.c *.h makefile
