#include <stdio.h>
#include <stdbool.h> // For using bool type

bool arraySortedOrNot(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false; // Found a decreasing pair
    }
    return true; // All elements are in non-decreasing order
}

int main() {
    int n;
    scanf("%d", &n); // Input array size

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Input array elements
    }

    if (arraySortedOrNot(arr, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
