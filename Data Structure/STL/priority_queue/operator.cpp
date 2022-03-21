#include <bits/stdc++.h>
using namespace std;
 
// priority_queue<int> pq;
// tuong duong
// priority_queue<int, vector<int>, less<int>> pq;
// priority_queue<int, vector<int>, greater<int>> pq;
 
 
// uu tien cao nhat = thoi gian dai nhat
// neu thoi gian bang nhau, thi uu tien su kien dien ra truoc
 
struct Object {
    int startTime, endTime;
};
 
struct CMP {
    bool operator() (Object a, Object b) {
        // true if a uu tien thap hon b
        int lenA = a.endTime - a.startTime;
        int lenB = b.endTime - b.startTime; 
        if (lenA == lenB) {
            return a.startTime > b.startTime;
        }
        return lenA < lenB;
    }
};
 
 
// ben trong pq, goi CMP(a, b)
priority_queue<Object, vector<Object>, CMP> pq;
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    pq.push({3, 4});
    pq.push({1, 3});
    pq.push({5, 6});
 
    cout << pq.top().startTime << " " << pq.top().endTime << endl; // {1, 3} -> 1
    pq.pop();
    cout << pq.top().startTime << " " << pq.top().endTime << endl; // {3, 4} -> 3
 
    return 0;
}