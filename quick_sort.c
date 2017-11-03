#include <stdlib.h>
#include <time.h>

int partition(int a[], int lo, int hi){
    int i = lo;
    int j = hi + 1;
    while (1) {
        while (a[++i] < a[lo]) {
            if (i == hi) {
                break;
            }
        }
        while (a[--j] > a[lo]) {
            if (j == lo) {
                break;
            }
        }
        if (i >= j) {
            break;
        }

        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    int t = a[lo];
    a[lo] = a[j];
    a[j] = t;
    return j;
}

void quickSort(int a[], int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int j = partition(a, lo, hi);
    quickSort(a, lo, j - 1);
    quickSort(a, j + 1, hi);
}

void shuffle(int a[], int len) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; i++) {
        int r = rand()%(i + 1);
        int t = a[r];
        a[r] = a[i];
        a[i] = t;
    }
}

int main() {
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    shuffle(a, 10);
    quickSort(a, 0, 9);
    return 0;
}
