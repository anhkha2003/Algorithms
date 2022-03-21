#include<bits/stdc++.h>
using namespace std;

vector<int> palinOdd, palinEven;

// i is index center, p[i] is length on left and right
vector<int> manacherOdd(string &t) {
    string s = t;
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = -1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string &s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    t += '#';
    auto res = manacherOdd(t);

    for (int i = 0; i < res.size(); i++) {
        if (i % 2 == 0) {
            palinEven.push_back((res[i] - 1) / 2);
        }
        else {
            palinOdd.push_back(res[i] / 2);
        }
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;

    manacher(s);

    int res = 0;
    int l = 0, r = 0;

    for (int i = 0; i < palinOdd.size(); i++) {
        if (res < 2 * palinOdd[i] - 1) {
            res = 2 * palinOdd[i] - 1;
            l = i + 1 - palinOdd[i] + 1;
            r = i + 1 + palinOdd[i] - 1;
        } 
    }

    for (int i = 0; i < palinEven.size(); i++) {
        if (res < 2 * palinEven[i]) {
            res = 2 * palinEven[i];
            l = i + 1 - palinEven[i];
            r = i + 1 + palinEven[i] - 1;
        } 
    }

    for (int i = l; i <= r; i++) {
        cout << s[i - 1];
    }

    return 0;
}