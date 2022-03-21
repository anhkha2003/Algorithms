int a[1005][1005];
long long f[1005][1005]; // (1, 1) -> (x, y)

// update bảng (x1, y1) -> (x2, y2)
void update(int x1, int y1, int x2, int y2, int p) {
    a[x1][y1] += p;
    a[x1][y2 + 1] -= p;
    a[x2 + 1][y1] -= p;
    a[x2 + 1][y2 + 1] += p;
    return;
}

// calc (1, 1) -> (x, y) and after update
f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];

// calc (x1, y1) -> (x2, y2)
long long calc(int x1, int y1, int x2, int y2) {
    return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
}

