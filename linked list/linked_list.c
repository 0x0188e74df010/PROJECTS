#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct node
{
	int num;
	struct node *next;
} node;


node *create_new_node(const int number);
void print_list(node *head);
int len_list(node *head);
int get_node(node *head, int index);
void remove_node(node *head, int index);
void free_list(node *head);


int main(void)
{
	char command[16];
	int num;

	node *head = NULL;
	node *added = NULL;

	while (1)
	{
		printf(">> ");
		fgets(command, 16, stdin);

		if (sscanf(command, "%d", &num) != 0)
		{
			if (head == NULL)
			{
				head = create_new_node(num);
				if (head == NULL) break;

				added = head;
			}
			else
			{
				added->next = create_new_node(num);
				if (added->next == NULL) break;

				added = added->next;
			}
		}
		else if (strcmp("print\n", command) == 0 || strcmp("p\n", command) == 0)
		{
			if (head == NULL) continue;

			print_list(head);
		}
		else if (strcmp("len\n", command) == 0)
		{
			printf("%d\n", len_list(head));
		}
		else if (sscanf(command, "index %d", &num) != 0 || sscanf(command, "i %d", &num) != 0)
		{
			int len = len_list(head);
			if (num >= len || len <= 0 || num < 0) continue;

			printf("%d\n", get_node(head, num));
		}
		else if (sscanf(command, "remove %d", &num) != 0 || sscanf(command, "rm %d", &num) != 0)
		{
			int len = len_list(head);
			if (num >= len || len <= 0 || num < 0) continue;

			if (num == 0) 
			{
				node *p = head;
				head = head->next;
				free(p);
			}
			else
			{
				remove_node(head, num);
			}
		}
		else if (strcmp("free\n", command) == 0)
		{
			free_list(head);
			head = NULL;
		}
		else if (strcmp("quit\n", command) == 0)
		{
			break;
		}
	}

	free_list(head);

	return 0;
}

node *create_new_node(const int number)
{
	node *element = malloc(sizeof(node));
	if (element == NULL) return NULL;

	element->num = number;
	element->next = NULL;

	printf("allocated new node: %p\n", element);

	return element;
}

void print_list(node *head)
{
	node *t = head;
	
	printf("[");
	while (t->next != NULL)
	{
		printf("%d, ", t->num);
		t = t->next;
	}
	printf("%d]\n", t->num);
}

int len_list(node *head)
{
	int len = 0;
	node *t = head;

	while (t != NULL)
	{
		len++;
		t = t->next;
	}

	return len;
}

int get_node(node *head, int index)
{
	node *t = head;

	for (int i = 0; i < index; i++)
	{
		t = t->next;
	}

	return t->num;
}

void remove_node(node *head, int index)
{
	node *p = head;

	for (int i = 0; i < (index - 1); i++)
	{
		p = p->next;
	}
	node *free_node = p->next;
	p->next = p->next->next;

	free(free_node);
}

void free_list(node *head)
{
	node *next = NULL;
	
	while (head != NULL)
	{
		next = head->next;
		free(head);
		printf("freed %p\n", head);
		head = next;
	}
}
