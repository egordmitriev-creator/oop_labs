#include <iostream>
#include <ctime>
using namespace std;

int** genRandMatrix(int size, int maxValue){
    int s = size + 2;
    int **matrix = new int*[s];
    matrix[0] = new int[1];
    matrix[0][0] = size; 
    for(int i = 1; i < s; i++){
        int x = rand()%10 + 1; // x - кол-во строк
        matrix[i] = new int[x];
        matrix[i][0] = x;
        int s2 = x + 1; // s2 - длинна строки
        for(int j = 1; j < s2; j++){
            matrix[i][j] = rand()%maxValue;
        }
    }
    return matrix;
}

void printMatrix(int** matrix){
    int s = matrix[0][0] + 1;
    cout << matrix[0][0] << endl;
    for(int i = 1; i < s; i++){
        int x = matrix[i][0] + 1;
        cout << matrix[i][0] << ": ";
        for(int j = 1; j < x; j++){ //x - кол-во строк
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    srand(time(NULL));
    int size = rand()%10 + 1;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix);
    for(int i = 0; i < size + 1; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}