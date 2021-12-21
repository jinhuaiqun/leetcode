/*
 * @Author: RiGe
 * @Date: 2021-08-19 14:33:13
 * @Description: 
 */

#include <stdio.h>

int binarySearch(int *nums, int left, int right, int target)
{
    int ret = 0;

    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (nums[mid] < target) {
        ret = binarySearch(nums, mid + 1, right, target);
    } else if (nums[mid] > target) {
        ret = binarySearch(nums, left, mid-1, target);
    } else {
        return mid;     
    }
        
    return ret;
}

int search(int *nums, int numSize, int target)
{
    if (nums == NULL)
        return -1;

    return binarySearch(nums, 0, numSize-1, target);
}

int main(int argc, char *argv[])
{
    int nums[] = {1,2,3,4,5,7,8,11};

    int index = search(nums, sizeof(nums)/sizeof(nums[0]), 2);

    printf("index = %d\n", index);

    return 0;
}
