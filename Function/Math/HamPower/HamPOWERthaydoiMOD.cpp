#include<bits/stdc++.h>

using namespace std;

long long pw(long long x, long long n, long long k) {
    if (n == 0) {
        return 1;
    }
    long long m = pw(x, n / 2, k) % k;
    if (n % 2 == 0) {
        return m * m % k;
    }
    return m * m % k * x % k;
}
