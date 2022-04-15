#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *string_append(char *s1, char *s2);

int main(void)
{
    char first[10] = "First ";
    char second[10] = "Second";

    strcat(first, second);
    printf("First: %s\n", first);

    char s1[] = "abc";
    char s2[] = "wxyz";

    char *s = string_append(s1, s2);

    printf("s: %s\n", s);

    free(s);

    return 0;
}

char *string_append(char *s1, char *s2)
{
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int size = s1_len + s2_len + 1;

    char *s = calloc(size, sizeof(char));
    
    for (int i = 0; i < s1_len; i++)
        s[i] = s1[i];
    
    for (int i = 0; i < s2_len; i++)
        s[s1_len + i] = s2[i];

    s[size - 1] = '\0';

    return s;
}
