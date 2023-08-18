// get Eulerian Cycle / Eulerian Path
// to get path, choose starting and ending vertex first
// starting vertex in undirected graph: 1 of 2 vertex has odd degrees
//                 in directed graph: out[i] - in[i] = 1 

struct EulerianPath {
    struct Edge {
        int to, index;
    };

    vector<vector<Edge>> adj;
    int n, m;
    int startVertex;

    EulerianPath(int n): n(n){
        adj.resize(n + 1);
        startVertex = -1;
        m = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back({v, ++m});
        adj[v].push_back({u, m});
    }

    void dfs(int a, vector<int>& visited) {
        visited[a] = 1;
        for (auto i: adj[a]) {
            if (!visited[i.to]) {
                dfs(i.to, visited);
            }
        }
    }

    bool isEulerian() {
        vector<int> visited(n + 1);
        for (int i = 1; i <= n; i++) {
            if (adj[i].size()) {
                dfs(i, visited);
                startVertex = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() % 2) {
                return false;
            }
            if (adj[i].size() && !visited[i]) {
                return false;
            }
        }
        return true;
    }

    vector<Edge> getEulerianPath() {
        vector<int> removed(m + 1);
        vector<Edge> res;
        stack<Edge> s;

        if (startVertex == -1) {
            return res;
        }

        s.push({startVertex, -1});

        while (s.size()) {
            auto curVertex = s.top().to;
            
            while (adj[curVertex].size()) {
                auto u = adj[curVertex].back();
                if (removed[u.index]) {
                    adj[curVertex].pop_back();
                }
                else break;
            }

            if (adj[curVertex].size() == 0) {
                res.push_back(s.top());
                s.pop();
            }
            else {
                auto u = adj[curVertex].back();
                removed[u.index] = true;
                s.push({u.to, u.index});
            }
        }
        return res;
    }
};