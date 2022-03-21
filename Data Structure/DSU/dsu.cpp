struct DSU {
    vector<int> root;
    int n;
    DSU(int n): n(n) {
        root.assign(n + 1, -1);
    }

    // root[x] > 0: parent of x
    // root[x] < 0: size of part include x

    int findRoot(int u) {
        while (root[u] >= 0) {
            u = root[u];
        }
        return u;
    }
    // root[findRoot] < 0: size của TPLT

    bool merge(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return 0;

        if (root[x] > root[y]) {
            swap(x, y); // số âm
        }
        // smaller attach to bigger

        root[x] += root[y];
        root[y] = x;

        return 1;
    }
};
