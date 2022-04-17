#include <stdlib.h>
#include <stdio.h>


typedef struct LinkedList
{
	int num;
	struct LinkedList *next;
} LinkedList;


LinkedList *create_new_element(const int number);
void print_array(LinkedList *head);


int main(void)
{
	LinkedList *head = NULL;
	LinkedList *added = NULL;

	int age;
	scanf("%d", &age);

	head = create_new_element(age);
	added = head;

	while (1)
	{
		scanf(" %d", &age);
		if (age == 2022) break;

		added->next = create_new_element(age);
		added = added->next;
	}

	print_array(head);

	free(head);
	free(added);

	return 0;
}

LinkedList *create_new_element(const int number)
{
	LinkedList *element = NULL;
	element = malloc(sizeof(LinkedList));
	if (element == NULL) return NULL;

	element->next = NULL;
	element->num = number;

	printf("created new element: %p\n", element);

	return element;
}

void print_array(LinkedList *head)
{
	LinkedList *t = head;
	
	printf("[");
	while (t->next)
	{
		printf("%d, ", t->num);
		t = t->next;
	}
	printf("%d]\n", t->num);
}
