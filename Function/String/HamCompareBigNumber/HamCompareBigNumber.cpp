#include <bits/stdc++.h>

using namespace std;

//so sánh 2 số có hơn 18 chữ số
// return 0 if a <= b, return 1 if a > b
bool compareBigNumber(string a, string b) {
    int la = a.length();
    int lb = b.length();
    if (la > lb) {
        return 1;
    }
    else if (la < lb) {
        return 0;
    }
    else {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] > b[i]) {
                return 1;
            }
            if (a[i] < b[i]) {
                return 0;
            }
        }
    }
    return 0;
}
