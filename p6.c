#include <stdio.h>
int largest(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]>max)
        {
            max= arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int findlargest = largest(arr, n);
    printf("Largest element: %d\n", findlargest);

    return 0;
}
