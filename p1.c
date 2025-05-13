#include <stdio.h>
#include <stdbool.h>

#define MAX 128  


void insertionSort(int *arr, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= l && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


bool areEqual(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        if (n > MAX) {
            printf("Array size too large for memory limit!\n");
            continue;
        }

        int A[MAX], B[MAX];  
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        for (int i = 0; i < n; i++) scanf("%d", &B[i]);

        int left = 0, right = n - 1;

        while (left < n && A[left] == B[left]) left++;

        /
        while (right >= 0 && A[right] == B[right]) right--;

        if (left > right) {
            printf("0\n");  
            continue;
        }

        
        insertionSort(A, left, right);
        insertionSort(B, left, right);

        if (areEqual(A, B, n)) {
            printf("%d\n", right - left + 1);
        } else {
            printf("%d\n", n);
        }
    }

    return 0;
}
