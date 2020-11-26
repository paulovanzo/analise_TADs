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

	std::ofstream pilhaA;
	std::ofstream pilhaI;
	std::ofstream filaA;
	std::ofstream filaI;

	// generate();

	input.open("./data/vetor.txt");

	std::cout << input.fail() << std::endl;

	if( input.is_open() ){
		
		pilhaI.open("./data/pilhaInsert.txt");
		pilhaA.open("./data/pilhaAcess.txt");
		filaI.open("./data/filaInsert.txt");
		filaA.open("./data/filaAcess.txt");

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

				pilha.push(vetor[k]);

				auto fimPilha = std::chrono::high_resolution_clock::now() - inicioPilha;
				long long tempoUsadoPilha = std::chrono::duration_cast<std::chrono::nanoseconds>(fimPilha).count();
				PilhaMediaI = tempoUsadoPilha + PilhaMediaI;
				

				Fila<int> fila;
				auto inicioFila = std::chrono::high_resolution_clock::now();

				fila.inserir(vetor[k]);
				
				auto fimFila = std::chrono::high_resolution_clock::now() - inicioFila;
				long long tempoUsadoFila = std::chrono::duration_cast<std::chrono::nanoseconds>(fimFila).count();
				FilaMediaI = tempoUsadoFila + FilaMediaI;

				for (int i = 0; i < tam; i++) {
					pilha.push(vetor[i]);
				}

				for (int i = 0; i < tam; i++) {
					fila.inserir(vetor[i]);
				}
				
				// ACESSO -------------------------------------------------------------------------------------------

				inicioPilha = std::chrono::high_resolution_clock::now();

				pilha.at(tam-1);

				fimPilha = std::chrono::high_resolution_clock::now() - inicioPilha;
				tempoUsadoPilha = std::chrono::duration_cast<std::chrono::nanoseconds>(fimPilha).count();
				PilhaMediaA = tempoUsadoPilha + PilhaMediaA;
				
				inicioFila = std::chrono::high_resolution_clock::now();

				fila.at(tam-1);

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

			pilhaI << std::fixed << std::setprecision(2) << tam << " " << PilhaMediaI << std::endl;
			filaI << std::fixed << std::setprecision(2) << tam << " " << FilaMediaI << std::endl;
			pilhaA << std::fixed << std::setprecision(2) << tam << " " << PilhaMediaA << std::endl;
			filaA << std::fixed << std::setprecision(2) << tam << " " << FilaMediaA << std::endl;

		}
	}

	pilhaI.close();
	filaI.close();
	pilhaA.close();
	filaA.close();
	
	return 0;
}