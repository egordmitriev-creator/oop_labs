#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Matrix {
private:
    int **data;
    int rows;
    int cols;
    int sum;

public:
    Matrix() : data(nullptr), rows(0), cols(0), sum(0) {}

    Matrix(int n) : rows(n), cols(n), sum(0) {
        data = new int*[n];
        for (int i = 0; i < n; i++) {
            data[i] = new int[n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = (i == j) ? 1 : 0;
            }
        }
    }

    Matrix(int rows, int cols) : rows(rows), cols(cols), sum(0) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void inputMatrix() {
        cout << "Введите элементы матрицы " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void fillRandom() {
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }

    void displayMatrix() const {
        cout << "Матрица " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void calculateSum() {
        sum = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum += data[i][j];
            }
        }
        cout << "Сумма элементов матрицы: " << sum << '\n';
    }

    int getRows() const { 
        return rows; 
    } 
 
    int getCols() const { 
        return cols; 
    } 
 
    void setElement(int row, int col, int value) { 
        data[row][col] = value; 
    }
};

int main() {
    Matrix M1;
    Matrix M2(3);
    Matrix M3(3, 4);
    Matrix M4(2, 3);

    M2.displayMatrix();
    M3.displayMatrix();
    M4.displayMatrix();

    for (int i = 0; i < M2.getRows(); ++i) { 
        for (int j = 0; j < M2.getCols(); ++j) { 
            M2.setElement(i, j, i * j); 
        } 
    } 
    M2.displayMatrix();

    M3.fillRandom();
    M3.displayMatrix();
    M3.calculateSum();

    M4.inputMatrix();
    M4.displayMatrix();

    return 0;
}