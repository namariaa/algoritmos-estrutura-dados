#ifndef pilha
#define pilha
#include <iostream>
#include "EPilhaVazia.cpp"

using namespace std;

class Pilha {
private:
    int *stack;
    int topo;
    int capacidade;
    
public:    
    int size;
    void iniciaPilha() {
        this->topo = -1;
    }

   Pilha(int capacidade) {
        iniciaPilha();
        this->capacidade = capacidade;
        this->size = 0;
        this->stack = new int[capacidade];
    }

    bool pilhaVazia() {
        if (this->topo == -1) {
            return true;
        } else {
            return false;
        }
    }

    void empilha(int value) {
        if (this->capacidade == this->size) {
            throw EPilhaVazia("A Pilha excedeu a capacidade!");
        }
        this->topo = this->topo + 1; 
        this->stack[this->topo] = value;
        this->size = this->size + 1;
    }

    int desempilha() {
        if (pilhaVazia()) {
            throw EPilhaVazia("A Pilha está vazia!");
        }
        this->topo = this->topo - 1; 
        this->size = this->size - 1;
        return this->stack[this->topo + 1];
    }
};

#endif