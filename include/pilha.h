#ifndef PILHA
#define PILHA

#include <string>
 
template <typename T>
class Pilha {
private:
  T* elementos;   // Elementos armazenados na pilha
  int tamanho;    // Qtde atual de elementos
  int capacidade; // Qtde Max de elementos
public:
  Pilha (int n_capacidade = 50);
  ~Pilha ();
  bool empty ();  // Se a pilha está vazia
  bool full (); // Se a pilha está cheia
  T& top (); // retorna a referência para o elemento do topo
  T& at(int index); // retorna a referência do elemento na I-ésima posição
  void push ( T novo ); // insere na fila
  void pop (); // remove o primeiro elemento
  int size();
};
 
template <typename T>
Pilha<T>::Pilha (int n_capacidade): tamanho(0), capacidade(n_capacidade){
  elementos = new T[n_capacidade];
}
template <typename T>
Pilha<T>::~Pilha (){
  delete [] elementos;
}
 
template <typename T>
bool Pilha<T>::empty (){
  return tamanho == 0;
}

template <typename T>
bool Pilha<T>::full (){
  return tamanho == capacidade;
}

template < typename T>
T& Pilha<T>::at(int idx){

    if(idx > tamanho){
        std::cerr << "Acesso a indices invalidos. O programa sera fechado!" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i{0}; i < idx-1; ++i){
        pop();
    }
    return top();
}
 
template <typename T>
void Pilha<T>::push ( T novo ){
  if (full()){
    capacidade = 2*capacidade;    
    T* novos_elementos = new T[capacidade];

    for (int i = 0; i < (capacidade/2); ++i){
      novos_elementos[i] = elementos[i];
    }

    elementos = nullptr;

    delete[] elementos;
    elementos = novos_elementos;

  }
  
  elementos[tamanho++] = novo;
  
}
 
template <typename T>
void Pilha<T>::pop (){

  if (empty())
    return;
  
  tamanho--;
}
 
template <typename T>
T& Pilha<T>::top(){ 
  if (empty()) {
    std::cerr << "Acesso invalido a elemento no topo. O programa sera fechado!" << std::endl;
    exit(EXIT_FAILURE);
  }
  return elementos[tamanho-1];
}
 
template <typename T>
int Pilha<T>::size(){
  return tamanho;
}

#endif