#include<bits/stdc++.h>
using namespace std;

int c[1000005];
vector<int> adj[1000005];
int sub[1000005];

vector<int> vec[1000005];
int cnt[3000005], res[1000005];
int val = 0;

void calcSub(int n, int par) {
    sub[n] = 1;
    for (auto i: adj[n]) {
        if (i == par) continue;
        calcSub(i, n);
        sub[n] += sub[i];
    }
}

void dfs(int n, int par, bool big) {
    int bigChild = 0;
    for (auto i: adj[n]) {
        if (i == par) continue;

        if (sub[bigChild] < sub[i]) {
            bigChild = i;
        }
    }

    for (auto i: adj[n]) {
        if (i == par || i == bigChild) continue;
        dfs(i, n, 0);
    }

    if (bigChild) {
        dfs(bigChild, n, 1);
        swap(vec[n], vec[bigChild]);
    }

    vec[n].push_back(n);
    if (cnt[c[n]] == 0) val++;
    cnt[c[n]]++;

    for (auto i: adj[n]) {
        if (i == par || i == bigChild) continue;

        for (auto j: vec[i]) {
            if (cnt[c[j]] == 0) val++;
            cnt[c[j]]++;
            vec[n].push_back(j);
        } 
    }

    res[n] = val;

    if (big == 0) {
        for (auto i: vec[n]) {
            cnt[c[i]]--;
            if (cnt[c[i]] == 0) val--;
        }
    }
}
