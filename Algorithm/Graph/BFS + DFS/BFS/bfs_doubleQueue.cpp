#include<bits/stdc++.h>
using namespace std;

const long long BASE = 1e9;
const long long INF = 1e18;

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int a[4][100005];
long long dist[4][100005];
bool vs[4][100005];

bool isValid(int x, int y) {
    return (1 <= x && x <= 3 && 1 <= y && y <= n);
}

void bfs(int x1, int x2) {
    queue<pair<int, int>> q1, q2;
    vector<pair<int, int>> inqueue;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n ; j++) {
            dist[i][j] = -1e18;
            vs[i][j] = 0;
        }
    }

    q1.push({x1, x2});
    vs[x1][x2] = 1;
    dist[x1][x2] = a[x1][x2];

    while (!q1.empty()) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        while (!q2.empty()) {
            int x = q2.front().first;
            int y = q2.front().second;
            q2.pop();

            for (int i = 0; i <= 3; i++) {
                int u = x + dx[i];
                int v = y + dy[i];
                if (vs[u][v] == 0 && isValid(u, v)) {
                    if (dist[u][v] < dist[x][y] + a[u][v]) {
                        if (dist[u][v] == -1e18) inqueue.push_back({u, v});
                        dist[u][v] = dist[x][y] + a[u][v];
                    }
                }
            }
        }

        for (auto i: inqueue) {
            vs[i.first][i.second] = 1;
            q1.push(i);
        }
        inqueue.clear();
    }
}

int main() {
    freopen("BONUS3ROWS.INP", "r", stdin);
    freopen("BONUS3ROWS.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int q;
    cin >> n >> q;

    int cnt = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= q; i++) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;

        bfs(x, y);
        cout << dist[u][v] << '\n';
    }



    return 0;
}


