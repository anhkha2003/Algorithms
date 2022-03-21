#include <bits/stdc++.h>

using namespace std;

// numberToString(123) = "123"
string numberToString(int n) {
    string res;
    while (n > 0) {
        int unitDigit = n % 10;
        res += (char) (unitDigit + '0');
        n /= 10;
    }
    for (int i = 0; i <= (res.length() - 1) / 2; i++) {
        swap(res[i], res[res.length() - i - 1]);
    }
    //reverse(res.begin(), res.end());
    return res;
}
