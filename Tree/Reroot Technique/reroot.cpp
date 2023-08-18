#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[200005];
int sub[200005];
long long sum[200005]; // sum distance of subtree
long long res[200005]; // sum distance
 
void dfs(int n, int p) {
    sub[n] = 1;
    for (auto i: adj[n]) {
        if (i == p) continue;
 
        dfs(i, n);
 
        sub[n] += sub[i];
        sum[n] += sum[i] + sub[i];
    }
}
 
void dfs2(int n, int p, int num) {
    for (auto i: adj[n]) {
        if (i == p) continue;
 
        // tùy vào cách tính
        res[i] = res[n] + num - 2 * sub[i];
        dfs2(i, n, num);
    }
}
 
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1, 0);
 
    res[1] = sum[1];
 
    dfs2(1, 0, n);
 
    for (int i = 1; i <= n; i++) {
        cout << res[i] <<  " ";
    }
 
    return 0;
}