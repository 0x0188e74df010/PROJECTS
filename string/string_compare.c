#include <stdio.h>
#include <string.h>

int string_compare(char *string1, char *string2);

int main(void)
{
	printf("%d\n", string_compare("HELLO", "HELLO"));

	return 0;
}

int string_compare(char *string1, char *string2)
{
	if (strlen(string1) != strlen(string2)) return 1;

	for (int i = 0; i < strlen(string1); i++)
	{
		if (string1[i] != string2[i]) return 1;
	}

	return 0;
}
