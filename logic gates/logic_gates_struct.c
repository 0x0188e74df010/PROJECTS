#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define LENGTH 16


typedef struct
{
	char value[LENGTH];
}
binary;


binary *long_to_binary(unsigned long x);
unsigned long binary_to_long(binary *x);
binary *and_operator(binary *x, binary *y);
binary *or_operator(binary *x, binary *y);
binary *xor_operator(binary *x, binary *y);
binary *nand_operator(binary *x, binary *y);
binary *nor_operator(binary *x, binary *y);
binary *xnor_operator(binary *x, binary *y);


int main(void)
{
	binary *a = long_to_binary(12379);
	binary *b = long_to_binary(21389);


	printf("%s %ld\n", a->value, binary_to_long(a));
	printf("%s %ld\n", b->value, binary_to_long(b));

	printf("----------------\n");
	
	printf("%s %ld\n", and_operator(a, b)->value, binary_to_long(and_operator(a, b)));
	printf("%s %ld\n", or_operator(a, b)->value, binary_to_long(or_operator(a, b)));
	printf("%s %ld\n", xor_operator(a, b)->value, binary_to_long(xor_operator(a, b)));
	printf("%s %ld\n", nand_operator(a, b)->value, binary_to_long(nand_operator(a, b)));
	printf("%s %ld\n", nor_operator(a, b)->value, binary_to_long(nor_operator(a, b)));
	printf("%s %ld\n", xnor_operator(a, b)->value, binary_to_long(xnor_operator(a, b)));


	free(a);
	free(b);

	return 0;
}

binary *long_to_binary(unsigned long x)
{
	unsigned long tmp_x = x;
	unsigned long pow2;
	binary *output = malloc(sizeof(binary));

	for (int i = 0; i < LENGTH; i++)
	{
		pow2 = (unsigned long) pow(2, LENGTH - i - 1);

		if (tmp_x >= pow2)
		{
			output->value[i] = '1';
			tmp_x -= pow2;
		}
		else
		{
			output->value[i] = '0';
		}
	}

	return output;
}

unsigned long binary_to_long(binary *x)
{
	binary *tmp_x = x;
	unsigned long output = 0;

	for (int i = 0; i < LENGTH; i++)
	{
		if (tmp_x->value[i] == '1')
		{
			output += (unsigned long) pow(2, LENGTH - i - 1);
		}
	}

	return output;
}

binary *and_operator(binary *x, binary *y)
{
	binary *output = malloc(sizeof(binary));

	for (int i = 0; i < LENGTH; i++)
	{
		if (x->value[i] - '0' && y->value[i] - '0')
		{
			output->value[i] = '1';
		}
		else
		{
			output->value[i] = '0';
		}
	}

	return output;
}

binary *or_operator(binary *x, binary *y)
{
	binary *output = malloc(sizeof(binary));

	for (int i = 0; i < LENGTH; i++)
	{
		if (x->value[i] - '0' || y->value[i] - '0')
		{
			output->value[i] = '1';
		}
		else
		{
			output->value[i] = '0';
		}
	}

	return output;
}

binary *xor_operator(binary *x, binary *y)
{
	binary *output = malloc(sizeof(binary));

	for (int i = 0; i < LENGTH; i++)
	{
		if ((x->value[i] - '0' || y->value[i] - '0') && !(x->value[i] - '0' && y->value[i] - '0'))
		{
			output->value[i] = '1';
		}
		else
		{
			output->value[i] = '0';
		}
	}

	return output;
}

binary *nand_operator(binary *x, binary *y)
{
	binary *output = malloc(sizeof(binary));

	for (int i = 0; i < LENGTH; i++)
	{
		if (!(x->value[i] - '0' && y->value[i] - '0'))
		{
			output->value[i] = '1';
		}
		else
		{
			output->value[i] = '0';
		}
	}

	return output;
}

binary *nor_operator(binary *x, binary *y)
{
	binary *output = malloc(sizeof(binary));

	for (int i = 0; i < LENGTH; i++)
	{
		if (!(x->value[i] - '0' || y->value[i] - '0'))
		{
			output->value[i] = '1';
		}
		else
		{
			output->value[i] = '0';
		}
	}

	return output;
}

binary *xnor_operator(binary *x, binary *y)
{
	binary *output = malloc(sizeof(binary));

	for (int i = 0; i < LENGTH; i++)
	{
		if (!((x->value[i] - '0' || y->value[i] - '0') && !(x->value[i] - '0' && y->value[i] - '0')))
		{
			output->value[i] = '1';
		}
		else
		{
			output->value[i] = '0';
		}
	}

	return output;
}
