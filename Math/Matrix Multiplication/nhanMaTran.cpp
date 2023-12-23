#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix {
	long long coef[105][105]; // độ dài của dãy dp
	int n;

	Matrix(int n): n(n) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				coef[i][j] = 0;
			}
		}
	}

	// a[i][j] += b[i][k] * c[k][j]
	Matrix operator * (Matrix& a) {
		Matrix res(n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					res.coef[i][j] += coef[i][k] * a.coef[k][j] % MOD;
					res.coef[i][j] %= MOD;
				}
			}
		}
		return res;
	}
};

Matrix pw(Matrix &A, long long n) {
	if (n == 1) return A;
	Matrix Q = pw(A, n / 2);
	if (n % 2 == 0) return Q * Q;
	return Q * Q * A;
}

// F(n) = a * F(n - 1) + b * F(n - 2) + c * F(n - 3)
// F(n)			=	a b c    *    F(n - 1)
// F(n - 1)			1 0 0		  F(n - 2)
// F(n - 2)			0 1 0		  F(n - 3)

long long solve(long long x, long long n) {
	Matrix A(3);

	A.coef[1][1] = x;
	A.coef[1][2] = A.coef[2][2] = 1;

	Matrix d(3);
	d.coef[1][1] = d.coef[2][1] = 1;

	Matrix res(n);

	if (n >= 1) {
		res = pw(A, n);
		res = res * d;
	}
	else {
		res = d;
	}
	
	return res.coef[1][1];
}
