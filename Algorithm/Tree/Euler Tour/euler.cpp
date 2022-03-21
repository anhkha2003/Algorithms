#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int euler[400005];
int first[200005];
int last[200005];

int cnt;
void dfs(int n, int p) {
    euler[++cnt] = n;
    first[n] = cnt;
    for (auto i: adj[n]) {
        if (i == p) continue;
        dfs(i, n);
    }
    euler[++cnt] = n;
    last[n] = cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    
    for (int i = 1; i <= 2 * n; i++) {
        cout << euler[i] << " ";
    }

    return 0;
}