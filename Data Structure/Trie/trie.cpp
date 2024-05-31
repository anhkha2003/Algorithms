struct Trie {
    int ID = 1;
    struct Node {
        int size;
        int child[2];

        Node() {
            size = 0;
            child[0] = child[1] = 0;
        }
    };

    vector<Node> node;
    Trie(int n) {
        node.resize(30 * n + 5);
    }

    void insert(int val) {
        int cur = 1;
        for (int i = 29; i >= 0; i--) {
            int bit = (bool) (val & (1 << i));

            node[cur].size++;
            if (node[cur].child[bit] == 0) {
                node[cur].child[bit] = ++ID;
            }
            cur = node[cur].child[bit];
        }
        node[cur].size++;
    }

    long long queryMin(int val) {
        int cur = 1;
        long long res = 0;
        for (int i = 29; i >= 0; i--) {
            int bit = (bool) (val & (1 << i));

            if (node[cur].child[bit] == 0) {
                res += (1 << i);
                cur = node[cur].child[bit ^ 1];
            }
            else { 
                cur = node[cur].child[bit];
            }
        }
        return res;
    }

    long long queryMax(int val) { // max a[i] ^ val
        int cur = 1;
        long long res = 0;
        for (int i = 29; i >= 0; i--) {
            int bit = (bool) (val & (1 << i));
            bit ^= 1;

            if (node[cur].child[bit] == 0) {
                cur = node[cur].child[bit ^ 1];
            }
            else {
                res += (1 << i);
                cur = node[cur].child[bit];
            }
        }
        return res;
    }
};