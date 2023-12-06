// dp[i][k] = min(dp[j][k - 1] + C(j + 1, i))
// if find max, negate everything

// C(l, r): a convex function a[l] -> a[r] (exp: a[l] + ... + a[r])
// opt[i][k] <= opt[i + 1][k]

// complexity: O(n * k * log(n))

struct DivideAndConquer {
    const long long INF = 1e18;

    int n, k;
    vector<vector<long long>> dp;
    vector<long long> sum;

    DivideAndConquer(int n, int k): n(n), k(k) {
        dp.assign(n + 1, vector<long long>(k + 1));
        sum.resize(n + 1);
    }

    long long cost(int i, int j) {
        if (i > j) return 0;
        return (sum[j] - sum[i - 1]) * (j - i);
    }

    void solve(int k, int l, int r, int optL, int optR) {
        if (l > r) return;
        
        int mid = (l + r) / 2;
        dp[mid][k] = INF;
        
        int optM = 0;
        for (int i = optL; i <= min(optR, mid); i++) {
            long long new_cost = dp[i][k - 1] + cost(i + 1, mid);
            if (dp[mid][k] > new_cost) {
                dp[mid][k] = new_cost;
                optM = i;
            }
        }
        
        solve(k, l, mid - 1, optL, optM);
        solve(k, mid + 1, r, optM, optR);
    }

    void setup() {
        for (int i = 1; i <= n; i++) dp[i][1] = cost(1, i);

        for (int i = 2; i <= k; i++) solve(i, 1, n, 0, n);
    }

    long long getDP(int n, int k) {
        return dp[n][k];
    }
};
