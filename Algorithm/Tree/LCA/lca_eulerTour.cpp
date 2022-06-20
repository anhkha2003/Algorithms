#include<bits/stdc++.h>
using namespace std;

struct RMQ {
    vector<int> a;
    vector<vector<pair<int, int>>> sparseMax, sparseMin;
    int n;
    RMQ(vector<int> arr = {}) {
        a = arr;
        n = arr.size();
        sparseMax.resize(n);
        sparseMin.resize(n);
        for (int i = 0; i < n; i++) {
            sparseMax[i].resize(__lg(n) + 1);
            sparseMax[i][0] = {a[i], i};

            sparseMin[i].resize(__lg(n) + 1);
            sparseMin[i][0] = {a[i], i};
        }

        for (int len = 1; len < __lg(n) + 1; len++) {
            for (int i = 0; i + (1 << (len - 1)) < n; i++) {
                sparseMax[i][len] = max(sparseMax[i][len - 1], sparseMax[(1 << (len - 1)) + i][len - 1]);
                sparseMin[i][len] = min(sparseMin[i][len - 1], sparseMin[(1 << (len - 1)) + i][len - 1]);
            }
        }
    }

    pair<int, int> queryMax(int l, int r) {
        int k = __lg(r - l + 1);
        return max(sparseMax[l][k], sparseMax[r - (1 << k) + 1][k]);
    }

    pair<int, int> queryMin(int l, int r) {
        int k = __lg(r - l + 1);
        return min(sparseMin[l][k], sparseMin[r - (1 << k) + 1][k]);
    }
};

struct LCA {
    vector<vector<int>> adj;
    vector<int> h, first, euler, eulerHeight;
    int n;

    RMQ rmqHeight, rmqFirst;

    LCA(int n): n(n) {
        euler.resize(2 * n + 1);
        eulerHeight.resize(2 * n + 1);
        first.resize(n + 1); 
        h.resize(n + 1); 
        adj.resize(n + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    void dfs(int n, int par) {
        h[n] = h[par] + 1;
        euler[++cnt] = n;
        eulerHeight[cnt] = h[euler[cnt]];
        first[n] = cnt;
        for (auto i: adj[n]) {
            if (i == par) continue;
            dfs(i, n);
            euler[++cnt] = n;
            eulerHeight[cnt] = h[euler[cnt]];
        }
    } 

    void initRMQ() {
        rmqHeight = RMQ(eulerHeight);
        rmqFirst = RMQ(first);
    }

    int lca(int u, int v) {
        int l = first[u];
        int r = first[v];
        if (l > r) swap(l, r);
        return euler[rmqHeight.queryMin(l, r).second];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n, q;
    cin >> n >> q;

    LCA lca(n);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        lca.addEdge(i, p + 1);
    }

    lca.dfs(1, 0);
    lca.initRMQ();

    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;

        u++; v++;
        cout << lca.lca(u, v) - 1 << "\n"; 
    }

    return 0;
}