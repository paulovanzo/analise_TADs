#include <time.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "../include/pilha.h"
#include "../include/fila.h"
#include "../include/rand.h"

void StrParaInt(int* vetor, std::string &str){

	for(long int i{0}; i < ( str.end() - str.begin() ); ++i){
		if(*(str.begin() + i)!= ' '){
			*(vetor+i) = *(str.begin() + i) - 48;
		}		
	}
	
}

int main (){
	std::ifstream input;

	std::ofstream outputR;
	std::ofstream outputI;

	generate();

	input.open("./data/vetor.txt");

	std::cout << input.fail() << std::endl;

	if( input.is_open() ){
		
		outputI.open("./data/outputInsert.txt");
		outputR.open("./data/outputRemove.txt");

		for (int tam = 50; tam <= 5000; tam+=50) {

			std::cout << "Teste com " << tam << " elementos:\n\n";

			long double PilhaMediaI{0};
			long double FilaMediaI{0};

			long double PilhaMediaR{0};
			long double FilaMediaR{0};

			for(int k =0 ; k < 50; k++){

				std::string str;
				
				std::getline(input,str);

				int vetor[(str.end() - str.begin())];

				StrParaInt(vetor, str);

				// INSERÇÃO -------------------------------------------------------------------------------------------

				Pilha<int> pilha(tam);
				auto inicioPilha = std::chrono::high_resolution_clock::now();

				for (int i = 0; i < tam; i++) {
					pilha.push(vetor[i]);
				}

				auto fimPilha = std::chrono::high_resolution_clock::now() - inicioPilha;
				long long tempoUsadoPilha = std::chrono::duration_cast<std::chrono::nanoseconds>(fimPilha).count();
				PilhaMediaI = tempoUsadoPilha + PilhaMediaI;
				

				Fila<int> fila;
				auto inicioFila = std::chrono::high_resolution_clock::now();

				for (int i = 0; i < tam; i++) {
					fila.inserir(vetor[i]);
				}

				auto fimFila = std::chrono::high_resolution_clock::now() - inicioFila;
				long long tempoUsadoFila = std::chrono::duration_cast<std::chrono::nanoseconds>(fimFila).count();
				FilaMediaI = tempoUsadoFila + FilaMediaI;
				
				
				// REMOÇÃO -------------------------------------------------------------------------------------------

				inicioPilha = std::chrono::high_resolution_clock::now();

				for (int i = 0; i < tam; i++) {
					pilha.pop();
				}

				fimPilha = std::chrono::high_resolution_clock::now() - inicioPilha;
				tempoUsadoPilha = std::chrono::duration_cast<std::chrono::nanoseconds>(fimPilha).count();
				PilhaMediaR = tempoUsadoPilha + PilhaMediaR;
				
				inicioFila = std::chrono::high_resolution_clock::now();

				for (int i = 0; i < tam; i++) {
					fila.remover();
				}

				fimFila = std::chrono::high_resolution_clock::now() - inicioFila;
				tempoUsadoFila = std::chrono::duration_cast<std::chrono::nanoseconds>(fimFila).count();
				FilaMediaR = tempoUsadoFila + FilaMediaR;
				
			}

			PilhaMediaI = PilhaMediaI/50;
			FilaMediaI = FilaMediaI/50;
			PilhaMediaR = PilhaMediaR/50;
			FilaMediaR = FilaMediaR/50;

			std::cout << "Tempo de inserção da pilha [" << tam << "]: " << PilhaMediaI << " nanosegundos\n\n";
			std::cout << "Tempo de inserção da fila [" << tam << "]: " << FilaMediaI << " nanosegundos\n\n";
			std::cout << "Tempo de remoção da pilha [" << tam << "]: " << PilhaMediaR << " nanosegundos\n\n";
			std::cout << "Tempo de remoção da fila [" << tam << "]: " << FilaMediaR << " nanosegundos\n\n";

			outputI << std::fixed << std::setprecision(2) << PilhaMediaI << " " << FilaMediaI << "\n";
			outputR << std::fixed << std::setprecision(2) << PilhaMediaR << " " << FilaMediaR << "\n";

		}
	}

	outputI.close();
	outputR.close();
	
	return 0;
}