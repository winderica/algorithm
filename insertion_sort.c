
void insertionSort(int a[],int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j - 1]){
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            } else {
                break;
            }
        }
    }
}

int main() {
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    insertionSort(a, 10);
    return 0;
}
