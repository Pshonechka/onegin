
.PHONY: clean run build
#target: dependences
#      command
CC = g++

CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D _DEBUG -D _EJUDGE_CLIENT_SIDE

build: solver

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

InputFunctions.o: InputFunctions.cpp
	$(CC) $(CFLAGS) -c InputFunctions.cpp

PrintFunctions.o: PrintFunctions.cpp
	$(CC) $(CFLAGS) -c PrintFunctions.cpp

SizeFunctions.o: SizeFunctions.cpp
	$(CC) $(CFLAGS) -c SizeFunctions.cpp

SortFunctions.o: SortFunctions.cpp
	$(CC) $(CFLAGS) -c SortFunctions.cpp

solver: main.o InputFunctions.o PrintFunctions.o SizeFunctions.o SortFunctions.o
	$(CC) $(CFLAGS) main.o InputFunctions.o PrintFunctions.o SizeFunctions.o SortFunctions.o -o solver

clean:
	rm -rf *.o

main_test: main_test.o
	$(CC) $(CFLAGS) main_test.o -o main_test

run:
	.\solver.exe
