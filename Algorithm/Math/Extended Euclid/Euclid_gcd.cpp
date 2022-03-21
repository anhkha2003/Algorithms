// a * x + b * y = gcd
// return gcd

// Nghiệm: x, y
// (x, y) && (x + p, y - q): p/q = b/a (pstg)
// Họ nghiệm: (x + kp, y - kq)

// ax + by = c (c % gcd = 0):
// nghiệm: x * (c / gcd), y * (c / gcd)
long long ext_euclid(long long a, long long b, long long &x, long long &y) {
    long long xx = y = 0;
    long long yy = x = 1;
    while (b){
        long long q = a / b;
        long long t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}