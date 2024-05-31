// Use:
// Constructor: Dinic dinic(n)
// 0-index (dinic(n + 1) if 1-index)
// add edges: dinic.addEdge(u, v, c)   (u -> v)
// 
// trace: for (auto e: dinic.E) {
//  if (e.flow && e.cap) {
//      cout << e.u << " " << e.v << " " << e.flow << endl;
//  }
// }
// 
// minCut: i from (0 to dinic.N - 1): dinic.d[i] != dinic.N + 1 (list of keep vertices)
// for [u, v] in edges: keep[u] != keep[v] -> u-v is cut

// in bipartite graph: minimum vertex cover = min cut = max matching
//                     maximum independent set = n + m - max matching
// source -> left: cap = 1
// left -> right: cap = INF
// right -> sink: cap = 1
// trace: from minCut, source -> left or right -> sink
struct Edge {
    int u, v;
    long long cap, flow;
    Edge() {}
    Edge(int u, int v, long long cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
    int N;
    vector<Edge> E;
    vector<vector<int>> g;
    vector<int> d, pt;
    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
    void addEdge(int u, int v, long long cap) {
        if (u != v) {
            E.emplace_back(Edge(u, v, cap));
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(Edge(v, u, 0));
            g[v].emplace_back(E.size() - 1);
        }
    }
    bool bfs(int S, int T) {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if (u == T) break;
            for (int k: g[u]) {
                Edge &e = E[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                    d[e.v] = d[e.u] + 1;
                    q.emplace(e.v);
                }
            }
        }
        return d[T] != N + 1;
    }
    long long dfs(int u, int T, long long flow = -1) {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < g[u].size(); ++i) {
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i]^1];
            if (d[e.v] == d[e.u] + 1) {
                long long amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (long long pushed = dfs(e.v, T, amt)) {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    long long maxFlow(int S, int T) {
        long long total = 0;
        while (bfs(S, T)) {
            fill(pt.begin(), pt.end(), 0);
            while (long long flow = dfs(S, T))
                total += flow;
        }
        return total;
    }
};
