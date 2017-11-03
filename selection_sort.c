#include <stdio.h>

void selectionSort(int a[],int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++){
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
}

int main() {
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    selectionSort(a, 10);
    return 0;
}
