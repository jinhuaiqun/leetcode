/*
 * @Author: RiGe
 * @Date: 2021-12-21 14:58:24
 * @Description: 
 */
#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize){
    int i = 0;
    char tmp;

    for (i = 0; i < sSize/2; i++) {
        tmp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = tmp;
    }
}

int main()
{
    char str[] = "abcdefg";

    reverseString(str, strlen(str));

    printf("%s\n", str);

    return 0;
}