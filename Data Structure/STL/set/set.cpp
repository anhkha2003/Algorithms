#include <bits/stdc++.h>
using namespace std;

struct CMP {
    bool operator() (int a, int b) {
        return a > b;
    }
}
// s: sắp xếp giảm dần
set<long long, greater<long long>> s;
set<long long, CMP> s;

multiset<long long> s: 
// các số có thể trùng nhau
// giống set

set <long long> s;
// các số sắp xếp theo thứ tự tăng dần
// các số chỉ xuất hiện 1 lần

int main() {
    s.insert(4);
    s.insert(2);
    
    // for xuôi
    for (auto i: s) {
        cout << i << " ";
    }
    cout << endl;
    // for ngược
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << " ";
    }
    
    //set
    s.erase(4); 
    // multiset
    s.erase(4); // xóa hết tất cả k
    s.erase(s.find(4)); // chỉ xóa 1 giá trị k
    // s.find(x): O(log)
    auto it = s.find(x);
    if (it != s.end()) s.erase(x);

    s.erase(s.begin()); // xóa số nhỏ nhất

    cout << s.size() << endl;
    cout << s.count(4) << endl; // ktr s có chứa số x không

    long long minVal = *s.begin(); // số nhỏ nhất
    cout << minVal << endl;
    long long maxVal = *(--s.end()); // số lớn nhất
                     = *s.rbegin();
    cout << maxVal << endl;

    cout << *(++s.begin()) << endl; // số nhỏ thứ 2
    cout << *(--(--s.end())) << endl; // số lớn thứ 2

    // lấy số nhỏ thứ k: O(k)
    auto it = s.begin();
    for (int i = 1; i < k; i++) it++;
    cout << *it;

    // tìm vị trí i sao cho k >= *i
    s.lower_bound(k);
    int x = *s.lower_bound(k);


    return 0;
}
