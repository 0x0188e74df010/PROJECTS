#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * ADD DELETE A CERTAIN wORD / DELETE AT A CERTAIN INDEX
 */

typedef struct LinkedList
{
	char *str;
	struct LinkedList *next;
} LinkedList;

LinkedList *create_new_element(char *string);
void print_list(LinkedList *head);
int len_list(LinkedList *head);
char *get_index(LinkedList *head, int index);
void free_up(LinkedList *head);

int main(void)
{
	LinkedList *head = NULL;
	LinkedList *added = NULL;

	char command[16];
	char text[64];
	int index;

	while (1)
	{
		fgets(command, sizeof(command), stdin);

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
		else if (sscanf(command, "index %d", &index) != 0)
		{
			int len = len_list(head);
			if (index >= len || len <= 0 || index < 0) continue;
			printf("\"%s\"\n", get_index(head, index));
		}
		else if (sscanf(command, "%s", text) != 0)
		{
			if (head == NULL)
			{
				head = create_new_element(text);
				if (head == NULL) break;

				added = head;
			}
			else
			{
				added->next = create_new_element(text);
				if (added->next == NULL) break;

				added = added->next;
			}
		}
	}

	free_up(head);

	return 0;
}

LinkedList *create_new_element(char *string)
{
	LinkedList *element = NULL;
	element = malloc(sizeof(LinkedList));
	if (element == NULL) return NULL;

	element->str = malloc(sizeof(char *));
	strcpy(element->str, string);
	element->next = NULL;

	printf("created new element: %p\n", element);

	return element;
}

void print_list(LinkedList *head)
{
	LinkedList *t = head;

	printf("[");
	while (t->next != NULL)
	{
		printf("\"%s\", ", t->str);
		t = t->next;
	}
	printf("\"%s\"]\n", t->str);
}

int len_list(LinkedList *head)
{
	int len = 0;
	LinkedList *t = head;

	while (t != NULL)
	{
		len++;
		t = t->next;
	}

	return len;
}

char *get_index(LinkedList *head, int index)
{
	LinkedList *t = head;
	for (int i = 0; i < index; i++)
	{
		t = t->next;
	}

	return t->str;
}

void free_up(LinkedList *head)
{
	LinkedList *next_free = NULL;
	
	while (head != NULL)
	{
		LinkedList *next_free = head->next;
		printf("freed %s at %p\n", head->str, head);
		free(head);
		head = next_free;
	}
}
