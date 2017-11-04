void sink(int a[], int m, int n) {
    int parent = m;
    int child = m * 2 + 1;
    while (child <= n) {
        if (child + 1 <= n && a[child] < a[child + 1]) {
            child++;
        }
        if (a[parent] < a[child]) {
            int t = a[parent];
            a[parent] = a[child];
            a[child] = t;
            parent = child;
            child = 2 * child + 1;
        } else {
            return;
        }
    }
}

int heapSort(int a[], int len) {
    int i;
    for (i = len / 2 - 1; i >= 0; i--) {
        sink(a, i, len - 1);
    }
    for (i = len - 1; i > 0; i--) {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        sink(a, 0, i - 1);
    }
}

int main() {
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    heapSort(a, 10);
    return 0;
}
