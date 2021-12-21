/*
 * @Author: RiGe
 * @Date: 2021-11-05 14:00:44
 * @Description:
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t)
{
    int i = 0;
    int j = 0;
    int table[26];
    if (s == NULL || t == NULL) {
        return false;
    }

    if (strlen(s) != strlen(t)) {
        return false;
    }

    memset(table, 0, sizeof(int) * 26);

    for (i = 0; i < strlen(s); i++) {
        table[s[i] - 'a']++;
    }

    for (j = 0; j < strlen(t); j++) {
        table[t[j] - 'a']--;
        if (table[t[j] - 'a'] < 0) {
            return false;
        }
    }

    return true;
}

void test1()
{
    assert(true == isAnagram("abc", "cba"));
    printf("%s running OK!\n", __func__);
}

int main(void)
{
    test1();

    return 0;
}