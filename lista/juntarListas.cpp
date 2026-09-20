#include <iostream>
#include <vector> 
#include "../ordenacao/mergeSort.cpp"

using namespace std;

int main () {
    vector<int> numberlist;
    int v, n, m;
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++) {
        cout << "Insira os valores da lista " << i + 1 << endl; 
        for(int j = 0; j < m; j++) { 
            cin >> v;
            numberlist.push_back(v);
        }
    }
    mergeSort(numberlist, 0, n * m - 1);
    
    for (int i = 0; i < numberlist.size(); i++) {
        cout << numberlist[i] << endl;
    }
    return 0;
}