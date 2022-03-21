#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct Node {
        int max = 0;    
    }; 

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        a.max = max(b.max, c.max);
    }

    void build(vector<int>& a, int id, int l, int r) {
        if (l == r) {
            st[id].max = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, int val) {
        if (l == r) {
            st[id].max = val; // or st[id].sum += val
            return;
        }
        int mid = (l + r) / 2;
        if (u <= mid) update(id * 2, l, mid, u, val);
        else update(id * 2 + 1, mid + 1, r, u, val); 
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    Node query(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return Node();
        if (u <= l && r <= v) {
            return st[id];
        }
        int mid = (l + r) / 2;
        auto a = query(id * 2, l, mid, u, v);
        auto b = query(id * 2 + 1, mid + 1, r, u, v);
        Node res;
        merge(res, a, b);
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegmentTree seg(n);

    seg.build(a, 1, 1, n);

    for (int i = 1; i <= q; i++) {
        int type, x, v;
        cin >> type >> x >> v;

        if (type == 1) {
            seg.update(1, 1, n, x, v);
        }
        else {
            cout << seg.query(1, 1, n, x, v).max << "\n";
        }
    }

    return 0;
}