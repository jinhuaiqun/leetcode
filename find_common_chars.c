/*
 * @Author: RiGe
 * @Date: 2021-11-08 17:12:11
 * @Description:
 */
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) ((x < y) ? (x) : (y))

char** commonChars(char** words, int wordsSize, int* returnSize)
{
    int i           = 0;
    int j           = 0;
    int minfreq[26] = {0};
    int freq[26]    = {0};

    for (i = 0; i < 26; i++) {
        minfreq[i] = INT_MAX;
    }

    for (i = 0; i < wordsSize; i++) {
        memset(freq, 0, sizeof(freq));
        printf("==>%s\n", words[i]);
        int n = strlen(words[i]);
        for (j = 0; j < n; j++) {
            freq[words[i][j] - 'a']++;
        }

        for (j = 0; j < 26; j++) {
            minfreq[j] = MIN(freq[j], minfreq[j]);
        }
    }

    int sum = 0;
    for (i = 0; i < 26; i++) {
        sum += minfreq[i];
    }

    char** ans  = (char**)malloc(sizeof(char*) * sum);
    *returnSize = 0;

    for (i = 0; i < 26; i++) {
        for (j = 0; j < minfreq[i]; j++) {
            ans[*returnSize]    = malloc(sizeof(char) * 2);
            ans[*returnSize][0] = i + 'a';
            ans[*returnSize][1] = '\0';
            (*returnSize)++;
        }
    }
    return ans;
}

void test1()
{
    int i       = 0;
    int retSize = 0;

    char** words = (char**)malloc(sizeof(char*) * 3);
    for (i = 0; i < 3; i++) {
        words[i] = (char*)malloc(10);
    }
    sprintf(words[0], "bella");
    sprintf(words[1], "label");
    sprintf(words[2], "roller");

    char** pAns = commonChars(words, 3, &retSize);

    assert(retSize == 3);

    for (i = 0; i < retSize; i++) {
        printf("char[%d]: %c\n", i, pAns[i][0]);
    }
}

int main(void)
{
    test1();
    return 0;
}