#include <stdio.h>

int isUnique(char *s)
{
    int i = 0;
    int index = 0;
    int bucket[26] = {0};

    while (s[i] != '\0') {
        index = s[i] - 'a';
        if (bucket[index] == 1)
            return 0;

        bucket[index] = 1; 
        i++;
    }

    return 1;
}

int main(int argc, char *argv[])
{

    if (isUnique(argv[1])) {
        printf("is unique\n"); 
    } else {
        printf("not unique\n"); 
    }

    return 0;
}
