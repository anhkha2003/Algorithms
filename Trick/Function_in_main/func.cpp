#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    auto solve = [&] (int x) {
        x++;
        return x;
    };

    cout << solve(5);
    
    return 0;
}