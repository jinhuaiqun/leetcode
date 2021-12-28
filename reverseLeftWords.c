/*
 * @Author: RiGe
 * @Date: 2021-12-24 16:47:13
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseLeftWords(char* s, int n)
{
    int   len = 0;
    int   i   = 0;
    int   j   = 0;
    char* res = NULL;

    if (s == NULL || strlen(s) == 0) {
        return NULL;
    }

    len = strlen(s);
    res = (char*)malloc(len + 1);
    if (res == NULL) {
        return NULL;
    }

    if (n > len) {
        strncpy(res, s, len);
        res[len] = '\0';
        return res;
    }

    for (i = 0; i < len; i++) {
        if (i >= n) {
            res[j++] = s[i];
        }
    }

    for (i = 0; i < n; i++) {
        res[j++] = s[i];
    }
    res[j] = '\0';

    return res;
}

int main(void)
{
    char str[] = "abcdefg";
    int  k     = 2;

    char* res = reverseLeftWords(str, 2);
    printf("%s\n", res);
    free(res);

    return 0;
}