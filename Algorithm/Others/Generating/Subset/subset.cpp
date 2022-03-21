#include<bits/stdc++.h>
using namespace std;

vector<long long> gen(vector<int>& v) {
    vector<long long> res;

    int n = v.size();
    for (int bit = 0; bit < (1 << n); bit++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) { 
                sum += v[i];
            }
        }
        res.push_back(sum);
    }

    return res;
}


// MAN OF THE MATCH
// MOTM 
// MITM
// MEET IN THE MIDDLE
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);


    int n;
    cin >> n;

    long long sum = 0;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    long long res = 1e18;

    vector<int> group[2];
    for (int i = 1; i <= n; i++) {
        if (i <= n / 2) group[0].push_back(a[i]);
        else group[1].push_back(a[i]);
    }

    auto sumA = gen(group[0]); // 10^6
    auto sumB = gen(group[1]); // 10^6

    sort(sumB.begin(), sumB.end());
    
    for (auto a: sumA) {
        // abs(2 * (a + b) - sum) = 0 => b = sum / 2 - a
        long long val = sum / 2 - a;
        
        int pos = lower_bound(sumB.begin(), sumB.end(), val) - sumB.begin();
        
        for (int i = -1; i <= 1; i++) {
            if (0 <= pos + i && pos + i < sumB.size()) {
                res = min(res, abs(2 * (a + sumB[pos + i]) - sum));
            }
        }
    }

    cout << res << endl;
    
    return 0;
}