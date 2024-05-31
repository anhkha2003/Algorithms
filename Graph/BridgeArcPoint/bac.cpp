struct BridgeArcPoint {
    int time = 0, n;
    vector<int> num, low, criticalNodes, stack, bccIdx;
    vector<vector<int>> adj, components;
    vector<pair<int, int>> bridges;

    BridgeArcPoint(int n, vector<vector<int>> adj): n(n), adj(adj) {
        num.resize(n + 1);
        low.resize(n + 1);
        bccIdx.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!num[i]) {
                dfs(i, 0, i);
                components.push_back(stack);
                while (stack.size()) {
                    bccIdx[stack.back()] = components.size();
                    stack.pop_back();
                }
            }
        }
    }

    void dfs(int u, int par, int root) {
        int numChild = 0;
        low[u] = num[u] = ++time;
        stack.push_back(u);

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
                
                // check bridge
                if (low[i] > num[u]) {
                    bridges.push_back({u, i}); // Bridge

                    // finding connected components after deleting bridges
                    vector<int> curCC;
                    while (stack.size()) {
                        int v = stack.back();
                        stack.pop_back();
                        curCC.push_back(v);
                        if (v == i) break;
                    }
                    components.push_back(curCC);

                    for (auto j: curCC) {
                        bccIdx[j] = components.size();
                    }
                }

                // check critical nodes
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
