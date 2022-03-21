double lower = -2e9, upper = 2e9;

for (int z = 1; z <= 50; z++) {
    double mid = (lower + upper) / 2;
    if (solve(mid)) lower = mid;
    else upper = mid;
}

cout << fixed << setprecision(4) << lower;