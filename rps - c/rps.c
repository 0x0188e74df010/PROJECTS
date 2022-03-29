#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>


int random_rps();


int main(void)
{
    char rps[] = {'r', 'p', 's'};
    char computer_input = rps[random_rps()];
    char player_input;
    char *result = NULL;
    
    while (true)
    {
        printf("r/p/s: ");
        scanf(" %c", &player_input);

        if (player_input == 'r' || player_input == 'p' || player_input == 's')
        {
            break;
        }
    }

    printf("%c vs %c\n", player_input, computer_input);

    switch (player_input)
    {
        case 'r':
            switch (computer_input)
            {
                case 'r':
                    result = "draw";
                    break;
                
                case 'p':
                    result = "lose";
                    break;

                case 's':
                    result = "win";
                    break;
            }
            break;
        
        case 'p':
            switch (computer_input)
            {
                case 'r':
                    result = "win";
                    break;

                case 'p':
                    result = "draw";
                    break;

                case 's':
                    result = "lose";
                    break;
            }
            break;

        case 's':
            switch (computer_input)
            {
                case 'r':
                    result = "lose";
                    break;

                case 'p':
                    result = "win";
                    break;

                case 's':
                    result = "draw";
                    break;
            }
            break;
    }

    printf("%s", result);

    return 0;
}

int random_rps()
{
    srand(time(NULL));
    int result = rand() % 3;

    return result;
}
