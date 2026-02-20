/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefix = 0;
    long long count = 0;

    
    int size = 2 * MAX + 1;
    int *freq = calloc(size, sizeof(int));

    
    int offset = MAX;

    freq[offset] = 1;   

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(freq[prefix + offset] > 0)
            count += freq[prefix + offset];

        freq[prefix + offset]++;
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}