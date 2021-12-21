/*
 * @Author: RiGe
 * @Date: 2021-12-21 15:09:13
 * @Description: 
 */

#include <stdio.h>
#include <string.h>

#define min(a,b) ((a)<(b)?(a):(b))

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char *l, char *r)
{
    while (l < r) {
        swap(l++, r--);
    }
}

char * reverseStr(char * s, int k){
    int len;
    int i = 0;
    int j = 0;

    if (s == NULL || strlen(s) == 0 || k == 0) {
        return NULL;
    }

    len = strlen(s);

    for (i = 0; i < len; i += k*2) {
        reverse(&s[i], &s[min(i+k-1, len-1)]);
    }

    return s;
}

int main()
{
    char str[] = "abcdefg";
    int k = 2;

    reverseStr(str, k);

    printf("%s\n", str);

    return 0;
}

