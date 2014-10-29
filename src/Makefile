CC=g++
CXXFLAGS=-std=c++14 -DDEBUG -Wall -Werror -Wextra -pedantic-errors \
-Wold-style-cast -Woverloaded-virtual -Wfloat-equal \
-Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align \
-Wconversion -Wshadow -Winit-self -Wswitch-default \
-Wswitch-enum -Wundef -Wlogical-op -Winline
EXEC=emulator

emulator: clean
	$(CC) $(CXXFLAGS) *.cc -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm -rf *.o *.cc~ Makefile~ ../include/*.h.gch a.out $(EXEC)
