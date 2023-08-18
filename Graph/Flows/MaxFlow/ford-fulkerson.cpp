#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
int c[1005][1005], f[1005][1005];
int trace[1005];
vector<int> adj[1005];
long long maxFlow = 0;

bool findPath(int u, int v) {
    memset(trace, 0, sizeof(trace));

    trace[u] = -1;

    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int p = q.front();
        q.pop();

        for (auto i: adj[p]) {
            if (trace[i] == 0 && c[p][i] > f[p][i]) {
                trace[i] = p;
                q.push(i);
            }
        }
    }

    if (trace[v]) return 1;
    return 0;
}

void incFlow() {
    int plus = 1e9;
    
    int v = t;
    while (v != s) {
        int u = trace[v];
        plus = min(plus, c[u][v] - f[u][v]);
        v = u;
    }

    v = t;
    while (v != s) {
        int u = trace[v];
        f[u][v] += plus;
        f[v][u] -= plus;
        v = u;
    }

    maxFlow += plus;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] = w;
    }

    while (findPath(s, t)) {
        incFlow();
    }
    cout << maxFlow;

    return 0;
}