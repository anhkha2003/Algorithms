#include <bits/stdc++.h>
using namespace std;

int a[500005];
int cnt[500005];
int res[500005];

struct Query {
    int l, r, ind;
};

const int S = 700; // (n / sqrt(q))
bool cmp(const Query &a, const Query &b) {
    if (a.l / S == b.l / S) {
        if ((a.l / S) % 2 == 0) return a.r < b.r;
        else return a.r > b.r;
    }
    return a.l / S < b.l / S;
}

int val = 0;
void add(int x) {
    cnt[x]++;
    if (cnt[x] == 2) val++;
    if (cnt[x] == 3) val--;  
}

void del(int x) {
    cnt[x]--;
    if (cnt[x] == 2) val++;
    if (cnt[x] == 1) val--;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<Query> queries;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }

    sort(queries.begin(), queries.end(), cmp);

    int l = 1;
    int r = 0;
    for (auto qr: queries) {
        while (r < qr.r) {
            r++;
            add(a[r]);
        }
        while (l < qr.l) {
            del(a[l]);
            l++;
        }
        while (l > qr.l) {
            l--;
            add(a[l]);
        }
        while (r > qr.r) {
            del(a[r]);
            r--;
        }
        res[qr.ind] = val;
    }

    for (int i = 1; i <= q; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}