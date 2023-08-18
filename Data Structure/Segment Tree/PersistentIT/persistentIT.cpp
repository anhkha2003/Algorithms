#include<bits/stdc++.h>
using namespace std;

// Persistent SegmentTree

// vector<int> segTree(q + 1)
// update segTree[1] instead of build(a)
// create ST (i+1)-th: segTree[i + 1] = pst.update(segTree[i], 1, n, i, x)
// update ST i-th: segTree[i] = pst.update(segTree[i], 1, n, i, x)
// query: pst.query(segTree[i], 1, n, i)

struct PersistentSegmentTree {
    struct Node {
        long long sum = 0; 
        int left = 0, right = 0;   
    }; 

    vector<Node> st = {Node()};
    int ID = 0;

    // in case MLE
    // PersistentSegmentTree(int n): n(n) {
    //     st.resize(number of update * (__lg(n) + 2));
    // }

    void merge(Node& a, Node& b, Node& c) {
        a.sum = b.sum + c.sum;
    }

    int update(int id, int l, int r, int u, int val) {
        int newID = ++ID;
        st.push_back(Node());

        if (l == r) {
            st[newID].sum = val;
            return newID;
        }

        int mid = (l + r) / 2;

        if (u <= mid) {
            st[newID].right = st[id].right;
            st[newID].left = update(st[id].left, l, mid, u, val);
        }
        else { 
            st[newID].left = st[id].left;
            st[newID].right = update(st[id].right, mid + 1, r, u, val); 
        }

        merge(st[newID], st[st[newID].left], st[st[newID].right]);
        return newID;
    }

    Node query(int id, int l, int r, int u, int v) {
        if (v < l || r < u || !id) return Node();
        if (u <= l && r <= v) {
            return st[id];
        }
        int mid = (l + r) / 2;
        auto a = query(st[id].left, l, mid, u, v);
        auto b = query(st[id].right, mid + 1, r, u, v);
        Node res;
        merge(res, a, b);
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vector<int> segTree(100);

    PersistentSegmentTree pst(10);

    segTree[1] = pst.update(segTree[0], 1, 10, 3, 5);
    segTree[2] = pst.update(segTree[1], 1, 10, 6, 10);
    segTree[3] = pst.update(segTree[0], 1, 10, 1, 2);

    cout << pst.query(segTree[3], 1, 10, 1, 10).max;

    return 0;
}