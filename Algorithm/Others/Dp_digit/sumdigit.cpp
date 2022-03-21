#include <bits/stdc++.h>
using namespace std;

int a, b;
vector<int> num;
long long d[15][100][2];

long long dp(int pos, int sum, bool exceed) {
    if (pos == num.size()) {
        return sum;
    }

    if (d[pos][sum][exceed] != -1) return d[pos][sum][exceed];

    long long ans = 0;

    int lim = 9;
    if (exceed == 0) lim = num[pos];

    for (int digit = 0; digit <= lim; digit++) {
        bool newExceed = exceed;
        if (digit < lim) newExceed = 1;

        int newSum = sum + digit;
        ans += dp(pos + 1, newSum, newExceed);
    }

    return d[pos][sum][exceed] = ans;
}

long long solve(long long a) {
    num.clear();
    while (a > 0) {
        num.push_back(a % 10);
        a /= 10;
    }

    reverse(num.begin(), num.end());

    memset(d, -1, sizeof(d));

    long long res = dp(0, 0, 0);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    while (cin >> a >> b) {
        if (a == -1 && b == -1) break;

        cout << solve(b) - solve(a - 1) << "\n";
    }    

    return 0;
}