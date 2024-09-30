// Find the recurrence (Berlekamp-Massey)
// For recurrence length n, need at least 2n elements of s 
// Find coefficients of linear recurrence
// Input: s[0..n-1], Output: c[0..d], such that s[i] = sum s[i-j]*c[j] for j = 1 to d
// Time complexity: O(n^2)

const long long MOD = 998244353;

long long pw(long long a, long long n) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

vector<long long> berlekampMassey(vector<long long> s) {
    vector<long long> c(1, 0), oldC(1, 0);
    int f = -1;
    for(int i = 0; i < s.size(); i++) {
        long long delta = s[i];
        for(int j = 1; j < c.size(); j++) {
            delta -= s[i - j] * c[j] % MOD;
            delta %= MOD;
        }

        if (delta == 0) continue;
 
        if (f == -1) {
            f = i;
            c.resize(i + 2, 0);
        } else {
            vector<long long> d = oldC;
            int fp = f;
            if (i - (int) c.size() > f - (int) oldC.size())
                oldC = c, fp = i;
            for(long long &x : d)
                x *= -1;
            d.insert(d.begin() + 1, 1);
            long long div = 0;
            for(int j = 1; j < d.size(); j++) {
                div += s[f - j + 1] * d[j];
                div %= MOD;
            }
            long long coef = delta * pw(div, MOD - 2) % MOD;
            for(long long &x : d)
                x = x * coef % MOD;
            d.insert(d.begin() + 1, i - f - 1, 0);
            if (c.size() < d.size())
                c.resize(d.size(), 0);
            for(int j = 1; j < d.size(); j++) {
                c[j] += d[j];
                c[j] %= MOD;
                if (c[j] < 0) c[j] += MOD;
            }
            f = fp;
        }
    } 
    return c;
}

// Find k-th element of linear recurrence
// find S[k], given first elements of S and c: S[i] = sum S[i-j]*c[j] for j = 1 to d
// c uses 1-index
// Time complexity: O(n^2 * log(k))
long long linearRec(const vector<long long>& S, const vector<long long>& c, long long k) {
    int n = int(c.size()) - 1;
    assert(S.size() + 1 >= c.size());

    auto combine = [&](vector<long long> a, vector<long long> b, bool e = false) {
        // multiply a * b * x^e
        vector<long long> res(int(a.size()) + int(b.size()));
        for (int i = 0; i < int(a.size()); i++) {
            for (int j = 0; j < int(b.size()); j++) {
                res[i + j + e] += a[i] * b[j];
                res[i + j + e] %= MOD;
            }
        }
        for (int i = int(res.size())-1; i >= n; --i) {
            for (int j = 1; j <= n; j++) {
                res[i - j] += res[i] * c[j];
                res[i - j] %= MOD;
            }
        }
        res.resize(n);
        return res;
    };

    vector<long long> pol(n);
    if (n > 0) pol[0] = 1;

    assert(k >= 0);
    for (int i = 64 - 1 - (k == 0 ? 64 : __builtin_clzll(k)); i >= 0; i--) {
        pol = combine(pol, pol, (k >> i) & 1);
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += pol[i] * S[i];
        res %= MOD;
    }
    return res;
}