#include <bits/stdc++.h>
using namespace std;

int trace[5000005]; // trace[i] là ước NT lớn nhất của i
int a[5000005];
int cnt[5000005];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = i; j <= n; j += i) {
                trace[j] = i;
            }
        }
    }
}

// faster
// void sieve(int n) {
//     for (int i = 2; i * i <= n; ++i) {
//         if (trace[i] == 0) { //if i is prime
//             for (int j = i * i; j <= n; j += i) {
//                 if (trace[j] == 0) {
//                     trace[j] = i;
//                 }
//             }
//         }
//     }
//     for (int i = 2; i <= n; ++i) {
//         if (trace[i] == 0) {
//             trace[i] = i;
//         }
//     }
// }

int main() {
    // phân tích thừa số NT
    for (int i = 1; i <= n; i++) {
		while (a[i] > 1) {
			int p = trace[a[i]];
			while (a[i] % p == 0) {
				a[i] /= p;
				cnt[p]++;
			}
		}
    }
}
// isPrime if trace[m] = m
// trace[m] is max divisor of m


// vector <vector<int>> a(n + 1, vector<int> (m + 1))