#include <iostream>
#include "EDequeError.cpp"

using namespace std;

#ifndef deque
#define deque

class Deque
{
private:
    int *dequeList;
    int begin;
    int end;
    int capacidade;
    
public:
    int size;
    Deque(int capacidade) {
        this->capacidade = capacidade;
        this->size = 0;
        this->dequeList = new int[capacidade];
        this->begin = -1;
        this->end = -1;
    }

    bool dequeVazio() {
        if (this->size == 0) return true;
        return false;
    }

    void inserirIncio(int value) {
        if (this->size == this->capacidade) {
            throw EDequeError("O deque excedeu sua capacidade.");
        }
        this->size = this->size + 1;
        if (this->begin == 0) this->begin = this->capacidade - 1;
        else if (this->begin == -1) this->begin = 0;
        else this->begin = this->begin - 1;
        if (this->size == 1) this->end = 0;
        this->dequeList[begin] = value;
    }

    void inserirFim(int value) {
        if (this->size == this->capacidade) {
            throw EDequeError("O deque excedeu sua capacidade.");
        }
        this->size = this->size + 1;
        if (this->capacidade == this->end + 1) this->end = 0;
        else this->end = this->end + 1;
        if (this->size == 1) this->begin = 0;
        this->dequeList[end] = value;
    }

    int removerInicio() {
        if (dequeVazio()) {
            throw EDequeError("O deque eestá vazio.");
        }
        this->size = this->size - 1;
        int oldElement = this->dequeList[this->begin];
        if (this->begin == this->capacidade - 1) this->begin = 0;
        else this->begin = this->begin + 1;
        if (size == 0) {
            this->begin = -1;
            this->end = -1;
        }
        return oldElement;
    }

    int removerFim() {
        if (dequeVazio()) {
            throw EDequeError("O deque eestá vazio.");
        }
        this->size = this->size - 1;
        int oldElement = this->dequeList[this->end];
        if (this->end == 0) this->end = this->capacidade - 1;
        else this->end = this->end -1;
        if (size == 0) {
            this->begin = -1;
            this->end = -1;
        }
        return oldElement;
    }
};

#endif