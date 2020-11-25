#ifndef FILA
#define FILA

template < typename T >
class Fila{
    private:
        T* elementos;
        size_t tam;
        size_t capacidade;
    public:
        Fila();
        Fila( int capacidade );
        ~Fila();
        bool empty();
        bool full();
        void inserir( T num );
        T& at(size_t index);
        T& remover();
        T& first();
        void print();
};


template < typename T>
Fila<T>::Fila(){
    tam = 0;
    capacidade = 50;
    elementos = new T[50];
}

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
void Fila<T>::inserir( T num ){

    if( full() ){

        capacidade = 2*capacidade;
        T* novos_elementos = new T[capacidade];

        for (size_t i = 0; i < (capacidade/2); ++i){
            novos_elementos[i] = elementos[i];
        }

        delete[] elementos;
        elementos = novos_elementos;

    }

    elementos[tam] = num;
    tam++;

}

template < typename T>
T& Fila<T>::first(){

    if( empty() ){
        return 0;
    }
    return elementos[0];
}

template < typename T>
T& Fila<T>::at(size_t idx){

    T* ptr;

    if(idx > tam){
        return nullptr;
    }

    for(size_t i{0}; i < idx; ++i){
        ptr = remover();
    }
    
    return ptr;
}

template < typename T>
T& Fila<T>::remover(){

    if( empty() ){
        return 0;
    }
    T var = elementos[0];

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