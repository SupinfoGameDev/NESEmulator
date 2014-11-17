CC=g++
CLANG=clang++
OBJ=cpu.o graphics.o tools.o
CXXFLAGS=-std=c++1y -Wall -Werror -Wextra -pedantic-errors -Wold-style-cast \
	-Woverloaded-virtual -Wfloat-equal  -Wconversion -Wswitch-enum -Wundef -Winline
EXEC=emulator

emulator: $(OBJ)
	@echo "MAKING EMULATOR"
	$(CLANG) $(CXXFLAGS) -DDEBUG $(OBJ) main.cc -o $(EXEC)
	@echo "DONE"

cpu.o:
	@echo "MAKING CPU"
	$(CLANG) -c $(CXXFLAGS) -O2 cpu/cpu.cc
	@echo "DONE"
    
graphics.o:
	@echo "MAKING GRAPHICS"
	$(CLANG) -c $(CXXFLAGS) -O2 graphics/Window.cc graphics/graphics.cc
	@echo "DONE"
    
tools.o:
	@echo "MAKING TOOLS"
	$(CLANG) -c $(CXXFLAGS) -O2 tools/tools.cc
	@echo "DONE"

run:
	./$(EXEC)

clean:
	@rm -rf *.o *.cc~ Makefile~ *.h.gch a.out $(EXEC)
	@echo "DONE"
