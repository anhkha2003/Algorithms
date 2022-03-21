#include <bits/stdc++.h>

using namespace std;

map<long long, long long> a;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        //cin >> a[i];
        a[i] = i;
    }
    a[2] = 10;
    cout << a[2] << " ";
    cout << a[n - 1] << " ";
    cout << a.count(10);
    return 0;
}
// a.count(n) == 1 if a[n] có xuất hiện
// a.count(n) == 0 if a[n] chưa xuất hiện

