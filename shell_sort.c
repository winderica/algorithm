void shellSort(int a[],int len) {
    int h = 0;
    while (h < len / 3) {
        h = 3 * h + 1;
    }
    while (h > 0) {
        for (int i = h; i < len; i++) {
            for (int j = i; j >= h; j -= h) {
                if (a[j] < a[j - h]) {
                    int t = a[j];
                    a[j] = a[j - h];
                    a[j - h] = t;
                } else {
                    break;
                }
            }
        }

        h /= 3;
    }
}

int main() {
    int a[20] = {9, 4, 13, 3, 17, 5, 18, 11, 8, 12, 2, 1, 0, 19, 6, 14, 7, 15, 16, 10};
    shellSort(a, 20);
    return 0;
}
