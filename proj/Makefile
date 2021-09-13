make:
	g++ -c search.cpp
	g++ -c result.cpp
	g++ -c main.cpp
	g++ -c helpfunctions.cpp
	g++ -o main main.o search.o result.o helpfunctions.o -static-libgcc -static-libstdc++ -static -lpthread
	strip main.exe
	make clean

clean:
	rm helpfunctions.o main.o result.o search.o
