#include <iostream>
#include <vector>

using namespace std;

void countSort(vector<int> &numberList, vector<int> &numberListSort, int sizeCount) {
    sizeCount += 1;
    vector<int> countList(sizeCount);
    for (int i = 0; i < sizeCount; i++) countList[i] = 0;
    for (int i = 0; i < numberList.size(); i++) countList[numberList[i]] += 1;
    for (int i = 1; i < sizeCount; i++) countList[i] += countList[i - 1];
    for (int i = 0; i < numberList.size(); i++) {
        int number = numberList[numberList.size() - i - 1];
        int pos = countList[number] - 1;
        numberListSort[pos] = number;
        countList[number] -= 1;
    } 
}

// int main() {
//     vector<int> numberlist;
//     cout << "Insira o maior valor da sua lista: " <<endl;
//     int sizeCount;
//     cin >> sizeCount;
//     int v;
//     for(int i = 0; i < 5; i++) {
//         cin >> v;
//         numberlist.push_back(v);
//     }
//     vector<int> numberlistSort(numberlist.size());
//     countSort(numberlist, numberlistSort, sizeCount);
    
//     for (int i = 0; i < numberlistSort.size(); i++) {
//         cout << numberlistSort[i] << endl;
//     }
//     return 0;
// }