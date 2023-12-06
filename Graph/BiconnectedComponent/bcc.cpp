// block-cut tree
// block: biconnected component (containing critical nodes)
// cutpoints: critical nodes (consider as nodes in tree)
// tree contains both block and cutpoints
struct BiconnectedComponent {
    int time = 0, n, numBCC = 0;
    vector<int> num, low, bccIdx, critical, temp;
    vector<vector<int>> adj, bcc;
    vector<pair<int, int>> stack;

    BiconnectedComponent(int n, vector<vector<int>> adj): n(n), adj(adj),
    num(n + 1), low(n + 1), bccIdx(n + 1), 
    bcc(n + 1), critical(n + 1), temp(n + 1) {
        for (int i = 1; i <= n; i++) {
            if (!num[i]) dfs(i, 0, i);
        }
    }

    void dfs(int u, int par, int root) {
        int numChild = 0;
        low[u] = num[u] = ++time;

        for (auto i: adj[u]) {
            if (i == par) continue;
            if (num[i]) {
                if (num[i] < num[u]) stack.push_back({u, i});
                low[u] = min(low[u], num[i]);
            }
            else {
                stack.push_back({u, i});
                numChild++;
                dfs(i, u, root);
                low[u] = min(low[u], low[i]);
                
                if (u == root) {
                    if (numChild >= 2) critical[u] = true;
                }
                else {
                    if (low[i] >= num[u]) critical[u] = true;
                }

                if (low[i] >= num[u]) {
                    numBCC++;
                    while (stack.size()) {
                        auto [x, y] = stack.back();
                        stack.pop_back();

                        // critical can belong to multiple BCCs
                        bccIdx[x] = numBCC; 
                        bccIdx[y] = numBCC;

                        if (!temp[x]) {
                            bcc[numBCC].push_back(x);
                            temp[x] = 1;
                        }
                        if (!temp[y]) {
                            bcc[numBCC].push_back(y);
                            temp[y] = 1;
                        }
                                                
                        if (x == u && y == i) break;
                    }

                    for (auto j: bcc[numBCC]) temp[j] = 0;
                }
            }
        }
    }
};