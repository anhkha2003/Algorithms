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

