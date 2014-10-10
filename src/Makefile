CC=g++
CXXFLAGS=-std=c++1y -Wall -Wextra -pedantic
EXEC=emulator

emulator: clean
	$(CC) $(CXXFLAGS) *.cc -o $(EXEC)

clean:
	rm -rf *.o *.cc~ *.h.gch a.out $(EXEC)
