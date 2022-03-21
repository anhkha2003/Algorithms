// For lấy tập con của bit
// ĐPT: O(3^n)

for (int bit = 0; bit < (1 << n); bit++) {
    for (int i = bit; i; i = (i - 1) & bit) {
        // do sth

    }
}