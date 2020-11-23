#include <ctime>
#include <fstream>
#include <iostream>
#include "../include/rand.h"

void generate(){

  std::ofstream arquivo;

	arquivo.open("./data/vetor.txt");

  srand(time(NULL));

  if( arquivo.fail() ){
    std::cerr << "Arquivo não encontrado" << std::endl;
  }else{

    for (int tam = 50; tam <= 5000; tam+=50){
      for(int k = 0; k < 50; k++){
        for (int i = 0; i < tam; ++i){ 
          arquivo << 1+rand()%9 << " ";
        }
        arquivo << "\n";
      }
    }

    arquivo.close();
    
  }

}