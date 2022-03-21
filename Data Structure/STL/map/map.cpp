#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

gp_hash_table<int, int> cnt;

struct CMP {
    bool operator() (const double& a, const double& b) const {
        return a < b - eps;
    }
};

map<double, int, CMP> m;

const long long MOD = 1e9 + 7;
map<long long, long long> f; // map là 1 mảng lưu đc số có giá trị lớn

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
