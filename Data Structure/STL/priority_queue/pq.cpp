#include <bits/stdc++.h>
using namespace std;

// priority_queue = queue + set

priority_queue<int> q;
// từ lớn tới nhỏ

priority_queue<int, vector<int>, greater<int>> p;
// từ nhỏ tới lớn

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    q.push(10);
    q.push(4);

    int x = q.top();
    q.pop();

    return 0;
}