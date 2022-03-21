#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

// n phương trình, m biến
// 0: vô nghiệm, 1: 1 nghiệm, INF: vô số nghiệm
int gauss (vector<vector<double>> a, vector<double> &ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < EPS)
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row) {
                long double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i) {
        long double sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i = 0; i < m; ++i)
        if (where[i] == -1) {
            return INF;
        }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vector<vector<double>> a;
    vector<double> ans;

    vector<double> equation;
    equation.push_back(3); equation.push_back(2);
    equation.push_back(4); equation.push_back(11);

    // 3x + 2y + 4z = 11
    a.push_back(equation);

    equation.clear();
    equation.push_back(6); equation.push_back(-3);
    equation.push_back(7); equation.push_back(7);

    // 6x - 3y + 7z = 7
    a.push_back(equation);

    gauss(a, ans);

    for (auto i: ans) {
        cout << i << ' ';
    }

    return 0;
}