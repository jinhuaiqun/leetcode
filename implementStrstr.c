/*
 * @Author: RiGe
 * @Date: 2021-12-27 15:40:16
 * @Description: 
 */
#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    int n = 0; 
    int m = 0;
    int i = 0;
    int j = 0;

    n = strlen(haystack);
    m = strlen(needle);

    for (i = 0; i + m <= n; i++) {
        int flag = 1;
        for (j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    char str[] = "abc";

    int pos = strStr(str, "bc");

    printf("%d\n", pos);

    return 0;
}