#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int sub[200005];
int c[200005];
set<int> s[200005];
int res[200005];

// if use IndexTree or sth else
namespace std {
    void swap(IndexTree &a, IndexTree &b) { a.swap(b); }
}

void dfs(int n, int par) {
    sub[n] = 1; 
    int maxSub = 0, bigChild = 0;
    for (auto i: adj[n]) {
        if (i == par) continue;

        dfs(i, n);

        sub[n] += sub[i];

        if (maxSub < sub[i]) {
            maxSub = sub[i];
            bigChild = i;
        }
    }

    if (bigChild) {
        swap(s[n], s[bigChild]);
        // std::swap(s[n], s[bigChild])

        for (auto i: adj[n]) {
            if (i == par || i == bigChild) continue;

            for (auto j: s[i]) {
                s[n].insert(j);
            }
        }
    }

    s[n].insert(c[n]);

    res[n] = s[n].size();
}
