#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long pw(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long q = pw(x, n / 2);
    if (n % 2 == 0) {
        return q * q % MOD;
    }
    else {
        return q * q % MOD * x % MOD;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long x;
    long long n;
    cin >> x >> n;

    cout << pw(x, n);
    return 0;
}

