#include <iostream>
#include <ctime>

using namespace std;

int* genRandArray(int size, int maxValue){
    int s = size + 1;
    int *arr = new int[s];
    arr[0] = size;
    for (int i = 1; i < s; i++){
        arr[i] = rand() % maxValue;
    }
    return arr;
}

void print(int* arr){
    int s = arr[0] + 1;
    cout << arr[0] << ": ";
    for (int i = 1; i < s; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand (time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    print(arr);
    delete[] arr;
    return 0;
}