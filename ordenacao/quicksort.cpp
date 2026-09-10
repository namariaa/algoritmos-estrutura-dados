#include <iostream>
#include <vector>

using namespace std;

void troca(vector<int> &list, int pos1, int pos2) {
    int value = list[pos1];
    list[pos1] = list[pos2];
    list[pos2] = value;
}

int particiona(vector<int> &list, int begin, int end) {
    int v = list[begin];
    int i = begin + 1;
    int j = end;

    while (i < j) {
        while (i <= end && list[i] < v) i++;
        while (j > begin && list[j] >= v) j--;
        if (i < j) troca(list, i, j);
    }
    list[begin] = list[j];
    list[j] = v;
    return j;
}

int pivo(vector<int>& list, int begin) {
    if (list[begin] < list[begin + 1])
        return begin + 1;

    if (list[begin] > list[begin + 1])
        return begin;

    return -1;
}

void quickSort(vector<int> &list, int begin, int end) {
    if (begin  >= end) return;
    int pivoList = pivo(list, begin);
    if (pivoList != -1) {
        troca(list, begin, pivoList);
        int j = particiona(list, begin, end);
        quickSort(list, begin, j - 1);
        quickSort(list, j + 1, end);
    }
}

int main () {
    vector<int> numberlist;
    int v;
    for(int i = 0; i < 5; i++) {
        cin >> v;
        numberlist.push_back(v);
    }
    quickSort(numberlist, 0, numberlist.size() - 1);
    
    for (int i = 0; i < numberlist.size(); i++) {
        cout << numberlist[i] << endl;
    }
    return 0;
}