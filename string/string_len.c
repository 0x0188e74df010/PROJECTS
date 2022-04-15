#include <stdio.h>

int string_len(char *string);

int main(void)
{
    //                     \0
    char string1[] = "abcde";

    int string1_len = string_len(string1);

    printf("Len of string1: %d\n", string1_len);

    return 0;
}

int string_len(char *string)
{
    if (*string == '\0') 
    { 
        return 0; 
    }
    else 
    { 
        return 1 + string_len(string + 1); 
    }
}
