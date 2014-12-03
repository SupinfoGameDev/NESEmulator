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
OBJ=core.o cpu.o graphics.o
SFMLOBJ=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# Différents fichiers selon les modules
CORE=core/core.cc core/RomReader.cc
CPU=cpu/cpu.cc
GRAPHICS=graphics/graphics.cc
TOOLS=tools/tools.cc
# Nom de l'exécutable
EXEC=emulator
# Flags clang++
CXXFLAGS=-std=c++1y -pedantic-errors -Wall -Wdeprecated-writable-strings -Werror \
         -Wextra -Wsign-conversion -Wswitch-enum -Wtype-limits -Wundef -Wunused-variable -pthread
SOURCES=$(CORE) $(CPU) $(GRAPHICS) $(TOOLS) main.cc
OBJECTS=$(SOURCES:.cpp=.o)
LIBS=lib/lua5.2.3.a

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

#emulator: main.cc $(SFMLOBJ) $(CORE) $(GRAPHICS) $(TOOLS)
#	@echo "MAKING EMULATOR"
#	@$(CLANG) $(CXXFLAGS) $(CONFIG_FLAG) -ldl  $(SFMLOBJ) $(CORE) $(GRAPHICS) $(TOOLS)  main.cc -o $(EXEC) 
#	@echo "DONE"

$(EXEC): clean $(SFMLOBJ)
	@echo "MAKING EMULATOR"
	@$(CLANG) $(CXXFLAGS) $(SFMLOBJ) $(SOURCES) -o $@ -lm -ldl -DLUA_OK $(LIBS)
	@echo "DONE"

nolua: clean $(SFMLOBJ)
	@echo "MAKING EMULATOR (NO LUA)"
	@$(CLANG) $(CXXFLAGS) $(SFMLOBJ) $(SOURCES) -o $(EXEC) $(LIBS)
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

