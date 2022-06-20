#include<bits/stdc++.h>
using namespace std;

int a[(1 << 20) + 5];
int f[(1 << 20) + 5];
// f[mask] = sum of a[i] such that i is subset of mask

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    // dp SOS
    for (int mask = 0; mask < (1 << 20); mask++) {
        f[mask] = a[mask];
    }
    
    for (int i = 0; i < 20; i++) {
        for (int mask = 0; mask < (1 << 20); mask++) {
            if (mask & (1 << i)) {
                f[mask] += f[mask ^ (1 << i)];
            }
        }
    }
    
    return 0;
}