#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define LENGTH 16


char *long_to_binary(unsigned long x);
unsigned long binary_to_long(char *x);
char *and_operator(char *x, char *y);
char *or_operator(char *x, char *y);
char *xor_operator(char *x, char *y);
char *nand_operator(char *x, char *y);
char *nor_operator(char *x, char *y);
char *xnor_operator(char *x, char *y);


int main(void)
{
	char *a = long_to_binary(12379);
	char *b = long_to_binary(21389);
	char *c = xnor_operator(a, b);


	printf("%s %ld\n", a, binary_to_long(a));
	printf("%s %ld\n", b, binary_to_long(b));
	printf("----------------\n");
	printf("%s %ld\n", c, binary_to_long(c));


	free(a);
	free(b);
	free(c);

	return 0;
}

char *long_to_binary(unsigned long x)
{
	unsigned long tmp_x = x;
	unsigned long pow2;
	char *output = malloc(LENGTH * sizeof(char));

	for (int i = 0; i < LENGTH; i++)
	{
		pow2 = (unsigned long) pow(2, LENGTH - i - 1);

		if (tmp_x >= pow2)
		{
			output[i] = '1';
			tmp_x -= pow2;
		}
		else
		{
			output[i] = '0';
		}
	}

	return output;
}

unsigned long binary_to_long(char *x)
{
	char *tmp_x = x;
	unsigned long output = 0;

	for (int i = 0; i < LENGTH; i++)
	{
		if (*tmp_x == '1')
		{
			output += (unsigned long) pow(2, LENGTH - i - 1);
		}

		tmp_x++;
	}

	return output;
}

char *and_operator(char *x, char *y)
{
	char *output = malloc(LENGTH * sizeof(char));

	for (int i = 0; i < LENGTH; i++)
	{
		if (x[i] - '0' && y[i] - '0')
		{
			output[i] = '1';
		}
		else
		{
			output[i] = '0';
		}
	}

	return output;
}

char *or_operator(char *x, char *y)
{
	char *output = malloc(LENGTH * sizeof(char));

	for (int i = 0; i < LENGTH; i++)
	{
		if (x[i] - '0' || y[i] - '0')
		{
			output[i] = '1';
		}
		else
		{
			output[i] = '0';
		}
	}

	return output;
}

char *xor_operator(char *x, char *y)
{
	char *output = malloc(LENGTH * sizeof(char));

	for (int i = 0; i < LENGTH; i++)
	{
		if ((x[i] - '0' || y[i] - '0') && !(x[i] - '0' && y[i] - '0'))
		{
			output[i] = '1';
		}
		else
		{
			output[i] = '0';
		}
	}

	return output;
}

char *nand_operator(char *x, char *y)
{
	char *output = malloc(LENGTH * sizeof(char));

	for (int i = 0; i < LENGTH; i++)
	{
		if (!(x[i] - '0' && y[i] - '0'))
		{
			output[i] = '1';
		}
		else
		{
			output[i] = '0';
		}
	}

	return output;
}

char *nor_operator(char *x, char *y)
{
	char *output = malloc(LENGTH * sizeof(char));

	for (int i = 0; i < LENGTH; i++)
	{
		if (!(x[i] - '0' || y[i] - '0'))
		{
			output[i] = '1';
		}
		else
		{
			output[i] = '0';
		}
	}

	return output;
}

char *xnor_operator(char *x, char *y)
{
	char *output = malloc(LENGTH * sizeof(char));

	for (int i = 0; i < LENGTH; i++)
	{
		if (!((x[i] - '0' || y[i] - '0') && !(x[i] - '0' && y[i] - '0')))
		{
			output[i] = '1';
		}
		else
		{
			output[i] = '0';
		}
	}

	return output;
}
