// search x

double f(double x) {
    return x * (a - 2 * x) * (b - 2 * x);
}

// find max
double ternarySearch() {
    long double lower = -2e9, upper = 2e9;
    for (int i = 1; i <= 200; i++) {
        // faster, turn only 50
        long double diff = (upper - lower) / (1e3);
        long double mid = (lower + upper) / 2;

        long double x1 = mid - diff;
        long double x2 = mid + diff;

        // double x1 = (lower * 2 + upper) / 3.0;
        // double x2 = (lower + upper * 2) / 3.0;

        if (f(x1) < f(x2)) { // f(x1) > f(x2) if find min
            lower = x1;
        }
        else {
            upper = x2;
        }
    }
    return (lower + upper) / 2;
}

// search x-y

double dist(double x, double y, double ax, double ay) {
    return sqrt((x - ax) * (x - ax) + (y - ay) * (y - ay)); 
}

double f(double x, double y) {
    return dist(x, y, ax, ay) + dist(x, y, bx, by) + dist(x, y, cx, cy);
}

double ternarySearch_Y(double x) {
    double lower = -1e6, upper = 1e6;
    for (int turn = 0; turn <= 100; turn++) {
        double y1 = (lower * 2 + upper) / 3.0;
        double y2 = (lower + upper * 2) / 3.0;
        
        if (f(x, y1) < f(x, y2)) {
            upper = y2;
        }
        else {
            lower = y1;
        }
    }
    return lower;
}

double ternarySearch_X() {
    double lower = -1e6, upper = 1e6;
    for (int turn = 0; turn <= 100; turn++) {
        double x1 = (lower * 2 + upper) / 3.0;
        double x2 = (lower + upper * 2) / 3.0;

        if (f(x1, ternarySearch_Y(x1)) < f(x2, ternarySearch_Y(x2))) {
            upper = x2;
        }
        else {
            lower = x1;
        }
    }
    return lower;
}

// ternary search integer
long long f(long long x) {
    return max(0ll, m - k * x - a1) + max(0ll, x - ak);
}

while (lower < upper) {
    long long mid = (lower + upper) / 2;
    if (f(mid) < f(mid + 1)) { // find min
        upper = mid;
    }
    else lower = mid + 1;
}