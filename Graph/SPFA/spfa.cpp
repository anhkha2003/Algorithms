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
            int v = q.front();
            q.pop();
            inqueue[v] = false;

            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    if (!inqueue[to]) {
                        q.push(to);
                        inqueue[to] = true;
                        cnt[to]++;
                        if (cnt[to] > n) {
                            return false;  // negative cycle
                        }
                    }
                }
            }
        }
        return true;
    }
};
