#include <stdio.h>

int binary_search(int arr[], int arr_size, int target)
{
    int left = 0;
    int right = arr_size-1;
    int mid = left + (right-left)/2;

    while (left <= right) {
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target){
            right =  mid - 1; 
        } else {
            return mid;
        }    

        mid = left + (right - left)/2;
    }

    return -1;
}

int main(void)
{
    int arr[5] = {-1,1,3,4,5};

    int ret = binary_search(arr, 5, 11);

    printf("ret = %d\n", ret);
    
    return 0;
}
