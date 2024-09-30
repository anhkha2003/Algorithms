#include <bits/stdc++.h>
using namespace std;

// solve system of difference constraints
// by finding shortest path algorithms

// xj - xi <= w   => addEdge(i, j, w)
// if negative cycle exists: No solution
// add imaginery node s to all other nodes (s, i, 0)
// xi = D(s, i): shortest path from s to i

typedef pair<int, int> II;

const int INF = 1e9;
int cnt = 0;

struct SPFA { // Shortest Path Faster Algorithm
    int n;
    vector<vector<pair<int, int>>> adj;
    vector<int> d;

    SPFA(int n): n(n) {
        adj.resize(n + 1);
        d.resize(n + 1);
    }

    void addEdge(int u, int v, int c) {
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    } 

    bool spfa(int s) {
        d.assign(n + 1, INF);
        vector<int> cnt(n + 1, 0);
        vector<bool> inqueue(n + 1, false);
        queue<int> q;

        d[s] = 0;
        q.push(s);
        inqueue[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inqueue[u] = false;

            for (auto [v, w]: adj[u]) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    if (!inqueue[v]) {
                        q.push(v);
                        inqueue[v] = true;
                        cnt[v]++;
                        if (cnt[v] > n) {
                            return false;  // negative cycle
                        }
                    }
                }
            }
        }
        return true;
    }
};


int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    Spfa spfa(n + 2);

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;

        // s[r] - s[l - 1] = 1 
        // 1 <= s[r] - s[l - 1] <= 1
        spfa.addEdge(l, r + 1, 1);
        spfa.addEdge(r + 1, l, -1);
    }

    for (int i = 1; i <= n; i++) {
        // 0 <= s[i] - s[i - 1] <= 1
        spfa.addEdge(i, i + 1, 1);
        spfa.addEdge(i + 1, i, 0);
    }

    // add imaginery node
    for (int i = 1; i <= n; i++) {
        spfa.addEdge(n + 2, i, 0);
    }

    // need to add (0, n, x) and (n, 0, -x): exists solution
    if (spfa.spfa(1) == false) cout << -1;
    else cout << spfa.d[n + 1];

    return 0;
}