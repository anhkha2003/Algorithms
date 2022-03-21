#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

int root[10005];
// root[x] > 0: parent của x
// root[x] < 0: size của TPLT chứa x

int findRoot(int u) {
    while (root[u] >= 0) {
        u = root[u];
    }
    return u;
}

bool merge(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if (x == y) return 0;

    if (root[x] > root[y]) {
        swap(x, y); // số âm
    }
    root[x] += root[y];
    root[y] = x;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 1; i <= m; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 1; i <= n; i++) {
        root[i] = -1;
    }

    int res = 0;
    for (auto &e: edges) {
        if (merge(e.u, e.v)) {
            res += e.w;
        }
    }
    cout << res;
    return 0;
}
