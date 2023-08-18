// if u can go to v, index of u < index of v

// can use to find the longest path btw any pair of vertices

struct TopoSort {
    int n;
    bool cycle = 0;
    vector<vector<int>> adj;
    vector<bool> visit;
    vector<int> res;
    vector<bool> inStack;

    TopoSort(int n): n(n) {
        adj.resize(n + 1);
        visit.resize(n + 1);
        inStack.resize(n + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int n) {
        if (visit[n]) return;
        visit[n] = 1;
        inStack[n] = 1;
        for (auto i: adj[n]) {
            if (!visit[i]) dfs(i);
            else if (inStack[i]) cycle = 1;
        }
        inStack[n] = 0;
        res.push_back(n);
    }

    void topological_sort() {
        res.clear();
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                dfs(i);
            }
        }
        reverse(res.begin(), res.end());
    }
};