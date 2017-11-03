#include <stdlib.h>
#include <time.h>

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
    return 0;
}
