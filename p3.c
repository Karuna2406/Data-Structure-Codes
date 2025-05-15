#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
long long solve (int n, int* nums) {
    int freq[100] = {0};
    for(int i=0;i<n;i++)
    {
        int sum = digitSum(nums[i]);
        freq[sum]++;
    }
    long long totalPairs =0;
    for(int i=0;i<100;i++)
    {
        if(freq[i]>=2)
        {
            totalPairs+=(long long)freq[i]*(freq[i]-1)/2;
        }
    }
    return totalPairs;
}

int main() {
    int n;
    scanf("%d", &n);
    int i_nums;
    int *nums = (int *)malloc(sizeof(int)*(n));
    for(i_nums = 0; i_nums < n; i_nums++)
    	scanf("%d", &nums[i_nums]);

    long long out_ = solve(n, nums);
    printf("%lld", out_);
}
