// dp[i][j] = min(dp[i][k] + dp[k + 1][j] + C(i, j)) 
// i <= k < j

// opt[i][j - 1] <= opt[i][j] <= opt[i + 1][j]
// complexity: O(n^2)

int opt[5005][5005];
long long dp[5005][5005];

long long cost(int i, int j) {
    if (i > j) return 0;
    return s[j] - s[i - 1];
}

void solve(int n) {
    for (int i = 1; i <= n; i++) {
        opt[i][i] = i;
        dp[i][i] = 0; // initialize dp[i][i] according to the problem
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = 1e18;
            long long c = cost(i, j);
            for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {
                if (dp[i][j] >= dp[i][k] + dp[k + 1][j] + c) {
                    opt[i][j] = k;
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + c;
                }
            }
        }
    }
}