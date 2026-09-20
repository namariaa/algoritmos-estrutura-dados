#include <iostream>
#include "EDequeError.cpp"

using namespace std;

#ifndef dequePonteiro
#define dequePonteiro

class DequePonteiro
{
private:
    struct Node {
        int value;
        Node *next;
        Node *ant;
    };
    Node *begin;
    Node *end;
    
public:
    int size;
    DequePonteiro() {
        this->size = 0;
        this->begin = nullptr;
        this->end = nullptr;
    }

    bool dequeVazio() {
        if (this->size == 0) return true;
        return false;
    }

    void inserirIncio(int value) {
        this->size = this->size + 1;
        Node *newNode = new Node;
        newNode->value = value;
        if (size >= 2) {
            newNode->next = this->begin;
            this->begin->ant = newNode;
        } else {
            newNode->next = nullptr;
        }
        newNode->ant = nullptr;
        this->begin = newNode;
        if (this->end == nullptr) {
            this->end = newNode;
        }
    }

    void inserirFim(int value) {
        this->size = this->size + 1;
        Node *newNode = new Node;
        newNode->value = value;
        if (size >= 2) {
            newNode->ant = this->end; 
            this->end->next = newNode;
        } else {
            newNode->ant = nullptr;
        }
        newNode->next = nullptr;
        this->end = newNode;
        if (this->begin == nullptr) {
            this->begin = newNode;
        }
    }

    int removerInicio() {
        if (dequeVazio()) {
            throw EDequeError("O deque está vazio.");
        }
        this->size = this->size - 1;
        int oldElement = this->begin->value;
        Node *removeNode = this->begin;
        if (size > 0) {
            this->begin = this->begin->next;
        } else {
            this->begin = nullptr;
            this->end = nullptr;
        }
        delete removeNode;
        return oldElement;
    }

    int removerFim() {
        if (dequeVazio()) {
            throw EDequeError("O deque eestá vazio.");
        }
        this->size = this->size - 1;
        int oldElement = this->end->value;
        Node *removeNode = this->end;
        if (size > 0) {
            this->end = this->end->ant;
        } else {
            this->begin = nullptr;
            this->end = nullptr;
        }
        delete removeNode;
        return oldElement;
    }
};

#endif