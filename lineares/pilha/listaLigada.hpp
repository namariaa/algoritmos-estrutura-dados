#ifndef pilhaPonteiro
#define pilhaPonteiro
#include <iostream>
#include "EPilhaVazia.cpp"

using namespace std;

class PilhaPonteiro {
private:
    struct Node{
        int value;
        Node *ant;
    };
    Node *topo;
    
public:    
    int size;
    void iniciaPilha() {
        this->topo = nullptr;
    }

   PilhaPonteiro() {
        iniciaPilha();
        this->size = 0;
    }

    bool pilhaVazia() {
        if (this->topo == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void empilha(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->ant = this->topo; 
        this->topo = newNode; 
        this->size = this->size + 1;
    }

    int desempilha() {
        if (pilhaVazia()) {
            throw EPilhaVazia("A Pilha está vazia!");
        }
        Node* removeNode = this->topo;
        int removeNodeValue = this->topo->value;
        this->topo = this->topo->ant; 
        delete removeNode;
        this->size = this->size - 1;
        if (size == 0) {
            this->topo = nullptr;
        }
        return removeNodeValue;
    }
};

#endif