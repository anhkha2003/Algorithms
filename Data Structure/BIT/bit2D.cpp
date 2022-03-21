struct BIT {
    int n, m;
    vector<vector<int>> fen;
    BIT(int n, int m): n(n), m(m) {
        fen.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fen[i].resize(m + 1);
        }
    } 

    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                fen[i][j] = max(fen[i][j], val);
            }
        }
    }

    int get(int x, int y) {
        int res = 0;
        for (int i = x; i; i -= i & -i) {
            for (int j = y; j; j -= j & -j) {
                res = max(res, fen[i][j]);
            }
        }
        return res;
    }
};