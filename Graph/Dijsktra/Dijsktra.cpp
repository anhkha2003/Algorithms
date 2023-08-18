// for every edge u, v with length c:
// adj[u].push_back(II(v, c));
// adj[v].push_back(II(u, c)); if 2-way edge

// use struct when there are more than 3 nums
struct CMP {
    bool operator() (int a, int b) {
        return a > b;
    }
}

const int INF = 1e9;

struct Dijkstra {
    typedef pair <int, int> II;
    vector<vector<II>> adj;
    vector<int> d; // shortest dist
    int n;
    priority_queue<II, vector<II>, greater<II>> pq;

    Dijkstra(int n): n(n) {
        adj.resize(n + 1);
        d.resize(n + 1);
    }

    void addEdge(int u, int v, int c) {
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    void dijkstra(int a) {
        while (pq.size()) pq.pop();
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