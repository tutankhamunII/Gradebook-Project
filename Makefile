CC=g++
# If you want to use the debugger, add -g to CFLAGS
CFLAGS=-Wall -Werror -std=c++11 -I.
DEPS = Color.h Parsing.h Course.h Gradeditem.h  Student.h
# TODO You'll need to change the next line
OBJ = Color.o Course.o Gradeditem.o Student.o Parsing.o Gradebook.o 

%.o: %.cpp %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Gradebook: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o Gradebook