
void shellSort(int a[],int len) {
    int h = 1;
    while (h < len) {
        h *= 3;
        h += 1;
    }
    while (h > 1) {
        for (int i = h; i < len; i++) {
            for (int j = i; j > h; j--) {
                if (a[j] < a[j - 1]){
                    int t = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = t;
                } else {
                    break;
                }
            }
        }
        h /= 3;
    }
}

int main() {
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    shellSort(a, 10);
    return 0;
}
