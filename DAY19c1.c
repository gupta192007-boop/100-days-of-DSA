/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = INT_MAX;
    int x = 0, y = 0;

    
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", x, y);

    return 0;
}
