#include <iostream>
using namespace std;

template <typename T>
class MATRIX{
    private:
        T** M;
        int  m;
        int n;
    public:
        MATRIX(){
            n = m = 0;
            M = nullptr;
        }

        MATRIX(int _m, int _n){
            m = _m;
            n = _n;
            M = (T**) new T*[m];
            for (int i = 0; i < m; i++)
                M[i] = (T*)new T[n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    M[i][j] = 0;
        }

        MATRIX(const MATRIX &_M){
            m = _M.m;
            n = _M.n;
            M = (T**) new T*[m];
            for (int i = 0; i < m; i++)
                M[i] = (T*) new T[n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    M[i][j] = _M.M[i][j];
        }

        T GetMij(int i, int j){
            if ((m > 0) && (n > 0))
                return M[i][j];
            else
                return 0;
        }

        void SetMij(int i, int j, T value){
            if ((i < 0) || (i >= m))
                return;
            if ((j < 0) || (j >= n))
                return;
            M[i][j] = value;
        }

        void Print(const char* ObjName){
            cout << "Object: " << ObjName << endl;
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++)
                    cout << M[i][j] << "\t";
                cout << endl;
            }
            cout << "---------------------" << endl << endl;
        }

        MATRIX operator = (const MATRIX &_M){
            if(n > 0){
                for(int i = 0; i < m; i++){
                    delete[] M[i];
                }
            }

            if(m > 0){
                delete[] M;
            }

            m = _M.m;
            n = _M.n;
            M = (T**) new T*[m];
            for (int i = 0; i < m; i++)
                M[i] = (T*) new T[n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    M[i][j] = _M.M[i][j];
            return *this;
        }

        ~MATRIX(){
            if(n > 0){
                for(int i = 0; i < m; i++)
                    delete[] M[i];
            }

            if(m > 0)
                delete[] M;
        }
};

// int main(){
//     MATRIX<int> M(3, 4);
//     M.Print("M");
//     int i, j;
//     for (i = 0; i < 2; i++)
//         for (j = 0; j < 3; j++)
//             M.SetMij(i, j, i + j);
//     M.Print("M");
//     MATRIX<int> M2 = M;
//     M2.Print("M2");
//     MATRIX<int> M3;
//     M3 = M;
//     M3.Print("M3");
//     MATRIX<int> M4;
//     M4 = M3 = M2 = M;
//     M4.Print("M4");
// }

int main(){
    MATRIX<double> M(3, 4);
    M.Print("M");
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            M.SetMij(i, j, (i + j)*0.5);
    M.Print("M");
    MATRIX<double> M2 = M;
    M2.Print("M2");
    MATRIX<double> M3;
    M3 = M;
    M3.Print("M3");
    MATRIX<double> M4;
    M4 = M3 = M2 = M;
    M4.Print("M4");
}