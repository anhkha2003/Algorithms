// Alien Trick
// Application of Lagrange multiplier
// dp[n][k]: min/max value of splitting n numbers into k consecutive groups
// dp[i][k] = dp[j][k - 1] + cost(j + 1, i)
// find min/max of dp[n][k] + C * (# groups - k)
// dp[n][k] = f[n] - k * C
// f[i] = f[j] + cost(j + 1, i) + C
// binary search C to find min/max dp[n][k] (binary search based on extreme)
// before binary search, print all solve1D(n, k, c) with all Cs to see whether function has max/min extreme

long long cost(int i, int j, long long c) { // i -> j
    return (sum[j] - sum[i]) * (j - i - 1) + c;
}

long long solve1D(int n, int k, long long c) {
    // f[i] = min(f[j] + cost(j + 1, i) + C)
    vector<long long> dp(n + 1);

    // solve dp without constraint on number of groups k
    // solve by 1D Optimization / Convex Hull Trick

    return dp[n] - k * c;
}

long long solve(int n, int k) {
    // dp[i][k] = min(dp[j][k - 1] + cost(j + 1, i))
    long long lower = -1e15, upper = 1e15; // careful overflow
    while (lower < upper) {
        long long mid = lower + (upper - lower) / 2;
        if (solve1D(n, k, mid) <= solve1D(n, k, mid + 1)) {
            lower = mid + 1;
        }
        else upper = mid;
    }

    return solve1D(n, k, lower);
}
