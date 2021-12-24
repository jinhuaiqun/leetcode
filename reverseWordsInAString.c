/*
 * @Author: RiGe
 * @Date: 2021-12-24 15:29:55
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s)
{
    int  i           = 0;
    int  len         = 0;
    char last_char   = ' ';
    int  start_index = -1;
    int  end_index   = -1;
    int  k           = 0;

    if (s == NULL || s[0] == '\0') {
        return NULL;
    }

    len = strlen(s);

    char* res = (char*)malloc(len + 1);

    for (i = len - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            if (last_char == ' ') {
                continue;
            }
            else {
                /*word end*/
                end_index = i;
                if (end_index >= 0 && start_index >= 0 && end_index <= start_index) {
                    int j = end_index+1;
                    while (j <= start_index) {
                        res[k++] = s[j++];
                    }
                    res[k++] = ' ';
                }
            }
        }
        else {
            if (last_char == ' ') {
                /*word start*/
                start_index = i;
            }
        }

        if (i == 0 && s[i] != ' ') {
            end_index = 0;
            if (end_index >= 0 && start_index >= 0 && end_index <= start_index) {
                int j = end_index;
                while (j <= start_index) {
                    res[k++] = s[j++];
                }
            }
        }

        last_char = s[i];
    }

    if (res[k-1] == ' ')
        res[k-1] = '\0';
    else
        res[k] = '\0';

    return res;
}


int main(void)
{
    char str[] = "a good  example";

    printf("[%s]\n", reverseWords(str));
    return 0;
}