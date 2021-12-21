#include <stdio.h>

int myAtoi(char *s)
{
    int result = 0;
    int sign = 1;

    while (*s == ' ' && *s != '\0')
        s++;

    if (*s == '+') {
        sign = 1;
        s++;
    } 
    else if (*s == '-') {
        sign = -1;
        s++;
    }

    while (*s >= '0' && *s <= '9') {
        if (result * 10 + *s - '0' > INT_MAX && sign == 1)
            return INT_MAX;
        else if (result * 10 + *s - '0' < INT_MIN && sign == -1)
            return INT_MIN;

        result = result * 10 + *s - '0';
        s++;
    }

    return result*sign;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("./a.out para1\n"); 
        return -1;
    }

    printf("atoi(%s) = %d\n", argv[1], myAtoi(argv[1]));

    return 0;
} 
