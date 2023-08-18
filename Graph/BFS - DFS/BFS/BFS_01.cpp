void bfs(int a) {
    deque<int> q;
    q.push_front(a);
    d[a] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop_front();
        for (auto [i, w]: adj[u]) {
            if (d[i] == -1 || d[i] > d[u] + w) {
                d[i] = d[u] + w;
                if (w == 0) {
                    q.push_front({x, y});
                }
                else {
                    q.push_back({x, y});
                }
            }
        }
    }
}