#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct LinkedList
{
	int num;
	struct LinkedList *next;
} LinkedList;


LinkedList *create_new_element(const int number);
void free_up(LinkedList *head);
void print_list(LinkedList *head);


int main(void)
{
	char command[16];
	int num;

	LinkedList *head = NULL;
	LinkedList *added = NULL;

	while (1)
	{
		printf(": ");
		fgets(command, 16, stdin);

		if (strcmp("quit\n", command) == 0)
		{
			break;
		}
		else if (strcmp("print\n", command) == 0)
		{
			print_list(head);
		}
		else if (sscanf(command, "%d", &num) != 0)
		{
			if (head == NULL)
			{
				head = create_new_element(num);
				if (head == NULL) break;

				added = head;
			}
			else
			{
				added->next = create_new_element(num);
				if (added->next == NULL) break;

				added = added->next;
			}
		}
	}

	free_up(head);

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

void free_up(LinkedList *head)
{
	LinkedList *next = NULL;
	
	while (head)
	{
		next = head->next;
		printf("freeing %d at %p\n", head->num, head);
		free(head);
		head = next;
	}
}

void print_list(LinkedList *head)
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
