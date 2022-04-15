/*

 * remaking card_flip.py in c, just because
 * inspired by x+y movie
 * 
 * face down: 0
 * face up: 1
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#define CARDS_LENGTH 6

void print_array(int arr[], int size);
int interact(int arr[], int size, int index);

int main(void)
{
    int *cards = calloc(CARDS_LENGTH, sizeof(int));
    int interact_count = 0;
    int user_input;

    while (1)
    {
        print_array(cards, CARDS_LENGTH);
        printf("Index: ");
        scanf("%d", &user_input);

        if (interact(cards, CARDS_LENGTH, user_input) == 0)
        {
            interact_count++;
        }
    }

    print_array(cards, CARDS_LENGTH);
    printf("%d", interact_count);

    free(cards);
    return 0;
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

int interact(int arr[], int size, int index)
{
    if (index >= (size - 1) || arr[index] == 1)
    {
        return 1;
    }

    arr[index] = 1;
    if (arr[index + 1] == 0)
    {
        arr[index + 1] = 1;
        return 0;
    }
    arr[index + 1] = 0;
    return 0;
}
