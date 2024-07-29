#include <iostream>
#include <ctime>
using namespace std;

int** genRandMatrix(int size, int maxValue){
    int **matrix = new int*[size]; 
    for(int i = 0; i < size; i++){
        int r = rand() % 10 + 1;
        matrix[i] = new int[r];
        for(int j = 0; j < r; j++){
            matrix[i][j] = rand()%maxValue;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}

int main(){
    srand(time(NULL));
    int maxValue = 100;
    int size = 1;
    cout << "Enter size:";
    cin >> size;
    int** matrix = genRandMatrix(size, maxValue);
    for(int i = 0; i < size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}