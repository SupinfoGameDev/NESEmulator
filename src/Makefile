CC=g++
CLANG=clang++
OBJ=cpu.o graphics.o tools.o
CXXFLAGS=-std=c++1y -pedantic-errors -Wall -Wdeprecated-writable-strings -Werror -Wextra -Wsign-conversion -Wswitch-enum -Wtype-limits -Wundef -Wunused-variable 
EXEC=emulator

# Warnings:
# @> -std=c++1y > activation de C++14
# @> -Wall > active davantage de warnings (-Wunused-function, -Wswitch, -Wunused-local-typedef, -Wmaybe-uninitialized entre autres)
# @> -Wdeprecated-writable-strings > utilisation de char* au lieu de std::string char* const
# @> -Werror > transforme les warnings en erreurs
# @> -Wextra > active davantage de warnings (-Wuninitialized, -Wunused-parameter, -Wunused-but-set-parameter, -Wsign-compare entre autres)
# @> -Wsign-conversion > conversions implicites signé / non signé
# @> -Wswitch-enum > tous les cas d'une enum doivent être testés dans un switch
# @> -Wtype-limits > comparaison signé / non signé
# @> -Wundef > si on teste dans un #if une macro non définie
# @> -Wunused-variable > variables non utilisées

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

