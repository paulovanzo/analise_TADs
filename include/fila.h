#ifndef FILA
#define FILA

#include <iostream>

template < typename T >
class Fila{
    private:
        T* elementos;
        size_t tam;
        size_t capacidade;
    public:
        Fila( int capacidade );
        ~Fila();
        bool empty();
        bool full();
        Fila<T>& copy( Fila<T> &F);
        void inserir( int num );
        T remover();
        void print();
};

template < typename T>
Fila<T>::Fila( int capacidade_ ){
    tam = 0;
    capacidade = capacidade_;
    elementos = new T[capacidade_];
}

template < typename T>
Fila<T>::~Fila(){

    elementos = nullptr;

    delete[] elementos;

}

template < typename T>
bool Fila<T>::empty(){

    return tam == 0 ? true : false;

}

template < typename T>
bool Fila<T>::full(){

    return tam == capacidade ? true : false;

}

template < typename T>
Fila<T>& Fila<T>::copy( Fila<T> &F){

    elementos = F.elementos;
    tam = F.tam;
    capacidade = F.capacidade;

    return *this;
}

template < typename T>
void Fila<T>::inserir( int num ){

    if( full() ){
        return;
    }

    elementos[tam] = num;

    std::cout << "Elemento de Fila inserido: [" << tam << "] " << elementos[tam] << std::endl;
    
    tam++;

}

template < typename T>
T Fila<T>::remover(){

    if( empty() ){
        return 0;
    }
    T var = elementos[0];

    std::cout << "Elemento de Fila removido no índice 0: " << elementos[0] << std::endl;


    elementos++;
    tam--;

    return var;
}

template < typename T>
void Fila<T>::print(){

    if( empty() ){
        std::cerr << "Fila vazia" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Elementos da fila:" << std::endl;

    for(size_t i{0}; i < tam; ++i){
        std::cout << "Fila [" << i << "]: "<< elementos[i] << std::endl;
    }
}

#endif