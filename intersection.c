/*
 * @Author: RiGe
 * @Date: 2021-12-20 13:31:29
 * @Description: 
 */
#include <stdio.h>
#include <assert.h>

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{


    return NULL;
}

void test1()
{
    int nums1[4] = {1,2,2,1};
    int nums2[2] = {2, 2};
    int rSize = 0;
    int *res = NULL;

    res = intersection(nums1, 4, nums2, 2, &rSize);
    assert(res != NULL);

    assert(res[0] == 2 && rSize == 1);

    printf("test1 OK\n");
}

int main(void)
{
    

    return 0;
}