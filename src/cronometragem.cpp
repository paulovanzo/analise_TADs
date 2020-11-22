#include <time.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include "../include/pilha.h"
#include "../include/fila.h"

int main (){
	std::ifstream arquivo;

	Pilha<int> pilha;
	auto inicioPilha = std::chrono::high_resolution_clock::now();
	pilha.push(1);
	auto fimPilha = std::chrono::high_resolution_clock::now() - inicioPilha;
	long long tempoUsadoPilha = std::chrono::duration_cast<std::chrono::nanoseconds>(fimPilha).count();

	Fila<int> fila;
	auto inicioFila = std::chrono::high_resolution_clock::now();
	fila.inserir(1);
	auto fimFila = std::chrono::high_resolution_clock::now() - inicioFila;
	long long tempoUsadoFila = std::chrono::duration_cast<std::chrono::nanoseconds>(fimFila).count();

	return 0;
}