#include <bits/stdc++.h>
using namespace std;

struct Crt {
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

    long long lcm(long long a, long long b) {
        return a / (__gcd(a, b)) * b;
    }

    bool noSolution = false;
    // x = a1 + u * m1 = a2 + v * m2
    // u * m1 - v * m2 = a2 - a1    
    // m1 < m2
    long long crt2(long long a1, long long m1, long long a2, long long m2) {
        long long x, y;
        long long g = extgcd(m1, -m2, x, y);
        long long m = lcm(m1, m2);

        long long c = a2 - a1;
        if (c % abs(g) != 0) noSolution = true;

        diophantine(m1, -m2, c, x, y, g);
    
        x = a1 + m1 * x;
        x %= m;
        return x;
    }

    long long crt(vector<long long> &a, vector<long long> &m) {
        while (a.size() >= 2) {
            long long a1 = a.back(); a.pop_back();
            long long a2 = a.back(); a.pop_back();

            long long m1 = m.back(); m.pop_back();
            long long m2 = m.back(); m.pop_back();

            long long a0 = crt2(a1, m1, a2, m2);
            long long m0 = lcm(m1, m2);

            if (noSolution == true) return -1;
            
            a.push_back(a0);
            m.push_back(m0);
        }
        return (a[0] % m[0] + m[0]) % m[0];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> m(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> m[i];
    }

    Crt crt;
    long long res = crt.crt(a, m);
    cout << res;

    return 0;
}