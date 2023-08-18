#include <bits/stdc++.h>
using namespace std;

int a[300005];
int val[3000005];
int cnt[3000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val[a[i]]++;
    }

    // cnt[i] là số số có ước là i
    for (int i = 1; i <= 3000000; i++) {
        for (int j = 1; j * i <= 3000000; j++) {
            cnt[i] += val[i * j];
        }
    }


    return 0;
}