#ifndef fila
#define fila
#include <iostream>
#include "EFilaError.cpp"

using namespace std;

class Fila {
private:
    int *query;
    int begin;
    int end;
    int capacidade;
    
public:    
    int size;
    void inciaFila() {
        this->begin = -1;
        this->end = -1;
    }

    Fila(int capacidade) {
        inciaFila();
        this->capacidade = capacidade;
        this->size = 0;
        this->query = new int[capacidade];
    }

    bool filaVazia() {
        if (this->size == 0) return true;
        return false;
    }

    void insere(int value) {
        if (this->capacidade == this->size) {
            throw EFilaError("A fila está excedendo a capacidade!");
        } 
        this->size = this->size + 1;
        if (this->capacidade == this->end + 1) this->end = 0;
        else this->end = this->end + 1;
        this->query[end] = value; 
    }
    
    int remove() {
        if (filaVazia()) {
            throw EFilaError("A fila  está vazia!");
        }
        if (this->capacidade == this->begin + 1) this->begin = 0;
        else this->begin = this->begin + 1;
        int oldElement = this->query[this->begin];
        this->size = this->size - 1;
        return oldElement;
    }
};

#endif