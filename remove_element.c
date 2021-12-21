#include <stdio.h>

int remove_element(int arr[], int arr_size, int val)
{
    int slow_index = 0;
    int fast_index = 0;

    for (fast_index = 0; fast_index < arr_size; fast_index++) {
        if (arr[fast_index] != val) {
            arr[slow_index++] = arr[fast_index];    
        } 
    }

    return slow_index; 
}

int main(void)
{
    int arr[5] = {1,2,2,2,7};

    int ret = remove_element(arr, 5, 2);

    printf("ret = %d\n", ret);
    
    return 0;
}
