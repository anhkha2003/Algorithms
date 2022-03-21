#include <bits/stdc++.h>
using namespace std;

// Johnson's algorithm

// find the shortest paths between every 
// pair of vertices in a weighted negative graph

const long long INF = 1e18;

struct Spfa { // Shortest Path Faster Algorithm
    int n;
    vector<vector<pair<int, long long>>> adj;
    vector<long long> d;

    Spfa(int n): n(n) {
        adj.resize(n + 1);
        d.resize(n + 1);
    }

    void addEdge(int u, int v, long long c) {
        adj[u].push_back({v, c});
        // adj[v].push_back({u, c});
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

struct Dijkstra {
    typedef pair <long long, long long> II;
    vector<vector<II>> adj;
    vector<long long> d; // shortest dist
    int n; // number of vertices

    Dijkstra(int n): n(n) {
        adj.resize(n + 1);
        d.resize(n + 1);
    }

    void addEdge(int u, int v, long long c) {
        adj[u].push_back({v, c});
        // adj[v].push_back({u, c});
    }
    
    void dijkstra(int a) {
        priority_queue < II, vector<II>, greater<II> > pq;

        for (int i = 1; i <= n; i++) {
            d[i] = INF;
        }

        d[a] = 0;

        pq.push({0, a});
        while (pq.size()) {
            int du = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d[u] != du) continue;
            
            for (auto i: adj[u]){
                int v = i.first;
                int uv = i.second;

                // this v is better
                if (d[v] > du + uv){
                    d[v] = du + uv;
                    pq.push({d[v],v}); // push the better one
                }
            }
        }
    }
};

struct Edge {
    int u, v, c;
};

Edge e[5005];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, m;
        cin >> n >> m;

        Spfa spfa(n);

        bool negEdge = 0;
        int minEdge = 1e9;
        for (int i = 1; i <= m; i++) {
            cin >> e[i].u >> e[i].v >> e[i].c;
            
            spfa.addEdge(e[i].u, e[i].v, e[i].c * 1ll);
            if (e[i].c < 0) negEdge = 1;
            else minEdge = min(minEdge, e[i].c);
        }

        if (negEdge) {
            if (spfa.spfa(1) == false) {
                cout << "-inf\n";
            } 
            else {
                Dijkstra dijkstra(n);
                for (int i = 1; i <= m; i++) {
                    // w(u, v) + d[u] - d[v]
                    dijkstra.addEdge(e[i].u, e[i].v, e[i].c + spfa.d[e[i].u] - spfa.d[e[i].v]);
                }

                long long minVal = 1e18;
                for (int i = 1; i <= n; i++) {
                    dijkstra.dijkstra(i);

                    for (int j = 1; j <= n; j++) {
                        if (j == i) continue;
                        minVal = min(minVal, dijkstra.d[j] + spfa.d[j] - spfa.d[i]);
                    }
                }

                cout << minVal << "\n";
            }
        }
        else {
            cout << minEdge << "\n";
        }
    }
    
    return 0;
}