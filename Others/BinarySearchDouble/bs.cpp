// binary search double
double lower = -2e9, upper = 2e9;
for (int z = 1; z <= 50; z++) {
    double mid = (lower + upper) / 2;
    if (solve(mid)) lower = mid;
    else upper = mid;
}
cout << fixed << setprecision(4) << lower;

// binary search negative: lower + (upper - lower) / 2
long long lower = -5e9, upper = 5e9;
while (lower < upper) {
    long long mid = lower + (upper - lower) / 2;
    if (solve(mid)) {
        lower = mid + 1;
    }
    else upper = mid;
}