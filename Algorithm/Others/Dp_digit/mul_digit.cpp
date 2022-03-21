#include<bits/stdc++.h>
using namespace std;

// an integer interesting if 
// the product of its digits is 
// divisible by the sum of its digits

// l <= r <= 10^12

template <class T>
struct Compressor {
    vector<T> values, orig;
    void add(T x) {
        values.push_back(x);
    }

    void compress() {
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        orig.resize(values.size() + 1);

        for (int i = 0; i < values.size(); i++) {
            orig[i + 1] = values[i];
        }
    }

    // return index of value: a[i] >= x (lower_bound)
    T find(T x) {
        return lower_bound(values.begin(), values.end(), x) - values.begin() + 1;
    }
};

Compressor<long long> comp;

void genMul(int i, int cur, long long mul) {
    if (i <= 12) {
        comp.add(mul);
        if (i == 12) return;
    }

    for (int d = cur; d <= 9; d++) {
        genMul(i + 1, d, mul * d);
    }
}

vector<int> num;
long long d[15][8500][150][2];

long long dp(int pos, int idxMul, int sum, bool exceed) {
    if (pos == num.size()) {
        if (sum == 0) return 0;
        return (comp.orig[idxMul] % sum == 0);
    }

    if (d[pos][idxMul][sum][exceed] != -1) return d[pos][idxMul][sum][exceed];

    long long ans = 0;

    int lim = 9;
    if (exceed == 0) lim = num[pos];

    for (int digit = 0; digit <= lim; digit++) {
        bool newExceed = exceed;
        if (digit < lim) newExceed = 1;

        // 005 = 5
        // idxMul = 0: all prefixes are 0
        int newIdx = 0;
        if (idxMul == 0) {
            if (digit == 0) newIdx = 0;
            else newIdx = comp.find(digit);
        }
        else {
            long long newMul = comp.orig[idxMul] * digit;
            newIdx = comp.find(newMul);
        }

        int newSum = sum + digit;
        ans += dp(pos + 1, newIdx, newSum, newExceed);
    }

    return d[pos][idxMul][sum][exceed] = ans;
}

long long solve(long long a) {
    num.clear();
    while (a > 0) {
        num.push_back(a % 10);
        a /= 10;
    }

    reverse(num.begin(), num.end());

    memset(d, -1, sizeof(d));

    long long res = dp(0, 0, 0, 0);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    genMul(0, 0, 1);

    comp.compress();

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        long long l, r;
        cin >> l >> r;

        cout << "Case #" << z << ": ";
        cout << solve(r) - solve(l - 1) << "\n";
    }

    return 0;
}