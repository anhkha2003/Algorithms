#include <bits/stdc++.h>
using namespace std;

// tìm max/min đoạn tịnh tiến
vector<int> calcMin(vector<int> &a, int k) { // [i-k+1, i]
    vector<int> res;
    int n = a.size() - 1;
    deque<int> q;

    for (int i = 1; i <= n; i++) {
        while (q.size() && a[q.back()] > a[i]) {
            q.pop_back();
        }

        q.push_back(i);

        while (q.front() <= i - k) q.pop_front();

        if (i >= k) res.push_back(a[q.front()]);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    // deque = vector + queue
    deque<int> q;

    q.push_front(14);
    q.pop_back();
    q.push_back(10);
    q.pop_front();

    q.push_back(4);
    cout << q[1];
    return 0;
}