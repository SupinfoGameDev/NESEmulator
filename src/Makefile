CC=g++
CXXFLAGS=-std=c++1y -Wall -Wextra -pedantic
EXEC=emulator

emulator: clean
	$(CC) $(CXXFLAGS) *.cc -o $(EXEC)

clean:
	rm -rf *.o *.h.gch a.out $(EXEC)
