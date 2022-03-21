long long solve(vector<long long>& a, long long r) {
    long long res = r;

    int n = a.size();
    for (int bit = 0; bit < (1 << n); bit++) {
        int cnt = 0;
        long long lcm = 1;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) { 
                // do sth {
                //   ....
                // }

                cnt++;
            }
        }

        // cnt = cntBit

        if (cnt % 2 == 1) {
            res += r / lcm;
        }
        else {
            res -= r / lcm;
        }
    }

    return res;
}