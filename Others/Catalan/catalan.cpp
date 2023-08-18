#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 1329;

long long fact[100005];
long long inv[100005];

long long pw(long long n, long long x) {
    if (x == 0) return 1;
    long long q = pw(n, x / 2);
    if (x % 2 == 0) {
        return q * q % MOD;
    }
    else {
        return q * q % MOD * n % MOD;
    }
}

long long catalan(long long n) {
    return fact[2 * n] * inv[n] % MOD * inv[n + 1] % MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    fact[0] = inv[0] = 1;
    for (long long i = 1; i <= 100000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2)
    }

    return 0;
}