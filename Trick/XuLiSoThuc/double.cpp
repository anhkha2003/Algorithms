#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-8;
const double PI = acos(-1);

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // a == b <=> abs(a - b) < EPS
    // a != b <=> abs(a - b) > EPS
    // a > b  <=> a > b + EPS

    double x;
    cin >> x;

    a = round(x * 100);
    // a: integer

    a = floor(x); // round down
    // the largest integer smaller than or equal to x

    a = ceil(x); // round up
    // the smallest integer greater than or equal to x

    a *= 1.0; // a /= 1.0
    // a becomes double

    // căn bậc 3
    a = pow(val, 1.0 / 3);

    int a; // degree
    double rad = PI * 2 * a / 360; // radian

    cout << fixed << setprecision(9) << res;

    // use when input double is large and when TLE
    string s, t;
    cin >> s >> t;
    long double x = stold(s);
    double y = stod(t);

    return 0;
}
