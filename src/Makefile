CC=g++
CLANG=clang++
OBJ=cpu.o graphics.o tools.o
CXXFLAGS=-std=c++1y -Wall -Werror -Wextra -pedantic-errors \
-Wold-style-cast -Woverloaded-virtual -Wfloat-equal \
-Wconversion -Wswitch-enum -Wundef -Winline
EXEC=emulator

emulator: $(OBJ)
	$(CLANG) $(CXXFLAGS) -DDEBUG -O2 $(OBJ) main.cc -o $(EXEC)

cpu.o:
	$(CLANG) -c $(CXXFLAGS) -O2 cpu/cpu.cc
    
graphics.o:
	$(CLANG) -c $(CXXFLAGS) -O2 graphics/Window.cc graphics/graphics.cc 
    
tools.o:
	$(CLANG) -c $(CXXFLAGS) -O2 tools/tools.cc

clang: clean
	$(CLANG) $(CXXFLAGS) -O2 *.cc graphics/graphics.cc graphics/Window.cc tools/tools.cc -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm -rf *.o *.cc~ Makefile~ *.h.gch a.out $(EXEC)
