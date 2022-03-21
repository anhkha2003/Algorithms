#include <bits/stdc++.h>
using namespace std;

// Định lý Euler: a ^ phi(n) = 1 (mod n) với (a, n) = 1
// với p là SNT: a ^ (p - 1) = 1 (mod p)

// phi(n): số số nguyên dương từ 1 tới n mà NTCN với n

// sum phi(d) = n   with d|n

// ĐPT: O(sqrt(n))
int phiEuler(int n) { // = n * (1 - 1/p1) ... (1 - 1/pn)
	int m = sqrt(n);

	int res = n;
	for (int i = 2; i <= m; i++) {
		if (n % i == 0) {
			res -= res / i;
			while (n % i == 0) n /= i;
		}
	}

	if (n > 1) res -= res / n;
	return res;
}

// ĐPT: O(log(n)) with n <= 1e7
sieve(10000000);

for (int i = 1; i <= 10000000; i++) {
    phi[i] = i;

    int x = i;
    while (x > 1) {
        int p = trace[x];
        if (x % p == 0) {
            while (x % p == 0) x /= p;
            phi[i] -= phi[i] / p;
        }
    }
}