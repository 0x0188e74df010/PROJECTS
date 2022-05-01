#include <stdio.h>
#include <string.h>

int main(void)
{
	char output[strlen("FizzBuzz")];
	
	for (int i = 1; i < 101; i++)
	{
		output[0] = '\0';

		if (i % 3 == 0) strcat(output, "Fizz");
		if (i % 5 == 0) strcat(output, "Buzz");

		if (output[0] != '\0')
			printf("%s\n", output);
		else
			printf("%d\n", i);
	}

	return 0;
}
