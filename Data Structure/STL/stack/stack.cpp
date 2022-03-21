#include <bits/stdc++.h>
using namespace std;

// for 1 to n: find the largest left j: a[i] >= a[j]
// for n to 1: find the smallest right j: a[i] >= a[j]
vector<int> calcLeft(vector<int> &a) {
    int n = a.size() - 1;
    stack<int> s;
    vector<int> maxLeft(n + 1);

    for (int i = 1; i <= n; i++) {
        // < : a[i] <= a[j]
        while (s.size() && a[s.top()] > a[i]) {
            s.pop();
        }

        if (s.size()) maxLeft[i] = s.top();
        s.push(i);
    }
    return maxLeft;
}

long long solve(vector<int> &a) {
    int n = a.size() - 1;
    auto maxLeft = calcLeft(a);

    reverse(a.begin() + 1, a.end());

    auto maxRight = calcLeft(a);
    reverse(maxRight.begin() + 1, maxRight.end());

    for (int i = 1; i <= n; i++) {
        maxRight[i] = n + 1 - maxRight[i];
    }

    reverse(a.begin() + 1, a.end());

    long long res = -1e18;
    for (int i = 1; i <= n; i++) {
        res = max(res, (maxRight[i] - maxLeft[i] - 1) * 1ll * a[i]);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    calcLeft(h);

    for (int i = 1; i <= n; i++) {
        cout << minLeft[i] << " ";
    }

    return 0;
}