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
        int root = 1;
        for (int i = 29; i >= 0; i--) {
            int bit = (bool) (val & (1 << i));

            node[root].size++;
            if (node[root].child[bit] == 0) {
                node[root].child[bit] = ++ID;
            }
            root = node[root].child[bit];
        }
        node[root].size++;
    }

    long long queryMin(int val) {
        int root = 1;
        long long res = 0;
        for (int i = 29; i >= 0; i--) {
            int bit = (bool) (val & (1 << i));

            if (node[root].child[bit] == 0) {
                res += (1 << i);
                root = node[root].child[bit ^ 1];
            }
            else { 
                root = node[root].child[bit];
            }
        }
        return res;
    }

    long long queryMax(int val) { // max a[i] ^ val
        int root = 1;
        long long res = 0;
        for (int i = 29; i >= 0; i--) {
            int bit = (bool) (val & (1 << i));
            bit ^= 1;

            if (node[root].child[bit] == 0) {
                root = node[root].child[bit ^ 1];
            }
            else {
                res += (1 << i);
                root = node[root].child[bit];
            }
        }
        return res;
    }
};