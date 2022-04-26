#include <stdlib.h>
#include <stdio.h>


typedef struct node
{
	struct node *prev;
	int num;
	struct node *next;
}
node;


node *create_node(int num);


int main(void)
{
	node *first = create_node(0);
	node *second = create_node(1);
	node *third = create_node(2);

	first->next = second;
	second->prev = first;
	second->next = third;
	third->prev = second;

	printf("%d\n", third->num);
	printf("%d\n", third->prev->num);
	printf("%d\n", third->prev->prev->num);

	printf("%ld\n", sizeof(node));

	free(first);
	free(second);
	free(third);

	return 0;
}

node *create_node(int num)
{
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL) return NULL;

	new_node->prev = NULL;
	new_node->num = num;
	new_node->next = NULL;

	return new_node;
}
