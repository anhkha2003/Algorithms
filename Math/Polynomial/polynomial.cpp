#include <bits/stdc++.h>
using namespace std;

vector<int> mulPoly(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    vector<int> res;
    res.resize(n + m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i + j] += a[i] * b[j];
        }
    }
    return res;
}

vector<int> modPoly(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();

    while (n >= m) {
        int val = a.back();
        for (int i = 0; i < m; i++) {
            a[i + n - m] -= val * b[i];
        }
        a.pop_back();
        n--;
    }

    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> a, b;

    int x;
    for (int i = 1; i <= n ; i++) {
        cin >> x;
        a.push_back(x);
    }

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        b.push_back(x);
    }

    auto c = modPoly(a, b);
    for (auto i: c) {
        cout << i << ' ';
    }    



    return 0;
}