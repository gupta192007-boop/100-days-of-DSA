//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    static int result[2];

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int returnSize;
    int* ans = twoSum(nums, n, target, &returnSize);

    if (ans != NULL) {
        printf("Indices: %d %d\n", ans[0], ans[1]);
    } else {
        printf("No solution found\n");
    }

    return 0;
}
