#include <iostream>
#include <vector> 

using namespace std;

void merge(vector<int> &list, int begin, int middle, int end) {
    int a = middle - begin + 1;
    int b = end - middle; 

    vector<int> firstList(a);
    vector<int> secondList(b);

    for (int i = 0; i < a; i++) {
        firstList[i] = list[begin + i];
    }
    
    for (int i = 0; i < b; i++) {
        secondList[i] = list[middle + i + 1];
    }
    
    int count1 = 0;
    int count2 = 0;
    for (int i = begin; i < end + 1; i++) {
         if (count1 < a && (count2 >= b || firstList[count1] <= secondList[count2])) {
            list[i] = firstList[count1];
            count1++;
        } else {
            list[i] = secondList[count2];
            count2++;
        }
    }
}

void mergeSort(vector<int> &list, int begin, int end) {
    if (begin < end) {   
        int pos = (begin + end) / 2;
        mergeSort(list, begin, pos);
        mergeSort(list, pos + 1, end);
        merge(list, begin, pos, end);
    }
}

int main () {
    vector<int> numberlist;
    int v;
    for(int i = 0; i < 5; i++) {
        cin >> v;
        numberlist.push_back(v);
    }
    mergeSort(numberlist, 0, numberlist.size() - 1);
    
    for (int i = 0; i < numberlist.size(); i++) {
        cout << numberlist[i] << endl;
    }
    return 0;
}