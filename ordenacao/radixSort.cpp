#include <iostream>
#include <vector>

using namespace std;

vector<int> countSortDigit(vector<int> numberList, int exp) {
    int size = numberList.size();
    vector<int> countList(10);
    vector<int> numberListSort(size);
    for (int i = 0; i < size; i++) countList[(numberList[i] / exp) % 10] += 1;
    for (int i = 1; i < 10; i++) countList[i] += countList[i - 1];
    for (int i = 0; i < numberList.size(); i++) {
        int number = numberList[numberList.size() - i - 1];
        int pos = countList[(number / exp) % 10] - 1;
        numberListSort[pos] = number;
        countList[(number / exp) % 10] -= 1;
    } 
    return numberListSort;
}

void radixSort(vector<int> &numberList) {
    int size = numberList.size();

    int biggerValue = 0;
    for (int i = 0; i < size; i++) {
        if (numberList[i] > biggerValue) biggerValue = numberList[i];
    }

    int exp = 1;
    while (biggerValue / exp > 0) {
        numberList = countSortDigit(numberList, exp);
        exp*=10;
    }
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
    radixSort(numberlist);
    
    for (int i = 0; i < size; i++) {
        cout << numberlist[i] << endl;
    }
    return 0;
}