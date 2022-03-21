#include <bits/stdc++.h>
using namespace std;

/* z[i] : longest prefix at pos i*/
/* z[1 ... j] = z[i ... i + j - 1] */ 

struct ZAlgo {
    vector<int> z;
    string s;
    ZAlgo(string s): s(s) {
        int n = s.length();
        z.resize(n);
        
        int x = 0, y = 0;
        for (int i = 1; i <= n - 1; i++) {
            z[i] = max(0, min(z[i - x], y - i + 1));
            while (i + z[i] < n && s[z[i]] == s[z[i] + i]) {
                x = i;
                y = i + z[i];
                z[i]++;
            }
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    ZAlgo zAlgo(s);

    cout << s.size() << " ";
    for (int i = 1; i < s.size(); i++) {
        cout << zAlgo.z[i] << " ";
    }
    return 0;
}