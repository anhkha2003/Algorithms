bitset<N> trace;
vector<int> primes;

void sieve(int n) {
    for (int i = 3; i * i < n; i += 2) {
        if (trace[i / 2] == 0) {
            for (int j = i * i; j < n; j += i * 2) {
                trace[j / 2] = 1;
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i < n; i += 2) {
        if (trace[i / 2] == 0) {
            primes.push_back(i);
        }
    }
}