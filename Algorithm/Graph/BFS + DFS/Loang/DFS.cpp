#include <bits/stdc++.h>

using namespace std;

int xx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int yy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
char a[105][105];
bool check[105][105];

void DFS(int x, int y) {
    if (a[x][y] == 'W') {
        check[x][y] = true;
        for (int i = 0; i <= 7; i++) {
            int u = x + xx[i];
            int v = y + yy[i];
            if (a[u][v] == a[x][y] && check[u][v] == false) {
                check[u][v] = true;
                DFS(u, v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'W' && check[i][j] == false) {
                check[i][j] = true;
                res++;
                DFS(i, j);
            }
        }
    }
    cout << res;
    return 0;
}

