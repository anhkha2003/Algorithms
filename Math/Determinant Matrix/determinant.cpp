#include<bits/stdc++.h>
using namespace std;

// Calculate determinant of a matrix. Destroys the matrix.
// O(n^3)

const long long MOD = 998244353;

long long pw(long long a, long long n) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

long long det(vector<vector<long long>>& a) {
    int n = a.size(); long long res = 1;
    bool isNeg = 0;
    for (int i = 0; i < n; i++) {
        int b = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(a[j][i]) > abs(a[b][i])) b = j;
        }

        if (i != b) {
            swap(a[i], a[b]);
            isNeg ^= 1;
        }

        res = res * a[i][i] % MOD;
        if (res == 0) return 0;
        long long denom = pw(a[i][i], MOD - 2);
        for (int j = i + 1; j < n; j++) {
            long long v = a[j][i] * denom % MOD;
            if (v != 0) {
                for (int k = i + 1; k < n; k++) {
                    a[j][k] -= v * a[i][k] % MOD;
                    a[j][k] = (a[j][k] % MOD + MOD) % MOD;
                }
            }
        }
    }
    if (isNeg) res = (-res % MOD + MOD) % MOD;
    return res;
}

double det(vector<vector<double>>& a) {
    int n = a.size(); double res = 1;
    int m = a[0].size();
    for (int i = 0; i < n; i++) {
        int b = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[j][i]) > fabs(a[b][i])) b = j;
        }

        if (i != b) {
            swap(a[i], a[b]);
            res *= -1;
        }

        res *= a[i][i];
        if (res == 0) return 0;
        for (int j = i + 1; j < n; j++) {
            double v = a[j][i] / a[i][i];
            if (v != 0) {
                for (int k = i + 1; k < n; k++) {
                    a[j][k] -= v * a[i][k];
                }
            }
        }
    }
    return res;
}