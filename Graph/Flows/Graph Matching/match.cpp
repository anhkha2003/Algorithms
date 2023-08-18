#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
int match[100005], vs[100005];

bool dfs(int u, int turn) {
    if (vs[u] == turn) return 0;
    vs[u] = turn;

    for (auto i: adj[u]) {
        if (match[i] == 0 || dfs(match[i], turn)) {
            match[i] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> m >> n;
    int u, v;
    while (cin >> u >> v) {
        if (u == 0) break;
        adj[u].push_back(v);
    }

    int res = 0;
    for (int i = 1; i <= m; i++) {
        res += dfs(i, i);
    }

    cout << res << "\n";
    for (int i = 1; i <= n; i++) {
        cout << match[i] << ' ';
    }

    return 0;
}
