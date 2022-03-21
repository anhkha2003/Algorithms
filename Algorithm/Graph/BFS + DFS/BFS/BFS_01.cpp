void bfs(int gX, int gY) {
    deque<pair<int, int>> q;
    q.push_front({gX, gY});
    d[gX][gY] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop_front();
        for (int i = 0; i <= 3; i++) {
            int x = u.first + dx[i];
            int y = u.second + dy[i];
            if (isValid(x, y)) {
                int w = 0;
                if (c[x][y] == '*') w = 1;

                if (d[x][y] == -1 || d[x][y] > d[u.first][u.second] + w) {
                    d[x][y] = d[u.first][u.second] + w;
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
}