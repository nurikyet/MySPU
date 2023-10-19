CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: hello.exe

hello.exe: SPU.o Commands.o SpeakCommands.o MainForSPU.o
	$(CC) $(CFLAGS) $^ -o $@

MainForSPU.o: MainForSPU.cpp SPU.h logfile.h
	$(CC) $(CFLAGS) $< -c -o $@

SPU.o: SPU.cpp SPU.h ..\MyCommands.h Commands.h SpeakCommands.h ..\Types.h ..\TotalFile.h Stack.h logfile.h
	$(CC) $(CFLAGS) $< -c -o $@

Commands.o: Commands.cpp Commands.h SPU.h ..\Types.h ..\TotalFile.h Stack.h
	$(CC) $(CFLAGS) $< -c -o $@

logfile.o: logfile.cpp lofgile.h ..\Types.h Stack.h
	$(CC) $(CFLAGS) $< -c -o $@

Stack.o: Stack.cpp Stack.h Hash.h logfile.h Error.h ..\Types.h
	$(CC) $(CFLAGS) $< -c -o $@

SpeakCommands.o:SpeakCommands.cpp SpeakCommands.h
	$(CC) $(CFLAGS) $< -c -o $@

Error.o: Error.cpp Error.h Hash.h Stack.h logfile.h ..\Types.h
	$(CC) $(CFLAGS) $< -c -o $@

ErrorsForSPU.o: ErrorsOfSPU.h ..\TotalFile.h Stack.h logfile.h
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: all clean

clean:
	rm *.o
