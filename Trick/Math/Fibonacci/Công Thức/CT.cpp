#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
map<long long, long long> f;

long long fibo(long long n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (f.count(n) > 0) {
        return f[n];
    }
    if (n % 2 == 0) {
        long long a = fibo(n / 2 - 1);
        long long b = fibo(n / 2);
        return f[n] = (a * a % MOD + b * b % MOD) % MOD;
    }
    return f[n] = (fibo(n + 1) - fibo(n - 1) + MOD) % MOD;
}

// f[2 * n] = f[n - 1] * f[n - 1] + f[n] * f[n]
// chỉ đúng với f[0] = f[1] = 1;
// sử dụng map để lưu số fibonacci
