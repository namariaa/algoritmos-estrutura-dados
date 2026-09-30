#include <iostream>
#include <vector>
#include <random>

using namespace std;

void troca(vector<int> &list, int pos1, int pos2) {
    int value = list[pos1];
    list[pos1] = list[pos2];
    list[pos2] = value;
}

int randomPivo(vector<int>&list, int begin, int end) {
    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<int> distrib(begin, end);
    return distrib(gen);
}

int particiona(vector<int> &list, int begin, int end) {
    int pivo = randomPivo(list, begin, end);
    cout << "PIVO " << pivo << endl;
    troca(list, begin, pivo);
    pivo = list[begin];
    int i = begin + 1;
    int j = end;

    while (i <= j) {
        while (list[i] < pivo) i+=1;
        while (list[j] >= pivo) j-=1;
        if (i < j) troca(list,i, j); 
    }
    list[begin] = list[j];
    list[j] = pivo;
    return j;
}

int quickSelect(vector<int> &list, int begin, int end, int element) {
    if (begin == end) return list[begin];

    int posPivo = particiona(list, begin, end);
    cout << "SAIU PARTICIONA " << posPivo << endl;
    // posição do pivô dentro da sublista
    int middle = posPivo - begin + 1;

    if (element == middle)
        return list[posPivo];

    if (element < middle) return quickSelect(list,begin,posPivo - 1, element);
    return quickSelect(list,posPivo + 1, end, element - middle);
}

int main () {
    vector<int> numberlist;
    int v;
    for(int i = 0; i < 11; i++) {
        cin >> v;
        numberlist.push_back(v);
    }

    cout << quickSelect(numberlist, 0, numberlist.size() - 1, 3) << endl;
    
    return 0;
}