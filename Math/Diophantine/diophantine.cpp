#include <bits/stdc++.h>
using namespace std;

// Nghiệm: x, y
// (x, y) && (x + p, y - q): p/q = b/a (pstg)
// Họ nghiệm: (x + kp, y - kq)

struct Diophantine {
    long long mulmod(long long a, long long b, long long c) {
        long long sign = 1;
        if (a < 0) {
            a = -a;
            sign = -sign;
        }
        if (b < 0) {
            b = -b;
            sign = -sign;
        }
        a %= c;
        b %= c;
        long long res = 0;
        while (b > 0) {
            if (b & 1) {
                res = (res + a) % c;
            }
            a = (a + a) % c;
            b >>= 1;
        }
        if (sign == -1) {
            res = (-res) % c;
        }
        return res;
    }

    template<typename T>
    T extgcd(T a, T b, T &x, T &y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
        T p = b / a;
        T g = extgcd(b - p * a, a, y, x);
        x -= p * y;
        return g;
    }

    template<typename T>
    bool diophantine(T a, T b, T c, T &x, T &y, T &g) {
        if (a == 0 && b == 0) {
            if (c == 0) {
                x = y = g = 0;
                return true;
            }
            return false;
        }
        if (a == 0) {
            if (c % b == 0) {
                x = 0;
                y = c / b;
                g = abs(b);
                return true;
            }
            return false;
        }
        if (b == 0) {
            if (c % a == 0) {
                x = c / a;
                y = 0;
                g = abs(a);
                return true;
            }
            return false;
        }
        g = extgcd(a, b, x, y);
        if (c % g != 0) {
            return false;
        }
        T dx = c / a;
        c -= dx * a;
        T dy = c / b;
        c -= dy * b;
        x = dx + mulmod(x, c / g, b);
        y = dy + mulmod(y, c / g, a);
        g = abs(g);
        return true;
    }
};

// a * k >= l 
long long calcBDT(long long l, long long a) {
    if (a > 0) {
        if (l > 0) l = (l - 1) / a + 1;
        else l = l / a;
    } 
    else {
        if (l >= 0) {
            if (l % a == 0) l /= a;
            else l = l / a - 1;
        }
        else l /= a;
    }
    return l;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long a, b, c;
    cin >> a >> b >> c;

    Diophantine diophantine;

    long long x, y;
    
    long long g = diophantine.extgcd(a, b, x, y);

    cout << diophantine.diophantine(a, b, c, x, y, g) << endl;
    cout << x << " " << y << " " << endl;
    return 0;
}