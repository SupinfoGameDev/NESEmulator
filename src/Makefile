CC=g++
CXXFLAGS=-std=c++14 -DDEBUG -Wall -Werror -Wextra -pedantic
EXEC=emulator

emulator: clean
	$(CC) $(CXXFLAGS) *.cc -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm -rf *.o *.cc~ ../include/*.h.gch a.out $(EXEC)
