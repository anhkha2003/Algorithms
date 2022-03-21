#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
map<long long, long long> f;

long long a[200005];

long long fibo(long long n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
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

long long gcd(long long a, long long b) {
    while (b > 0) {
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int n;
    cin >> n;
    long long g = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }

    cout << fibo(g - 1);
    return 0;
}

// GCD(F[a], F[b]) = F[GCD(a, b)]
