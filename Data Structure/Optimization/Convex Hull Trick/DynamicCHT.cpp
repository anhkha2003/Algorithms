// dp[i] = min(dp[j] + b[j] * a[i] + C)
// line: y = x * a + b
//       dp[i] = a[i] * b[j] + dp[j] + C
// add(a, b) => add(b[i], dp[i]) (after calc dp[i])
// y = query(x) => dp[i] = query(a[i]) + C

// Example: 
// dp[i] = dp[j] + (h[i] - h[j])^2 + C
//       = dp[j] + h[j]^2 - 2 * h[j] * h[i] + h[i]^2 + C
// add(-2 * h[i], dp[i] + h[i]^2)
// dp[i] = query(h[i]) + h[i]^2 + C

// add: O(log)
// query: O(log)

// return max
// add (-a, -b), return -query if need min

struct Line {
    mutable long long k, m, p;
    bool operator < (const Line& o) const {return k < o.k;}
    bool operator < (long long x) const {return p < x;}
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use INF = 1/.0, div(a,b) = a/b)
    const long long INF = LLONG_MAX;
    
    long long div(long long a, long long b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); 
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) { 
            x->p = INF; 
            return false; 
        }

        if (x->k == y->k) { 
            x->p = x->m > y->m ? INF : -INF;
        }
        else {
            x->p = div(y->m - x->m, x->k - y->k);
        }
        return x->p >= y->p;
    }

    void add(long long k, long long m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) 
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    
    long long query(long long x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};