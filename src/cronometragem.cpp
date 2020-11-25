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

	std::ofstream outputA;
	std::ofstream outputI;

	generate();

	input.open("./data/vetor.txt");

	std::cout << input.fail() << std::endl;

	if( input.is_open() ){
		
		outputI.open("./data/outputInsert.txt");
		outputA.open("./data/outputAcess.txt");

		for (int tam = 50; tam <= 5000; tam+=50) {

			std::cout << "Teste com " << tam << " elementos:\n\n";

			long double PilhaMediaI{0};
			long double FilaMediaI{0};

			long double PilhaMediaA{0};
			long double FilaMediaA{0};

			for(int k = 0 ; k < 50; k++){

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
				
				
				// ACESSO -------------------------------------------------------------------------------------------

				inicioPilha = std::chrono::high_resolution_clock::now();

				pilha.at(tam);

				fimPilha = std::chrono::high_resolution_clock::now() - inicioPilha;
				tempoUsadoPilha = std::chrono::duration_cast<std::chrono::nanoseconds>(fimPilha).count();
				PilhaMediaA = tempoUsadoPilha + PilhaMediaA;
				
				inicioFila = std::chrono::high_resolution_clock::now();

				fila.at(tam);

				fimFila = std::chrono::high_resolution_clock::now() - inicioFila;
				tempoUsadoFila = std::chrono::duration_cast<std::chrono::nanoseconds>(fimFila).count();
				FilaMediaA = tempoUsadoFila + FilaMediaA;
				
			}

			PilhaMediaI = PilhaMediaI/50;
			FilaMediaI = FilaMediaI/50;
			PilhaMediaA = PilhaMediaA/50;
			FilaMediaA = FilaMediaA/50;

			std::cout << "Tempo de inserção da pilha [" << tam << "]: " << PilhaMediaI << " nanosegundos\n\n";
			std::cout << "Tempo de inserção da fila [" << tam << "]: " << FilaMediaI << " nanosegundos\n\n";
			std::cout << "Tempo de acesso da pilha [" << tam << "]: " << PilhaMediaA << " nanosegundos\n\n";
			std::cout << "Tempo de acesso da fila [" << tam << "]: " << FilaMediaA << " nanosegundos\n\n";

			outputI << std::fixed << std::setprecision(2) << PilhaMediaI << " " << FilaMediaI << "\n";
			outputA << std::fixed << std::setprecision(2) << PilhaMediaA << " " << FilaMediaA << "\n";

		}
	}

	outputI.close();
	outputA.close();
	
	return 0;
}