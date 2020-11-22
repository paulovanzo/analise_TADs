#include <ctime>
#include <fstream>
#include "../include/rand.h"

void generate(){

  std::ofstream arquivo;

	arquivo.open(("../data/vetor.txt"));

  srand(time(NULL));

  for (int tam = 0; tam < 15; tam++){
    for (int i = 0; i < tam; ++i){ 
      arquivo << 1+rand()%tam << " ";
    }
    arquivo << "\n";
  }

	arquivo.close();

}