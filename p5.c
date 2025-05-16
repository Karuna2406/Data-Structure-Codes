#include <stdio.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int arr[n];
    int position[n + 1];  

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        position[arr[i]] = i; 
    }

    while (q--) {
        int L, R;
        scanf("%d %d", &L, &R);
        L--, R--; 

        for (int i = n; i >= 1; i--) {
            if (position[i] < L || position[i] > R) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}
