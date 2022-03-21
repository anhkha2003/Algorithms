#include <bits/stdc++.h>
using namespace std;

// 0 is false, 1 is true
vector <long long> adj[805];
bool visit[805];

void dfs(int n) {
    if (visit[n]) return;
    visit[n] = 1;
    for (auto i: adj[n]) {
        dfs(i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false) {
            visit[i] = true;
            dfs(i);
        }
    }
    return 0;
}
