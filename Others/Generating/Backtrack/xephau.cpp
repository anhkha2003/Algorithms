#include <bits/stdc++.h>
using namespace std;

int n;
int a[15][15];

bool isSafe(int row, int col) {
    for (int i = 1; i <= row; i++) {
        if (a[i][col]) return false;
    }

    for (int i = row, j = col; i >= 1 && j >= 1; i--, j--) {
        if (a[i][j]) return false;
    }

    for (int i = row, j = col; i >= 1 && j <= 8; i--, j++) {
        if (a[i][j]) return false;
    }

    return true;
} 

bool solve(int row) {
    if (row > n) return true;

    for (int i = 1; i <= n; i++) {
        if (isSafe(row, i)) {
            a[row][i] = 1;

            if (solve(row + 1)) return true;

            a[row][i] = 0;
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    if (solve(1)) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << "\n";
        }
    }
    else {
        cout << "NO";
    }

    return 0;
}