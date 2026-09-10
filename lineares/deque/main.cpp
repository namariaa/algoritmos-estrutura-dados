#include <iostream>
// #include "vetor.hpp"
#include "listaLigada.hpp"

using namespace std;

int main () {
    int v, capacidade;
    cout << "Informe a capacidade do deque: ";
    cin  >> capacidade;
    // Deque dequeList(capacidade);
    DequePonteiro dequeList;
    for(int i = 0; i < capacidade; i++) {
        cin >> v;
        dequeList.inserirIncio(v);
    }

    int size = dequeList.size;
    for (int i = 0; i < size; i++) {
        cout << dequeList.removerFim() << endl;
    }
    dequeList.inserirFim(7);
    dequeList.inserirIncio(8);
    dequeList.inserirFim(9);
    cout << dequeList.removerInicio() << endl;
    dequeList.inserirFim(10);
    cout << dequeList.removerInicio() << endl;
    cout << dequeList.removerInicio() << endl;
    cout << dequeList.removerInicio() << endl;
    return 0;
}