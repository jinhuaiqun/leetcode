/*
 * @Author: RiGe
 * @Date: 2021-11-03 17:29:19
 * @Description:
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool isPalindrom(int x)
{
    long rev = 0;
    int  y   = x;

    if (y < 0) {
        return false;
    }

    while (y != 0) {
        rev = rev * 10 + y % 10;
        y /= 10;
    }

    printf("x=%d, rev=%d\n", x, rev);

    if (rev == x) {
        return true;
    }
    else {
        return false;
    }
}

void test1()
{
    int input = 121;

    assert(true == isPalindrom(input));

    printf("%s running OK!\n", __func__);
}

int main()
{
    test1();

    return 0;
}