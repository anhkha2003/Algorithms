#include <bits/stdc++.h>
using namespace std;
 
// 3^n: thêm vector state lưu 0, 1, 2
void go(int idx, int n, vector<int> &a) {
    if (idx == n + 1) {
        for (auto i: a) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    // không thêm idx vào a
    go(idx + 1, n, a);
 
    a.push_back(idx);
    go(idx + 1, n, a);
    a.pop_back();
}
 
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<int> a;
    go(1, 5, a);    
    
    return 0;
}