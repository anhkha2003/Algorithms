#include <bits/stdc++.h>
using namespace std;

int a[100005];

// ở ngoài: định nghĩa kết quả phép tính
// ở trong: kiểu biến thực hiện phép tính
vector<int> operator * (int c, vector<int> a)

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 1; i <= 10; i++) {
        a[i] = i;
    }

    // copy từ mảng qua vector
    vector<int> v(a + 1, a + 10 + 1);

    for (auto i: v) cout << i << " ";
    cout << endl;

    // tạo vector có n số x
    vector<int> s(5, -10);  
    for (auto i: s) cout << i << " ";

    // insert số a vào vị trí k
    q.insert(q.begin() + k, a)

    // unique elements in vector
    auto it = unique(a.begin(), a.end());
    a.resize(distance(a.begin(), it));

    return 0;
}