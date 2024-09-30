const int INF = 1e9;

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
