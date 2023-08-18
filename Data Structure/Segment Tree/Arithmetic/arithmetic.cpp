// a[l] += 1, a[l + 1] += 2, ...
// a[i] += i - (l - 1)
// a[i] += b[i] * i + c[i]
 
long long calc(long long l, long long r) {
    // l + ... + r
    return (r - l + 1) * (r + l) / 2ll;
}
 
struct SegmentTree {
    struct Node {
        long long sum = 0;
        long long lazyB = 0;
        long long lazyC = 0;
    };
 
    int n;
    vector<Node> st;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }
 
    void merge(Node& a, Node& b, Node& c) {
        a.sum = b.sum + c.sum;
    }
 
    void build(vector<int> &a, int id, int l, int r) {
        if (l == r) {
            st[id].sum = a[l];
            return;
        }
 
        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }
 
    void down(int id, int l, int r) {
        long long lzB = st[id].lazyB;
        long long lzC = st[id].lazyC;
 
        if (l == r || (!lzB && !lzC)) return;
 
        int mid = (l + r) / 2;
        st[id * 2].sum += lzB * calc(l, mid) + lzC * (mid - l + 1);
        st[id * 2 + 1].sum += lzB * calc(mid + 1, r) + lzC * (r - mid);
    
        st[id * 2].lazyB += lzB;
        st[id * 2 + 1].lazyB += lzB;
 
        st[id * 2].lazyC += lzC;
        st[id * 2 + 1].lazyC += lzC;
 
        st[id].lazyB = 0;
        st[id].lazyC = 0;
    }
 
    void update(int id, int l, int r, int u, int v) {
        if (r < u || v < l) return;
        if (u <= l && r <= v) {
            st[id].sum += calc(l, r) - (r - l + 1) * 1ll * (u - 1);
            st[id].lazyB += 1;
            st[id].lazyC -= u - 1;
            return;
        } 
 
        down(id, l, r);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v);
        update(id * 2 + 1, mid + 1, r, u, v);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }
 
    Node query(int id, int l, int r, int u, int v) {
        if (r < u || v < l) return Node();
        if (u <= l && r <= v) {
            return st[id];
        }
 
        down(id, l, r);
        int mid = (l + r) / 2;
        auto a = query(id * 2, l, mid, u, v);
        auto b = query(id * 2 + 1, mid + 1, r, u, v);
 
        Node res;
        merge(res, a, b);
        return res;
    }
};