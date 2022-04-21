#include <stdio.h>
#include <ctype.h>

int count_vowels1(char *string);
int count_vowels2(char *string);

int main(void)
{
	char *test_string = "maybe let's try this string out!";

	printf("count_vowels1: %d\n", count_vowels1(test_string));
	printf("count_vowels2: %d\n", count_vowels2(test_string));

	return 0;
}

int count_vowels1(char *string)
{
	int vowels = 0;
	while (*string != '\0')
	{
		if (tolower(*string) == 'a' || tolower(*string) == 'i' || tolower(*string) == 'u' || tolower(*string) == 'e' || tolower(*string) == 'o')
		{
			vowels++;
		}

		string++;
	}

	return vowels;
}

int count_vowels2(char *string)
{
	if (*string == '\0') return 0;

	char c = tolower(*string);

	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
		return 1 + count_vowels2(string + 1);
	return count_vowels2(string + 1);
}
