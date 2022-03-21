#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> fen;
    int n;
    BIT(int n): n(n) {
        fen.resize(n + 1);
    }
    void update(int u, int v) {
        for (int i = u; i <= n; i += i & -i) {
            fen[i] = max(fen[i], v);
        }
    }
    
    int getMax(int u) {
        int res = 0;
        for (int i = u; i; i -= i & -i) {
            res = max(res, fen[i]);
        }
        return res;
    }
    
    // find the smallest number: getSum(i) >= val
    int getKth(int val) {
        int sum = 0, pos = 0;
        
        for (int i = logN; i >= 0; i--) {
            if (pos + (1 << i) <= n && sum + fen[pos + (1 << i)] < val) {
                sum += fen[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1; 
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    BIT dp(1e6 + 5);
    for : int val = dp.getMax(a[i]) + a[i];
    for : dp.update(a[i], val);

    vector<BIT> bit(26, BIT(n));

    return 0;
}
