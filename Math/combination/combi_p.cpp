#include <bits/stdc++.h>
using namespace std;

long long fact[100005];
long long inv[100005];
long long vp[100005];

// tính combi(n, k) với mọi p là snt
long long pw(long long a, long long n, long long m) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2, m);
    if (n % 2 == 0) return q * q % m;
    else return q * q % m * a % m;
}

long long combi(long long n, long long k, long long m) {
    if (n < k) return 0;
    if (vp[n] > vp[n - k] + vp[k]) return 0;
    return fact[n] * inv[k] % m * inv[n - k] % m;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t, p;
    cin >> t >> p;

    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        int val = i; vp[i] = vp[i - 1];
        while (val % p == 0) {
            vp[i]++;
            val /= p;
        }

        fact[i] = fact[i - 1] * val % p;
        inv[i] = pw(fact[i], p - 2, p);
    }

    for (int z = 1; z <= t; z++) {
        long long n, k;
        cin >> n >> k;
        cout << combi(n, k, p) << "\n";
    }

    return 0;
}