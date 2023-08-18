struct BridgeArcPoint {
    int time = 0, n;
    vector<int> num, low, criticalNodes;
    vector<vector<int>> adj;
    vector<pair<int, int>> bridges;

    BridgeArcPoint(int n, vector<vector<int>> adj): n(n), adj(adj) {
        num.resize(n + 1);
        low.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!num[i]) dfs(i, 0, i);
        }
    }

    void dfs(int u, int par, int root) {
        int numChild = 0;
        low[u] = num[u] = ++time;

        bool isCritical = false;
        for (auto i: adj[u]) {
            if (i == par) continue;
            if (num[i]) {
                low[u] = min(low[u], num[i]);
            }
            else {
                dfs(i, u, root);
                numChild++;
                low[u] = min(low[u], low[i]);
                
                if (low[i] > num[u]) {
                    bridges.push_back({u, i}); // Bridge
                }

                if (u == root) {
                    if (numChild >= 2) isCritical = true;
                }
                else {
                    if (low[i] >= num[u]) isCritical = true;
                }
            }
        }
        if (isCritical) criticalNodes.push_back(u);
    }
};