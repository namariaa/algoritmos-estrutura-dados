#ifndef pilhaDinamica
#define pilhaDinamica
#include <iostream>
#include "EPilhaVazia.cpp"

using namespace std;

class PilhaDinamica {
private:
    int *stack;
    int topo;
    int capacidade;
    
public:    
    int size;
    void iniciaPilha() {
        this->topo = -1;
    }

   PilhaDinamica(int capacidade) {
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

    void aumentarCapacidade() {
        int *newStack = new int[this->capacidade * 2];
        for (int i = 0; i < this->capacidade; i++) {
            newStack[i] = this->stack[i];
        }
        delete[] this->stack; 
        this->stack = newStack;
        this->capacidade = this->capacidade * 2;
        return;
    }
    
    void empilha(int value) {
        if (this->capacidade == this->size) {
            aumentarCapacidade();
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
        return this->stack[this->topo + 1];
    }
};

#endif