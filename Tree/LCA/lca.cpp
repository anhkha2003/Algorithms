struct LCA {
    int n, logn = 0, root = 1;
    vector<vector<int>> adj, p;
    vector<int> h;
 
    LCA(int n): n(n) {
        while ((1 << logn) <= n) logn++;
        p.assign(n + 1, vector<int>(logn + 1));
        h.resize(n + 1);
        adj.resize(n + 1);
    }
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void dfs(int u, int par) {
        h[u] = h[par] + 1;
        p[u][0] = par;
        for (auto i: adj[u]) {
            if (i != par) dfs(i, u);
        }
    }
 
    void initJumps() {
        for (int j = 1; j <= logn; j++) {
            for (int i = 1; i <= n; i++) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }    
    }

    void setup() {
        dfs(1, 0);
        initJumps();
    }

    int getKthAnc(int n, int k) { // jump k nodes from n
        int node = n;
        for (int i = logn; i >= 0; i--) {
            if (p[node][i] != -1 && (1 << i) <= k) {
                node = p[node][i];
                k -= (1 << i);
            }
        }
        return node;
    } 
 
    int lca(int u, int v){
        if (h[u] < h[v]) swap(u, v);
        if (h[v] < h[u]) { // jump u to v
            for (int i = logn; i >= 0; i--) {
                if (h[p[u][i]] >= h[v]) u = p[u][i];
            }
        }
 
        for (int i = logn; i >= 0; i--) {
            if (p[u][i] != p[v][i]) {
                u = p[u][i]; 
                v = p[v][i];
            }
        }
        
        while (u != v){
            u = p[u][0]; 
            v = p[v][0];
        }
 
        return u;
    }

    int dist(int u, int v) {
        return h[u] + h[v] - 2 * h[lca(u, v)];
    } 
};
 