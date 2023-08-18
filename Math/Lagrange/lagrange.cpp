// With polynomial degree n:
// A(x) = sum (A(j) * (mul (x - xk) / (xj - xk))) (j: 1 -> n + 1, k != j)
// 1^k + 2^k + ... + n^k -> deg = k + 1

f[0] = 0;
for (int i = 1; i <= k; i++) {
    f[i] = f[i - 1] + pw(i, k);
    f[i] %= MOD;
}

// degree = k, find f[n]
// O(k) - formula with i = 0 -> k
long long lagrange(vector<long long> &f, int n, int k) {
    if (n <= k) return f[n];

    // use prefix and suffix if n - i can be 0
    long long tu = 1;
    for (int i = 0; i <= k; i++) {
        tu *= (n - i);
        tu %= MOD;
    }

    long long res = 0;
    for (int i = 0; i <= k; i++) {
        long long mau = (n - i) * fact[i] % MOD * fact[k - i] % MOD;
        if ((k - i) % 2) mau *= -1;
        mau = (mau % MOD + MOD) % MOD;

        res += f[i] * tu % MOD * pw(mau, MOD - 2) % MOD;
        res %= MOD;
    }
    return res;
}

// O(k^2) - original formula
long long lagrange(vector<long long> &f, int n, int k) {
    if (n <= k) return f[n];
    
    long long tu = 1;
    for (int i = 0; i <= k; i++) {
        tu *= (n - i);
        tu %= MOD;
    }

    long long res = 0;
    for (int i = 0; i <= k; i++) {
        long long val = f[i];
        for (int j = 0; j <= k; j++) {
            if (j == i) continue;
            val = val * (n - j) % MOD;

            if (i - j < 0) {
                val *= -1;
                val = val * pw(j - i, MOD - 2) % MOD;
            }
            else {
                val = val * pw(i - j, MOD - 2) % MOD;
            }

            val = (val % MOD + MOD) % MOD;
        }
        res += val;
        res %= MOD;
    }
    return res;
}