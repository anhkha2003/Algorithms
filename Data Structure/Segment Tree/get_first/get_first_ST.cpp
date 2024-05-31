// Segment Tree Walk for lazy
// store min if find first idx a[idx] <= x
// store max if find first idx a[idx] >= x

int getFirst(int id, int l, int r, int u, int v, long long x) {
    // first idx that a[idx] >= x in [u, v]
    if (r < u || v < l || u > v) return -1;
    if (st[id].max < x) return -1;
    if (l == r) return l;

    down(id, l, r);
    int mid = (l + r) / 2;

    int idx = getFirst(id * 2, l, mid, u, v, x);
    if (idx != -1) return idx;
    return getFirst(id * 2 + 1, mid + 1, r, u, v, x);
}