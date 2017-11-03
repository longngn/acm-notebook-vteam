#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1e9+7;

// NOTE: Matrix is 1-indexed
typedef long long MT;
struct Matrix {
    int h = 0, w = 0;
    vector<vector<MT> > val;
    friend Matrix operator*(Matrix& A, Matrix& B) {
        if (A.w != B.h) { cout << "Matrix multiplication fails!"; exit(0); }
        Matrix C(A.h, B.w);
        for(int i = 1; i <= C.h; i++) for(int j = 1; j <= C.w; j++)
            for(int k = 1; k <= A.w; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }
    vector<MT>& operator[](const int& idx) { return val[idx]; }
    friend ostream& operator<<(ostream& os, Matrix& a) { 
        for(int i = 1; i <= a.h; i++) {
            for(int j = 1; j <= a.w; j++) os << a[i][j] << ' ';
            os << '\n';
        }
        return os;
    }
    Matrix(int h = 0, int w = 0): h(h), w(w) { 
        val.resize(h+1, vector<MT>(w+1, 0)); 
    }
};

int main() {
    Matrix a(2, 2);
    a[1][1] = 1, a[1][2] = 2, a[2][1] = 3, a[2][2] = 4;
    Matrix b = a, c = b*a;
    cout << c;
}