#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define ui unsigned int


typedef struct
{
	char name[MAX_NAME];
	int age;
}
person;


ui hash(char *name);
void init_hash_table(person *hash_table);
void print_table(person *hash_table);


int main(void)
{
	person *hash_table[TABLE_SIZE];
	init_hash_table(hash_table);

	/*
	printf("Jacob => %u\n", hash("Jacob"));
	printf("Natalie => %u\n", hash("Natalie"));
	printf("Sara => %u\n", hash("Sara"));
	printf("Mpho => %u\n", hash("Mpho"));
	printf("Tebogo => %u\n", hash("Tebogo"));
	printf("Ron => %u\n", hash("Ron"));
	printf("Jane => %u\n", hash("Jane"));
	printf("Maren => %u\n", hash("Maren"));
	printf("Bill => %u\n", hash("Bill"));
	*/

	print_table(hash_table);

	free(hash_table);

	return 0;
}

ui hash(char *name)
{
	int length = strlen(name);
	ui hash_value = 0;

	for (int i = 0; i < length; i++)
	{
		hash_value += name[i];
		hash_value = hash_value * name[i];
	}

	return hash_value % TABLE_SIZE;
}

void init_hash_table(person *hash_table)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hash_table[i] = NULL;
	}
}

void print_table(person *hash_table)
{
	printf("%d\n", hash_table[0]->name);
}
