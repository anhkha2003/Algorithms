const int INF = 1e9;

struct Dial {
    vector<vector<pair<int, int>>> adj;
    vector<int> d;
    vector<vector<int>> bin; // bin[d] contains all i: d[i] = d
    int n;
    int maxDist;

    Dial(int n, int maxW): n(n) {
        maxDist = maxW * n; // maximum distance
        adj.resize(n + 1);
        d.resize(n + 1);
        bin.resize(maxDist + 1);
    }

    void addEdge(int u, int v, int c) {
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    void dial(int a) {
        for (int i = 1; i <= n; i++) d[i] = INF;
        for (int i = 0; i <= maxDist; i++) bin[i].clear();

        bin[0].push_back(a);
        d[a] = 0;

        int idx = 0;
        while (true) {
            while (bin[idx].empty() && idx <= maxDist) idx++;
            if (idx > maxDist) break;

            int u = bin[idx].back();
            bin[idx].pop_back();

            if (idx != d[u]) continue;
            
            for (auto [v, w]: adj[u]){
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    bin[d[v]].push_back(v);
                }
            }
        }
    }
};