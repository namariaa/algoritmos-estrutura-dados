#ifndef Heap
#include <iostream>
#include <vector>
#include "EHeapError.cpp"

using namespace std;

class Heap {
    private:
        vector<int> priorityList;
        int size;

        
    public:
        Heap() {
            this->size = 0;
        }

        int heapSize() {
            return this->size;
        }

        int heapVazia() {
            return this->size == 0;
        }

        int getElement(int index) {
            return this->priorityList[index];
        }

        void troca(int pos1, int pos2) {
            int value = this->priorityList[pos1];
            this->priorityList[pos1] = this->priorityList[pos2];
            this->priorityList[pos2] = value;
        }

        void descer(int root, int treeSize) {
            int esqRoot = root * 2 + 1;
            if (esqRoot <= treeSize) {
                if (esqRoot + 1 <= treeSize) {
                    if (this->priorityList[esqRoot + 1] > this->priorityList[esqRoot]) esqRoot+=1;
                }

                if (this->priorityList[root] < this->priorityList[esqRoot]) {
                    troca(root,esqRoot);
                    descer(esqRoot, treeSize);
                }
            }
        }

        void remover() {
            if (heapVazia()) {
                throw EHeapError("A heap está vazia. Não foi possível remover o elemento.");
            } else {
                this->priorityList[0] = this->priorityList[this->size - 1];
                this->priorityList.pop_back();
                this->size--; 
                descer(0,this->size - 1);
            }
        }

        void subir(int newElement) {
            int fatherN = (newElement - 1) / 2;
            if (fatherN >= 0) {
                if (this->priorityList[newElement] > this->priorityList[fatherN]) {
                    troca(newElement,fatherN);
                    subir(fatherN);
                }
            }
        }

        void inserir(int value) {
            this->priorityList.push_back(value);
            subir(size);
            this->size++;
        }
};


#endif