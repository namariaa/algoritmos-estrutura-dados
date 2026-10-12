#include <iostream>
#include <vector>
#include "../arvores/heap/heap.cpp"

using namespace std;

void troca(vector<int> &list, int pos1, int pos2) {
    int value = list[pos1];
    list[pos1] = list[pos2];
    list[pos2] = value;
}

void descer(vector<int> &list, int root, int treeSize) {
    int esqRoot = root * 2 + 1;
    if (esqRoot <= treeSize) {
        if (esqRoot + 1 <= treeSize) {
            if (list[esqRoot + 1] > list[esqRoot]) esqRoot+=1;
        }

        if (list[root] < list[esqRoot]) {
            troca(list, root,esqRoot);
            descer(list, esqRoot, treeSize);
        }
    }
}

void arranjar(vector<int> &list, int listSize) {
    for (int i = listSize / 2; i >= 0; i--) {
        descer(list, i, listSize);
    }
}

void heapSort(vector<int> &list) {
    int n = list.size();
    arranjar(list,n);
    int listSize = n - 1;
    for (int i = 0; i < n - 1; i++) {
        troca(list, 0, listSize);
        listSize--;
        descer(list, 0, listSize);
    }
}

int main () {
    vector<int> numberlist;
    int v;
    for(int i = 0; i < 10; i++) {
        cin >> v;
        numberlist.push_back(v);
    }
    heapSort(numberlist);
    
    for (int i = 0; i < numberlist.size(); i++) {
        cout << numberlist[i] << endl;
    }
    return 0;
}