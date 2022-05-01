#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define ul unsigned long
#define LENGTH 16


char *long_to_binary(ul x);
ul binary_to_long(char *x);
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


	printf("%s %ld\n", a, binary_to_long(a));
	printf("%s %ld\n", b, binary_to_long(b));

	printf("----------------\n");
	
	printf("%s %ld\n", and_operator(a, b), binary_to_long(and_operator(a, b)));
	printf("%s %ld\n", or_operator(a, b), binary_to_long(or_operator(a, b)));
	printf("%s %ld\n", xor_operator(a, b), binary_to_long(xor_operator(a, b)));
	printf("%s %ld\n", nand_operator(a, b), binary_to_long(nand_operator(a, b)));
	printf("%s %ld\n", nor_operator(a, b), binary_to_long(nor_operator(a, b)));
	printf("%s %ld\n", xnor_operator(a, b), binary_to_long(xnor_operator(a, b)));


	free(a);
	free(b);

	return 0;
}

char *long_to_binary(ul x)
{
	ul tmp_x = x;
	ul pow2;
	char *output = malloc(LENGTH * sizeof(char));

	for (int i = 0; i < LENGTH; i++)
	{
		pow2 = (ul) pow(2, LENGTH - i - 1);

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

ul binary_to_long(char *x)
{
	char *tmp_x = x;
	ul output = 0;

	for (int i = 0; i < LENGTH; i++)
	{
		if (*tmp_x == '1')
		{
			output += (ul) pow(2, LENGTH - i - 1);
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
		if (x[i] - '0' ^ y[i] - '0')
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
		if (!(x[i] - '0' ^ y[i] - '0'))
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
