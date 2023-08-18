const long long INF = 1e18;

struct Edge {
    int u, v, c;
};

Edge e[5005];
long long d[2505];
vector<int> posCycle;
bool negCycle = 0;

long long bellman_ford(int n, int m) {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }

    d[1] = 0;

    for (int i = 1; i <= n; i++) {
        bool decrease = 0;

        for (int j = 1; j <= m; j++) {
            if (d[e[j].u] < INF) {
                if (d[e[j].v] > d[e[j].u] + e[j].c) {
                    d[e[j].v] = d[e[j].u] + e[j].c;
                    decrease = 1;

                    if (i == n) { // negative cycle
                        posCycle.push_back(e[j].v);
                        negCycle = 1; 
                    }
                }
            }
        }

        if (!decrease) break;
    }

    return d[n];
}