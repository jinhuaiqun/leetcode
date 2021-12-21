/*
 * @Author: RiGe
 * @Date: 2021-08-19 18:43:07
 * @Description: 
 */

#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize)
{
    int i = 0, j = 0;
    int sum = 0;
    int result = __INT32_MAX__;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
        
        while (sum >= target)
        {
            int len = i - j + 1;
            result = len < result ? len : result;
            sum -= nums[j++];
        }
    }

    return result == __INT32_MAX__ ? 0 : result;
}

int main(int argc, char *argv[])
{
    int target = 7;
    int nums[] = {2,3,1,2,4,3};

    int ret = minSubArrayLen(target, nums, sizeof(nums)/sizeof(nums[0]));
    printf("%d\n", ret);

    return 0;
}