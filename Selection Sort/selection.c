#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void swap(int *a, int *b);
void generate_arr(int arr[], int size);
void sort(int arr[], int size);
void print_arr(int arr[], int size);


int main(void)
{
    const int ARR_SIZE = 5000;
    int arr[ARR_SIZE];
    generate_arr(arr, ARR_SIZE);


    float t = (float)clock()/CLOCKS_PER_SEC;            // get starting time
    sort(arr, ARR_SIZE);
    printf("%f\n", ((float)clock()/CLOCKS_PER_SEC)-t);  // print run time

}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void generate_arr(int arr[], int size)
{
    // generate array
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }

    // randomize array
    srand(time(NULL));

    for (int i = size-1; i > 0; i--)
    {
        swap(&arr[i], &arr[rand() % (i+1)]);
    }
}

void sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // print_arr(arr, size);
        int min = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

void print_arr(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size-1; i++)
    {
        printf("%i,", arr[i]);
    }
    printf("%i]\n", arr[size-1]);
}
