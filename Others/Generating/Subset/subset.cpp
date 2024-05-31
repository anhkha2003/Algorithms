// Generate all subsets of a bit
// Time: O(3^n)

for (int bit = 0; bit < (1 << n); bit++) {
    for (int i = bit; i; i = (i - 1) & bit) {
        // do sth

    }
}