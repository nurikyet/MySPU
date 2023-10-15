CC=g++
CFLAGS=-c -Wall
LDFLAGS=

SOURCES=SPU.cpp Stack.cpp Main.cpp logfile.cpp Hash.cpp Error.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.%.o : %.cpp

.PHONY: clean
clean:
	rm -rf hello *.o
