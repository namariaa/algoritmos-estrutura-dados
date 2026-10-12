#include <iostream>
#include "heap.cpp"

using namespace std;

int main () {
    int v, capacidade;
    cout << "Informe a capacidade da heap: ";
    cin  >> capacidade;
    Heap priorityList;
    for(int i = 0; i < capacidade; i++) {
        cin >> v;
        priorityList.inserir(v);
    }

    for (int i = 0; i < priorityList.heapSize(); i++) {
        cout << priorityList.getElement(i) << endl;
    }

    priorityList.remover();
    priorityList.remover();

    for (int i = 0; i < priorityList.heapSize(); i++) {
        cout << priorityList.getElement(i) << endl;
    }
    return 0;
}