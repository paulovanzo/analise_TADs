#include <time.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include "../include/pilha.h"
#include "../include/fila.h"

int main (){
	std::ifstream arquivo;

	int vetor[15] = {3, 6, 4, 21, 3, 54, 7, 30, 12, 34, 21, 34, 32, 90, 54};

	// INSERÇÃO -------------------------------------------------------------------------------------------

	for (int j = 0; j < 15; j++) {
		std::cout << "Teste com " << j + 1 << " elemento: \n";
		Pilha<int> pilha;
		auto inicioPilha = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < j; i++) {
			pilha.push(vetor[i]);
		}
		auto fimPilha = std::chrono::high_resolution_clock::now() - inicioPilha;
		long long tempoUsadoPilha = std::chrono::duration_cast<std::chrono::nanoseconds>(fimPilha).count();
		std::cout << "Tempo de inserção da pilha: " << tempoUsadoPilha << " nanosegundos\n";

		Fila<int> fila;
		auto inicioFila = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < j; i++) {
			fila.inserir(vetor[i]);
		}
		auto fimFila = std::chrono::high_resolution_clock::now() - inicioFila;
		long long tempoUsadoFila = std::chrono::duration_cast<std::chrono::nanoseconds>(fimFila).count();
		std::cout << "Tempo de inserção da fila: " << tempoUsadoFila << " nanosegundos\n";

		// REMOÇÃO -------------------------------------------------------------------------------------------

		inicioPilha = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < j; i++) {
			pilha.pop();
		}
		fimPilha = std::chrono::high_resolution_clock::now() - inicioPilha;
		tempoUsadoPilha = std::chrono::duration_cast<std::chrono::nanoseconds>(fimPilha).count();
		std::cout << "Tempo de remoção da pilha: " << tempoUsadoPilha << " nanosegundos\n";

		inicioFila = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < j; i++) {
			fila.remover();
		}
		fimFila = std::chrono::high_resolution_clock::now() - inicioFila;
		tempoUsadoFila = std::chrono::duration_cast<std::chrono::nanoseconds>(fimFila).count();
		std::cout << "Tempo de remoção da fila: " << tempoUsadoFila << " nanosegundos\n\n";
	}
	return 0;
}