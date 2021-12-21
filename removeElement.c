#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int slowIndex = 0, fastIndex = 0;

    for (fastIndex = 0; fastIndex < numsSize; fastIndex++) {
        if (nums[fastIndex] != val) {
            nums[slowIndex++] = nums[fastIndex];
        }
    }

    return slowIndex;
}

int main(int argc, char* argv[])
{
    int arr[] = {1, 1, 2, 3, 4, 5, 1};

    int num = removeElement(arr, sizeof(arr) / sizeof(arr[0]), 1);

    printf("num = %d\n", num);

    return 0;
}