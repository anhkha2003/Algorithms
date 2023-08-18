#include <stdio.h>

// way to always O(nlog):
// random: swap (a[l], a[rand(l, r)])
// shuffle array before sort

int partition(int a[], int l, int r) {
    int ran = rand() % (r - l + 1) + l;
    int val = a[l];
    a[l] = a[ran];
    a[ran] = val;

    int pivot = a[l];
    int j = r;

    for (int i = r; i > l; i--){
        if (a[i] >= pivot){
            int c = a[i];
            a[i] = a[j];
            a[j] = c;

            j--;
        }
    }

    int c = a[l];
    a[l] = a[j];
    a[j] = c;

    return j;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int mid = partition(a, l, r);

        quickSort(a, l, mid - 1);
        quickSort(a, mid + 1, r);
    }
}