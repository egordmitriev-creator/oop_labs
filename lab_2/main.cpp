#include <iostream>
#include <ctime>
using namespace std;

int** genRandMatrix(int size, int maxValue){
    int **matrix = new int*[size]; 
    for(int i = 0; i < size; i++){
        matrix[i] = new int[size];
        for(int j = 0; j < size; j++){
            matrix[i][j] = rand()%maxValue;
        }
    }
    return matrix;
}

void printMatrix(int size, int** matrix){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    srand(time(NULL));
    int maxValue = 100;
    int size = 1;
    cout << "Enter size:" << endl;
    cin >> size;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(size, matrix);
    for(int i = 0; i < size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}