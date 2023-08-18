#include <bits/stdc++.h>
using namespace std;

int p[500005][35]; // p[a][i]: đỉnh đi tới sau 2^i bước, xuất phát từ a

//p[i][0] = parent of i
//p[i][j] = p[p[i][j - 1]][j - 1];

// for i trước for a
void initJumps() {
    for (int j = 1; j <= logn; j++) {
        for (int i = 1; i <= n; i++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }    
}

int kthNode(int n, int k) {
    int node = n;
    for (int i = 30; i >= 0; i--) {
        if (p[node][i] != -1 && (1 << i) <= k) {
            node = p[node][i];
            k -= (1 << i);
        }
    }
    return node;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        p[i][0] = x;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 30; j++) {
            p[i][j] = -1;
        }
    }

    for (int i = 1; i <= q; i++) {
        int x, k;
        cin >> x >> k;

        int res = kthNode(x, k);
        cout << res << "\n";
    }

    return 0;
}