#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<int, int> par[1005][1005];
int d[1005][1005];

bool isValid(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m && c[x][y] != '#')
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
 
    while (q.size()) {
        auto u = q.front();
        q.pop();
 
        for (int i = 0; i <= 3; i++) {
            int newX = dx[i] + u.first;
            int newY = dy[i] + u.second;
            if (isValid(newX, newY) && d[newX][newY] == -1) {
                par[newX][newY] = u;                
                d[newX][newY] = d[u.first][u.second] + 1;
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int xA = 0, yA = 0;
    int xB = 0, yB = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'A') {
                xA = i;
                yA = j;
            }

            if (c[i][j] == 'B') {
                xB = i;
                yB = j;
            }
        }
    }

    bfs(xA, yA);

    vector<pair<int, int>> path;
    auto u = {xB, yB};
    
    while (u != {xA, yA}) {
        path.push_back(u);
        u = par[u.first][u.second];
    }

    if (d[xB][yB] != -1) {
        cout << "YES" << "\n";
        cout << d[xB][yB] << "\n";
        for (auto i: path) {
            cout << path[i];
        }
    }
    else {
        cout << "NO";
    }
    return 0;
}