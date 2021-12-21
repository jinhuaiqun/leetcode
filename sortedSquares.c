/*
 * @Author: RiGe
 * @Date: 2021-08-19 16:58:17
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    int  i = 0, j = 0, k = numsSize - 1;
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    memcpy(arr, nums, sizeof(int) * numsSize);

    for (i = 0, j = numsSize - 1; i <= j;) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            arr[k] = nums[i] * nums[i];
            i++;
        }
        else {
            arr[k] = nums[j] * nums[j];
            j--;
        }
        k--;
    }

    *returnSize = numsSize;
    return arr;
}

int main(int argc, char* argv[])
{
    int nums[] = {-3, -1, 0, 1, 2, 8};
    int i      = 0;
    int size   = 0;

    int* arr = sortedSquares(nums, sizeof(nums) / sizeof(nums[0]), &size);
    for (i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}