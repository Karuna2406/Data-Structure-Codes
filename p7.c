#include <studio.h>
int getSecondLargest(int arr[], int n) {
    int first=-1;
    int second=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>first)
        {
            second=first;
            first=arr[i];
        }
        else if(arr[i]<first && arr[i]>second)
        {
            second=arr[i];
        }
    }
    return second;
}
int main() {
    int n;
    scanf("%d", &n); ay

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]); 

    int result = getSecondLargest(arr, n);
    printf("%d\n", result); 
    return 0;
}
