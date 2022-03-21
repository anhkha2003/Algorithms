#include<bits/stdc++.h>
using namespace std;

bitset<10> a, b;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    a[0] = 1;
    a[2] = 1;
    b[1] = 1;

    cout << a << endl; // O(N / 64)
    cout << b << endl;
    auto c = a | b;
    cout << c << endl;

    // đếm số bit 1
    cout << a.count();

    //(01 & 11)
    return 0;
}