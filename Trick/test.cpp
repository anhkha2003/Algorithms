#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9;

// overload
struct Point {
    long long x, y;
    bool operator < (const Point& p) {
        return x + y < p.x + p.y;
    }

    Point operator + (const Point& p) {
        return {(x + p.x) % MOD, (y + p.y) % MOD};
    }


    Point operator - (const Point& p) {
        return {(x - p.x), (y - p.y)};
    }

    Point operator * (long long a) {
        return {a * x % MOD, a * y % MOD};
    } 

    friend Point operator * (long long a, const Point& p) {
        return {a * p.x % MOD, a * p.y % MOD};
    }

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    Point a = {1, 2};
    Point b = {5, 3};
    Point d = {3, 7};

    a.print();
    return 0;
}