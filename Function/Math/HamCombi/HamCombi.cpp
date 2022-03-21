#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int a[100005];
long long fact[100005];
long long inv[100005];

long long pw(long long x, long long n) {
    if (n == 0) return 1;
    long long m = pw(x, n / 2) % MOD;
    if (n % 2 == 0) return m * m % MOD;
    return m * m % MOD * x % MOD;
}

long long combi(int n, int k) {
    if (n >= k) {
        return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
    }
    return 0;
}

int main() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2);
    }

    // faster
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv[100000] = pw(fact[100000], MOD - 2, MOD);
    for (int i = 99999; i; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    int n, k;
    cin >> n >> k;

    cout << combi(n, k);
    return 0;
}
