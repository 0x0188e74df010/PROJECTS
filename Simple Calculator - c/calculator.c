#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    double num1, num2, result;
    char op;

    while (true)
    {
        scanf("%lf %c %lf", &num1, &op, &num2);
        switch (op)
        {
            case '+':
                result = num1 + num2;
                break;
            
            case '-':
                result = num1 - num2;
                break;
            
            case '*':
            case 'x':
                result = num1 * num2;
                break;

            case '/':
                result = num1 / num2;
                break;

            case '^':
                result = pow(num1, num2);
                break;

            default:
                continue;
        }

        printf("%lf\n", result);
    }

    return 0;
}