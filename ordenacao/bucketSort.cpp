#include <iostream>
#include <vector>
#include "insertionSort.cpp"

using namespace std;

vector<int> bucketSort(vector<int> numberList) {
    int sizeNumberList = numberList.size();
    int biggerValue = 0;
    vector<vector<int>> numberlistMatrix(sizeNumberList);
    vector<int> numberlistSorted;

    for (int i = 0; i < sizeNumberList; i++) {
        if (numberList[i] > biggerValue) biggerValue = numberList[i];
    }
    for (int i = 0; i < sizeNumberList; i++) {
        int bucketNumberIndex = sizeNumberList * (numberList[i] / (biggerValue + 1));
        numberlistMatrix[bucketNumberIndex].push_back(numberList[i]);
    }
    for (int i = 0; i < sizeNumberList; i++) {
        numberlistMatrix[i] = insertionSort(numberlistMatrix[i]);
        if (numberlistMatrix[i].size() > 0) {
            numberlistSorted.insert(numberlistSorted.end(), numberlistMatrix[i].begin(), numberlistMatrix[i].end());
        }
    }
    return numberlistSorted;
}

int main() {
    vector<int> numberlist;
    cout << "Insira o tamanho da sua lista: " <<endl;
    int size;
    cin >> size;
    int v;
    for(int i = 0; i < size; i++) {
        cin >> v;
        numberlist.push_back(v);
    }
    vector<int> numberlistSorted = bucketSort(numberlist);
    
    for (int i = 0; i < size; i++) {
        cout << numberlistSorted[i] << endl;
    }
    return 0;
}