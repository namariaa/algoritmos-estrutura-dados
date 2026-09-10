#include <iostream>
#include "vetor.hpp"
// #include "listaLigada.hpp"

using namespace std;

int main () {
    int v, capacidade;
    cout << "Informe a capacidade da fila: ";
    cin  >> capacidade;
    Fila query(capacidade);
    // FilaPonteiro query;
    for(int i = 0; i < capacidade; i++) {
        cin >> v;
        query.insere(v);
    }

    int size = query.size;
    for (int i = 0; i < size; i++) {
        cout << query.remove() << endl;
    }
    query.insere(7);
    query.insere(8);
    query.insere(9);
    cout << query.remove() << endl;
    query.insere(10);
    return 0;
}