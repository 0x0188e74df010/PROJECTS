#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * ADD DELETE A CERTAIN wORD / DELETE AT A CERTAIN INDEX
 */

typedef struct node
{
	char *str;
	struct node *next;
}
node;


node *create_new_node(char *string);
void print_list(node *head);
int len_list(node *head);
char *get_node(node *head, int index);
void remove_node(node *head, int index);
void free_node(node *head);


int main(void)
{
	node *head = NULL;
	node *added = NULL;

	char command[16];
	char text[64];
	int index;

	while (1)
	{
		fgets(command, sizeof(command), stdin);

		if (strcmp("quit\n", command) == 0 || strcmp("q\n", command) == 0)
		{
			break;
		}
		else if (strcmp("print\n", command) == 0 || strcmp("p\n", command) == 0)
		{
			print_list(head);
		}
		else if (strcmp("len\n", command) == 0)
		{
			printf("%d\n", len_list(head));
		}
		else if (sscanf(command, "index %d", &index) != 0 || sscanf(command, "i %d", &index) != 0)
		{
			int len = len_list(head);
			if (index >= len || len <= 0 || index < 0) continue;
			printf("\"%s\"\n", get_node(head, index));
		}
		else if (sscanf(command, "remove %d", &index) != 0 || sscanf(command, "rm %d", &index) != 0)
		{
			int len = len_list(head);
			if (index >= len || len <= 0 || index < 0) continue;

			if (index == 0)
			{
				head = head->next;
			}
			else
			{
				remove_node(head, index);
			}
		}
		else if (sscanf(command, "%s", text) != 0)
		{
			if (head == NULL)
			{
				head = create_new_node(text);
				if (head == NULL) break;

				added = head;
			}
			else
			{
				added->next = create_new_node(text);
				if (added->next == NULL) break;

				added = added->next;
			}
		}
	}

	free_node(head);

	return 0;
}

node *create_new_node(char *string)
{
	node *element = NULL;
	element = malloc(sizeof(node));
	if (element == NULL) return NULL;

	element->str = malloc(sizeof(char *));
	strcpy(element->str, string);
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
		printf("\"%s\", ", t->str);
		t = t->next;
	}
	printf("\"%s\"]\n", t->str);
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

char *get_node(node *head, int index)
{
	node *t = head;
	for (int i = 0; i < index; i++)
	{
		t = t->next;
	}

	return t->str;
}

void remove_node(node *head, int index)
{
	node *p = head;

	for (int i = 0; i < (index - 1); i++)
	{
		p = p->next;
	}
	p->next = p->next->next;
}

void free_node(node *head)
{
	node *next_free = NULL;
	
	while (head != NULL)
	{
		node *next_free = head->next;
		printf("freed %p\n", head);
		free(head);
		head = next_free;
	}
}

void insert_node(node *head, char *string, int index)
{
	node *p = head;

	for (int i = 0; i < (index - 1); i++)
	{
		p = p->next;
	}

	node *old_p_next = p->next;
	p->next = create_new_node(string);
	p->next->next = old_p_next;
}
