// pass by value: create a copy inside the function (Ex: foo(int s))
// pass by reference: use the original one (Ex: foo(int &s))

#include <bits/stdc++.h>

using namespace std;

void foo(int &a) {
    a += 5;
    //cout << a << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int s = 123;
    foo(s);
    cout << s;
    return 0;
}

