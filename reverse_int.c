#include <assert.h>
#include <limits.h>
#include <stdio.h>

int reverse(int orign)
{
    long x   = orign;
    long num = 0;

    while (x != 0) {
        if ((num * 10 + x % 10) > INT_MAX || (num * 10 + x % 10) < INT_MIN) {
            return 0;
        }

        num = num * 10 + x % 10;

        x = x / 10;
    }

    return num;
}

void test1()
{
    int input = 123;

    assert(321 == reverse(input));

    printf("test1 Running OK!\n");
}

void test2()
{
    int input = -123;

    assert(-321 == reverse(input));

    printf("test2 Running OK!\n");
}

void test3()
{
    int input = 0;

    assert(0 == reverse(input));

    printf("test3 Running OK!\n");
}

void test4()
{
    int input = 1534236469;

    assert(0 == reverse(input));

    printf("%s Running OK!\n", __func__);
}

void test5()
{
    int input = -2147483648;

    assert(0 == reverse(input));

    printf("%s Running OK!\n", __func__);
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();

    printf("-1%%10 = %d\n", -1 % 10);

    return 0;
}