const long long MOD = 1e18;

long long mul(long long a, long long b) {
    if (b == 0) return 0;
    long long c = mul(a, b / 2);
    if (b % 2 == 0) return (c + c) % MOD;  
    else return ((c + c) % MOD + a) % MOD;
} 
