#include <bits/stdc++.h>

using namespace std;

// stringToNumber(123) = 123;
long long stringToNumber(string s) {
    long long res = 0, n = 0;
    long long l = s.length();
    long long base = 1;
    for (int i = l - 1; i >= 0; i--) {
        n = s[i] - '0';
        n *= base;
        base *= 10;
        res += n;
        //cout << n << " " << res << endl;
    }
    return res;
}
