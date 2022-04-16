#include <stdlib.h>
#include <stdio.h>

void print_array(int arr[], int size);
void generate_array(int arr[], int size);

int main(int argc, char *argv[])
{
    int array_length;
    printf("Array Length: ");
    scanf("%d", &array_length);

    int *array = calloc(array_length, sizeof(int));
    print_array(array, array_length);

    generate_array(array, array_length);
    print_array(array, array_length);


    free(array);
    return 0;
}

void generate_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
}

void print_array(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < (size - 1); i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size - 1]);
}
