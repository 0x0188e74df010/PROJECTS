#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fill_random(int arr[], int length);

int main(void)
{
	srand(time(NULL));

	int arr[100];
	fill_random(arr, 100);

	for (int i = 0; i < 100; i++)
		printf("arr[%d] = %d\n", i, arr[i]);

	return 0;
}

void fill_random(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		arr[i] = (rand() % 201);
}
