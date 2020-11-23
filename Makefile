all:
	mkdir -p bin
	g++ -Wall -pedantic src/cronometragem.cpp src/rand.cpp -o bin/cronometragem
run:
	bin/./cronometragem