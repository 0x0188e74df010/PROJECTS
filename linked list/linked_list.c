#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct LinkedList
{
	int num;
	struct LinkedList *next;
} LinkedList;


LinkedList *create_new_element(const int number);
void print_list(LinkedList *head);
int len_list(LinkedList *head);
int get_index(LinkedList *head, int index);
void free_up(LinkedList *head);


int main(void)
{
	char command[16];
	int num;

	LinkedList *head = NULL;
	LinkedList *added = NULL;

	while (1)
	{
		printf(">> ");
		fgets(command, 16, stdin);

		if (strcmp("quit\n", command) == 0)
		{
			break;
		}
		else if (strcmp("print\n", command) == 0)
		{
			print_list(head);
		}
		else if (strcmp("len\n", command) == 0)
		{
			printf("%d\n", len_list(head));
		}
		else if (sscanf(command, "index %d", &num) != 0)
		{
			int len = len_list(head);
			if (num >= len || len <= 0 || num < 0) continue;

			printf("%d\n", get_index(head, num));
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

int len_list(LinkedList *head)
{
	int len = 0;
	LinkedList *t = head;

	while (t)
	{
		len++;
		t = t->next;
	}

	return len;
}

int get_index(LinkedList *head, int index)
{
	LinkedList *t = head;

	for (int i = 0; i < index; i++)
	{
		t = t->next;
	}

	return t->num;
}

void free_up(LinkedList *head)
{
	LinkedList *next = NULL;
	
	while (head)
	{
		next = head->next;
		free(head);
		printf("freed %p\n", head);
		head = next;
	}
}
