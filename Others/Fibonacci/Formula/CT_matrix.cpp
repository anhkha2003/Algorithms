#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

struct Matrix {
    long long coef[5][5]; // độ dài của dãy dp
    int n;

    Matrix(int n): n(n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                coef[i][j] = 0;
            }
        }
    }

    // a[i][j] += b[i][k] * c[k][j]
    Matrix operator * (Matrix& a) {
        Matrix res(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    res.coef[i][j] += coef[i][k] * a.coef[k][j] % MOD;
                    res.coef[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

Matrix pw(Matrix &A, long long n) {
    if (n == 1) return A;
    Matrix Q = pw(A, n / 2);
    if (n % 2 == 0) return Q * Q;
    return Q * Q * A;
}

// F(n) = F(n - 1) + F(n - 2)
// F(n)         =   1 1   *   F(n - 1) 
// F(n - 1)         1 0       F(n - 2)
long long fibo(long long n) {
    Matrix A(2);
    A.coef[1][1] = 1;
    A.coef[1][2] = 1;
    A.coef[2][1] = 1;
    A.coef[2][2] = 0;

    Matrix d(2); 
    d.coef[1][1] = 1; 
    d.coef[1][2] = 0;

    Matrix res(2);
    if (n > 1) {
        res = pw(A, n - 1);
        res = d * res;
    }
    else res = d;
    
    return res.coef[1][1];
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long n;
    cin >> n;

    cout << fibo(5);

    return 0;
}