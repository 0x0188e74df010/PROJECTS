#include <stdio.h>

char *my_string_copy1(char *destination, char *source);
char *my_string_copy2(char *destination, char *source);

int main(void)
{
    char src[] = "copy this";
    char dest[100];

    char *dest_ptr = my_string_copy2(dest, src);

    printf("     src: %s\n", src);
    printf("    dest: %s\n", dest);
    printf("dest_ptr: %s\n", dest_ptr);

    printf("\n");

    printf("     src: %p\n", src);
    printf("    dest: %p\n", dest);
    printf("dest_ptr: %p\n", dest_ptr);

    return 0;
}

// unsafe
char *my_string_copy1(char *destination, char *source)
{
    if (destination == NULL) return NULL;

    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
    return destination;
}

char *my_string_copy2(char *destination, char *source)
{
    if (destination == NULL) return NULL;

    char *return_ptr = destination;

    while (*source != '\0')
    {
        *destination = *source;

        destination++;
        source++;
    }
    *destination = '\0';

    return return_ptr;
}
