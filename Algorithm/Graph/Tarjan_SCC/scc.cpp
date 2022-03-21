#include <bits/stdc++.h>
using namespace std;

struct SCC {
    vector<vector<int>> adj, scc;
    vector<int> num, low, stack, vs, sccIdx;
    int time, n;
    
    SCC(int n): n(n) {
        adj.resize(n + 1);
        num.resize(n + 1);
        low.resize(n + 1);
        vs.resize(n + 1);
        sccIdx.resize(n + 1);
        time = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void setup() {
        for (int i = 1; i <= n; i++) {
            if (!num[i]) dfs(i);
        }
    }

    void dfs(int a) {
        low[a] = num[a] = ++time;
        stack.push_back(a);
        for (auto i: adj[a]) {
            if (!num[i]) dfs(i);
            if (!vs[i]) low[a] = min(low[a], low[i]);
        }
        if (num[a] == low[a]) {
            vector<int> curSCC;
            while (stack.size()) {
                int b = stack.back();
                curSCC.push_back(b);
                stack.pop_back();
                vs[b] = 1;
                if (b == a) break;
            }
            scc.push_back(curSCC);

            for (auto i: curSCC) {
                sccIdx[i] = scc.size();
            }
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    SCC scc(n);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        scc.addEdge(u, v);
    }

    scc.setup();

    for (auto v: scc.scc) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}