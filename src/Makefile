CC=g++
CLANG=clang++
OBJ=core.o graphics.o cpu.o tools.o
CXXFLAGS= -Wall -Werror -Wextra -pedantic-errors \
-Wold-style-cast -Woverloaded-virtual -Wfloat-equal \
-Wconversion -Wswitch-enum -Wundef -Winline
EXEC=emulator

emulator: clean
	$(CC) -std=c++14 $(CXXFLAGS) -O2 *.cc graphics/graphics.cc graphics/Window.cc tools/tools.cc -o $(EXEC)

clang: clean
	$(CLANG) -std=c++1y $(CXXFLAGS) -O2 *.cc graphics/graphics.cc graphics/Window.cc tools/tools.cc -o $(EXEC)
	
debug: clean
	$(CC) $(CXXFLAGS) -DDEBUG *.cc -o $(EXEC)
	
run:
	./$(EXEC)

clean:
	rm -rf *.o *.cc~ Makefile~ *.h.gch a.out $(EXEC)
