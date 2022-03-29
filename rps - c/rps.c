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
    
    while (true)
    {
        printf("r/p/s: ");
        scanf(" %c", &player_input);

        if (player_input == 'r' || player_input == 'p' || player_input == 's')
        {
            break;
        }
    }

    return 0;
}

int random_rps()
{
    srand(time(NULL));
    int result = rand() % 3;

    return result;
}
