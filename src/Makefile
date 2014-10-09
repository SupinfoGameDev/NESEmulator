CC=g++
CXXFLAGS=-std=c++1y -Werror -pedantic

EXEC=emulator

emulator: clean
	$(CC) $(CXXFLAGS) *.cc -o $(EXEC)

clean:
	rm -f *.o a.out $(EXEC)
