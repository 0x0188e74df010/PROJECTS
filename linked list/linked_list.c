#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


typedef struct node
{
	int number;
	struct node *next;
} node;


node *create_node(const int num);
void print_list(node *head);
int len_list(node *head);
int get_node(node *head, int index);
void remove_node(node *head, int index);
void insert_node(node *head, int num, int index);
void free_list(node *head);


int main(void)
{
	char command[16];
	int num;
	int index;

	node *head = NULL;
	node *added = NULL;

	while (true)
	{
		printf(">> ");
		fgets(command, 16, stdin);

		if (sscanf(command, "%d", &num) != 0)
		{
			if (head == NULL)
			{
				head = create_node(num);
				if (head == NULL) break;

				added = head;
			}
			else
			{
				added->next = create_node(num);
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
		else if (sscanf(command, "index %d", &index) != 0 || sscanf(command, "i %d", &index) != 0)
		{
			int len = len_list(head);
			if (index >= len || len <= 0 || index < 0) continue;

			printf("%d\n", get_node(head, index));
		}
		else if (sscanf(command, "remove %d", &index) != 0 || sscanf(command, "rm %d", &index) != 0)
		{
			int len = len_list(head);
			if (index >= len || len <= 0 || index < 0) continue;

			if (index == 0) 
			{
				node *to_free = head;

				head = head->next;

				free(to_free);
			}
			else
			{
				remove_node(head, index);
			}
		}
		else if (sscanf(command, "insert %d %d", &num, &index) != 0)
		{
			int len = len_list(head);
			if (index >= len || len <= 0 || index < 0) continue;

			if (index == 0)
			{
				node *p = head;

				head = create_node(num);
				head->next = p;
			}
			else
			{
				insert_node(head, num, index);
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

node *create_node(const int num)
{
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL) return NULL;

	new_node->number = num;
	new_node->next = NULL;

	usleep(200000);								// sleep for 0.2 second

	return new_node;
}

void print_list(node *head)
{
	node *p = head;
	
	printf("[");
	while (p->next != NULL)
	{
		printf("%d, ", p->number);
		p = p->next;
	}
	printf("%d]\n", p->number);
}

int len_list(node *head)
{
	int len = 0;
	node *p = head;

	while (p != NULL)
	{
		len++;
		p = p->next;
	}

	return len;
}

int get_node(node *head, int index)
{
	node *p = head;

	for (int i = 0; i < index; i++)
	{
		p = p->next;
	}

	return p->number;
}

void remove_node(node *head, int index)
{
	node *p = head;

	for (int i = 0; i < (index - 1); i++)
	{
		p = p->next;
	}

	node *to_free = p->next;
	p->next = p->next->next;

	free(to_free);
}

void free_list(node *head)
{
	node *next = NULL;
	
	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}

	sleep(1);							// sleep for 1 second
}

void insert_node(node *head, int num, int index)
{
	node *p = head;

	for (int i = 0; i < (index - 1); i++)
	{
		p = p->next;
	}

	node *old_p_next = p->next;
	p->next = create_node(num);
	p->next->next = old_p_next;
}
