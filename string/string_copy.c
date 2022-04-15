#include <stdio.h>
#include <string.h>

void string_copy(char *destination, char *origin);

int main(void)
{
    char string1[] = "HELLO!";
    char string2[2];

    string_copy(string2, string1);

    printf("string2: %s\n", string2);

    return 0;
}

// unsafe
void string_copy(char *destination, char *origin)
{
    printf("origin len: %ld\n", strlen(origin));
    printf("destination len: %ld\n", strlen(destination));

    for (int i = 0; i < strlen(origin)+1; i++)
    {
        destination[i] = origin[i];
    }
}
