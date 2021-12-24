/*
 * @Author: RiGe
 * @Date: 2021-12-22 15:34:39
 * @Description:
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replaceSpace(char* s)
{
    int i       = 0;
    int j       = 0;
    int str_len = 0;
    int n_space = 0;
    int new_len = 0;

    if (s == NULL) {
        return NULL;
    }

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            n_space++;
        }
        i++;
    }
    str_len = strlen(s);
    new_len = str_len + 2 * n_space;

    char *p = (char *)malloc(new_len+1);

    for (i = str_len - 1, j = new_len - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            p[j] = s[i];
            j--;
        }
        else {
            p[j--] = '0';
            p[j--] = '2';
            p[j--] = '%';
        }
    }
    p[new_len] = '\0';

    return p;
}

int main(void)
{
    char *str = "We are happy.";

    printf("%s\n", replaceSpace(str));
    return 0;
}