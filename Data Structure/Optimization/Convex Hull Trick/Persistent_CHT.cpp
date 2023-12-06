// Persistent Convex Hull Trick
// use when slopes increasing
// store Convex Hull Trick at n positions
// add lines of the form kx+m, and query maximum values at points x.

// example: dp[i] = s[i] + v[i] * h[i] + dp[n] - v[i] * h[n]
// setup version[1] = cht.add(h[1], -dp[1], version[0])
// version[i] = cht.add(h[i], -dp[i], version[n]);
// dp[i] = -cht.query(v[i], version[n]) + s[i] + v[i] * h[i]

struct Persistent_CHT {
    const int logn = 18; // modify based on constraints
    vector<long long> k, m;
    vector<vector<int>> pars;
    Persistent_CHT() {
        pars.push_back(vector<int>(logn));
        k.push_back(0); m.push_back(0);
    }

    long long query(long long x, int version) {
        auto f = [&](long long x, int version) {
            return x * k[version] + m[version];
        };
        for (int i = logn - 1; i > -1; i--) {
            if (f(x, pars[version][i]) < f(x, pars[pars[version][i]][1])) {
                version = pars[pars[version][i]][1];
            }
        }
        return f(x, version);
    }

    int add(long long k1, long long m1, int version) { // return new version
        for (int i = logn - 1; i > -1; i--) {
            if (pars[version][i] == 0) continue;
            int b = pars[version][i];
            int a = pars[pars[version][i]][1];
            __int128 left = (__int128)(m[b] - m[a]) * (k[a] - k1);
            __int128 right = (__int128)(m1 - m[a]) * (k[a] - k[b]);
            if (left > right) { // use __int128 to handle overflow
                version = pars[pars[version][i]][1];
            }
        }
        int node = k.size();
        k.push_back(k1); m.push_back(m1);
        pars.push_back(vector<int>(logn));
        pars[node][0] = node;
        pars[node][1] = version;
        for(int i = 2; i < logn; i++) {
            pars[node][i] = pars[pars[node][i - 1]][i - 1];
        }
        return node;
    }
};