DEBUG=yes
# Ajout de la macro DEBUG ou du flag O2 selon la config (debug / release)
ifeq ($(DEBUG),yes)
  CONFLIG_FLAG=-DDEBUG
else
  CONFLIG_FLAG=-O2
endif

CLANG=clang++
OBJ=cpu.o graphics.o tools.o
CXXFLAGS=-std=c++1y -pedantic-errors -Wall -Wdeprecated-writable-strings -Werror -Wextra -Wsign-conversion -Wswitch-enum -Wtype-limits -Wundef -Wunused-variable 
CPU=cpu/cpu.cc cpu/bit_array.h cpu/instructions.h
GRAPHICS=graphics/graphics.cc graphics/Window.cc graphics/graphics.h graphics/Window.h
TOOLS=tools/tools.cc tools/NonCopyable.h
EXEC=emulator

# Flags:
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
	@$(CLANG) $(CXXFLAGS) $(CONFLIG_FLAG) $(OBJ) main.cc -o $(EXEC)
	@echo "DONE\n"

cpu.o: $(CPU)
	@echo "MAKING CPU"
	@$(CLANG) -c $(CXXFLAGS) $(CONFLIG_FLAG) cpu/cpu.cc
	@echo "DONE\n"
    
graphics.o: $(GRAPHICS)
	@echo "MAKING GRAPHICS"
	@$(CLANG) -c $(CXXFLAGS) $(CONFLIG_FLAG) graphics/Window.cc graphics/graphics.cc
	@echo "DONE\n"
    
tools.o: $(TOOLS)
	@echo "MAKING TOOLS"
	@$(CLANG) -c $(CXXFLAGS) $(CONFLIG_FLAG) tools/tools.cc
	@echo "DONE\n"

run:
	@./$(EXEC)

clean:
	@echo "DELETING FILES"
	@rm -rf *.o *.cc~ Makefile~ *.h.gch a.out $(EXEC)
	@echo "DONE\n"

