#include <iostream>
#include <vector>
// #include "vetor.hpp"
// #include "vetorDinamico.hpp"
#include "listaLigada.hpp"

using namespace std;

int main () {
    int v, capacidade;
    cout << "Informe a capacidade da pilha: ";
    cin  >> capacidade;
    // Pilha stack(capacidade);
    PilhaPonteiro stackPonteiro;
    // PilhaDinamica stackDinamico(capacidade);
    for(int i = 0; i < capacidade; i++) {
        cin >> v;
        // stack.empilha(v);
        stackPonteiro.empilha(v);
        // stackDinamico.empilha(v);
    }

    // stackDinamico.empilha(5);
    // stackDinamico.empilha(8);
    
    int size = stackPonteiro.size;
    for (int i = 0; i < size; i++) {
        // cout << stack.desempilha() << endl;
        cout << stackPonteiro.desempilha() << endl;
        // cout << stackDinamico.desempilha() << endl;
    }
    stackPonteiro.empilha(9);
    stackPonteiro.empilha(10);
    cout << stackPonteiro.desempilha() << endl;

    return 0;
}