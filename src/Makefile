DEBUG=yes
# Ajout de la macro DEBUG ou du flag O2 selon la config (debug / release)
ifeq ($(DEBUG),yes)
  CONFIG_FLAG=-DDEBUG
else
  CONFIG_FLAG=-O2
endif

# Compilateur utilisé
CLANG=clang++
# Fichiers objets (.o) -> 1 par dossier / module
OBJ=core.o cpu.o graphics.o tools.o
# Différents fichiers selon les modules
CORE=core/core.cc core/core.h core/RomReader.cc core/RomReader.h
CPU=cpu/cpu.cc cpu/cpu.h
GRAPHICS=graphics/graphics.cc graphics/Window.cc graphics/graphics.h graphics/Window.h
TOOLS=tools/tools.cc tools/NonCopyable.h
# Nom de l'exécutable
EXEC=emulator
# Flags clang++
CXXFLAGS=-std=c++1y -pedantic-errors -Wall -Wdeprecated-writable-strings -Werror \
         -Wextra -Wsign-conversion -Wswitch-enum -Wtype-limits -Wundef -Wunused-variable 

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

emulator: clean main.cc $(OBJ)
	@echo "MAKING EMULATOR"
	@$(CLANG) $(CXXFLAGS) $(CONFIG_FLAG) $(OBJ) main.cc -o $(EXEC)
	@echo "DONE"

core.o: $(CORE)
	@echo "MAKING CORE"
	@$(CLANG) -c $(CXXFLAGS) $(CONFIG_FLAG) core/core.cc core/RomReader.cc
	@echo "DONE"
	
cpu.o: $(CPU)
	@echo "MAKING CPU"
	@$(CLANG) -c $(CXXFLAGS) $(CONFIG_FLAG) cpu/cpu.cc
	@echo "DONE"
    
graphics.o: $(GRAPHICS)
	@echo "MAKING GRAPHICS"
	@$(CLANG) -c $(CXXFLAGS) $(CONFIG_FLAG) graphics/Window.cc graphics/graphics.cc
	@echo "DONE"
    
tools.o: $(TOOLS)
	@echo "MAKING TOOLS"
	@$(CLANG) -c $(CXXFLAGS) $(CONFIG_FLAG) tools/tools.cc
	@echo "DONE"

run:
	@./$(EXEC)

clean:
	@echo "DELETING FILES"
	@rm -rf *.o *.cc~ Makefile~ *.h.gch a.out $(EXEC)
	@echo "DONE"

