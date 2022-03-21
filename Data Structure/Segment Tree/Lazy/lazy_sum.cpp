struct SegmentTree {
    struct Node {
        long long sum = 0;
        long long lazy = 0; // -1 nếu update là phép gán
    };

    vector<Node> st;
    int n;
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
        if (l == r || !st[id].lazy) return;

        long long val = st[id].lazy;

        int mid = (l + r) / 2;
        st[id * 2].sum += val * (mid - l + 1);
        st[id * 2 + 1].sum += val * (r - mid);

        st[id * 2].lazy += val;
        st[id * 2 + 1].lazy += val;

        st[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (r < u || v < l) return;
        if (u <= l && r <= v) {
            st[id].sum += val * 1ll * (r - l + 1);
            st[id].lazy += val;
            return;
        } 

        down(id, l, r);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
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