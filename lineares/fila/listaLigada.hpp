#ifndef filaPonteiro
#define filaPonteiro
#include <iostream>
#include "EFilaError.cpp"

using namespace std;

class FilaPonteiro {
private:
    struct Node {
        int value;
        Node* next;
    };
    
    Node *begin;
    Node *end;
   
    
public:    
    int size;
    void inciaFila() {
        this->begin = nullptr;
        this->end = nullptr;
    }

    FilaPonteiro() {
        inciaFila();
        this->size = 0;
    }

    bool filaVazia() {
        if (this->size == 0) return true;
        return false;
    }

    void insere(int value) {
        this->size = this->size + 1;
        Node *newNode = new Node;
        newNode->next = nullptr;
        newNode->value = value;
        if (this->end != nullptr) {
            this->end->next = newNode;
        } else {
            this->begin = newNode;
        }
        if (this->size == 2) {
            this->begin->next = newNode;
        }
        this->end = newNode;
    }
    
    int remove() {
        if (filaVazia()) {
            throw EFilaError("A fila está vazia!");
        }
        int oldElement = this->begin->value;
        if (this->begin->next != nullptr) {
            Node *newBegin = this->begin->next;
            delete this->begin;
            this->begin = newBegin;
        } else {
            this->begin = nullptr;
            this->end = nullptr;        
        }
        this->size = this->size - 1;
        return oldElement;
    }
};

#endif