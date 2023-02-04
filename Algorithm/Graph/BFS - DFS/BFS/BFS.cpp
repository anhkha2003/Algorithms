z#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
int cost[100005];
bool visit[100005];

void bfs(int n) {
    queue <int> q;
    q.push(n);
    visit[n] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto i: adj[u]) {
            if (visit[i] == false) {
                visit[i] = true;
                cost[i] = cost[u] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, m, x, u , v, p;
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= x; i++) {
        bfs(1);
        cin >> p;
        cout << cost[p] << endl;
    }
    return 0;
}
