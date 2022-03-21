#include <bits/stdc++.h>
using namespace std;

vector<int> calcMin(vector<int> &a, int k) {
    vector<int> res;
    int n = a.size() - 1;
    deque<int> q;

    for (int i = 0; i <= n; i++) {
        while (q.size() && a[q.back()] > a[i]) {
            q.pop_back();
        }

        q.push_back(i);

        while (q.front() <= i - k) q.pop_front();

        res.push_back(a[q.front()]);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto minRange = calcMin(a, k);

    for (int i = 0; i <= n; i++) {
        cout << minRange[i] << ' ';
    }
    
    return 0;
}