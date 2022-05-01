#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define ul unsigned long
#define LENGTH 16


typedef struct
{
	char value[LENGTH];
}
binary;


binary *long_to_binary(ul x);
ul binary_to_long(binary *x);
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

binary *long_to_binary(ul x)
{
	ul tmp_x = x;
	ul pow2;
	binary *output = malloc(sizeof(binary));

	for (int i = 0; i < LENGTH; i++)
	{
		pow2 = (ul) pow(2, LENGTH - i - 1);

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

ul binary_to_long(binary *x)
{
	binary *tmp_x = x;
	ul output = 0;

	for (int i = 0; i < LENGTH; i++)
	{
		if (tmp_x->value[i] == '1')
		{
			output += (ul) pow(2, LENGTH - i - 1);
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
		if (x->value[i] - '0' ^ y->value[i] - '0')
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
		if (!(x->value[i] - '0' ^ y->value[i] - '0'))
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
