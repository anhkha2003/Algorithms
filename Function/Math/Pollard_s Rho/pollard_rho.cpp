#include <bits/stdc++.h>
using namespace std;

/* POLLARD RHO algorithm */
// prime factorization algorithm for n = 1e18

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r){
    uniform_int_distribution<long long> rnd(l,r);
    return rnd(gen);
}

long long mul(long long a, long long b, long long m){
    // return a * b % m if m <= 1e9
    // return (__int128) a * b % m if can use __int128

    long long c = (long double)a * b / m;
    long long ans = (long long)(a * b - c * m) % m;
    if (ans < 0) {
        ans += m;
    }   
    return ans;
}

long long pw(long long a, long long n, long long m){
    if (n == 0) return 1 % m;
    long long q = pw(a, n / 2, m);
    if (n % 2 == 0) return mul(q, q, m);
    return mul(mul(q, q, m), a, m);
}

// Milner-Rabin algorithm
bool checkprime(long long n){
    if (n == 2) return 1;
    if (n % 2 == 0 || n == 1) return 0;
    long long m = n - 1;
    long long s = 0;
    while (m % 2 == 0){
        m /= 2; s++;
    }
    long long dem = 0, q = 0, a, b;
    while (dem <= 3){
        dem++;

        a = Rand(2, n - 2);
        b = pw(a, m, n);

        if ((b + 1) % n == 0 || (b - 1) % n == 0) {q++;continue;}
        for (int i = 1; i <= s; i++) {
            b = mul(b, b, n);
            if ((b + 1) % n == 0) {q++; break;}
        }
    }
    if (q == 4) return 1;
    return 0;
}

map<long long, long long> alpha;

void brute(int n){
    if (n == 1) return;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) {
           while (n % i == 0) {alpha[i]++; n /= i;}
        }
    }
    if (n > 1){
        alpha[n]++;
    }
}

long long f(long long x, long long m){
    return (mul(x, x, m) + 1) % m;
}

long long findFactor(long long n){
    long long x = Rand(2, n - 1);
    long long y = x;
    long long p = 1;
    while (p == 1){
        x = f(x, n);
        y = f(f(y, n), n);
        p = __gcd(abs(x - y), n);
    }
    return p;
}

void fact(long long n){
    if (n == 1) return ;
    if (checkprime(n)) {alpha[n]++; return;}

    if (n <= 10000) {
        brute(n); return;
    }
    long long p = 0;
    while (p == 0 || p == n){
        p = findFactor(n);
    }
    fact(p); fact(n / p);
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long n;

    while (cin >> n){
        alpha.clear();
        fact(n);
        for (auto i: alpha){
            cout << i.first << "^" << i.second << "\n";
        }
    }
    
    return 0;
}