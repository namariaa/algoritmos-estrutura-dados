#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> numberlist) {
    for (int i = 1; i < numberlist.size(); i++) {
        int index = i;
        int moveNumber = numberlist[index]; 
        while (moveNumber < numberlist[index - 1]) {
            numberlist[index] = numberlist[index - 1];
            index--;
        }
        numberlist[index] = moveNumber;
    }
    return numberlist;
}

vector<int> insertionSortDecrescente(vector<int> numberlist) {
    for (int i = 1; i < numberlist.size(); i++) {
        int index = i;
        int moveNumber = numberlist[index]; 
        while (index - 1 >= 0 && moveNumber > numberlist[index - 1]) {
            numberlist[index] = numberlist[index - 1];
            index--;
        }
        numberlist[index] = moveNumber;
    }
    return numberlist;
}

int main() {
    vector<int> numberlist;
    int v;
    for(int i = 0; i < 5; i++) {
        cin >> v;
        numberlist.push_back(v);
    }
    vector<int> sortList = insertionSort(numberlist);
    
    for (int i = 0; i < sortList.size(); i++) {
        cout << sortList[i] << endl;
    }

    return 0;
}