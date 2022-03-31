#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int random_result();

int main(void)
{
    const char *RESULT[] = {"win", "lose", "draw"};
    int score = 0;
    int result;
    char player_input;

    while (true)
    {
        while (true)
        {
            printf("r/p/s: ");
            scanf(" %c", &player_input);

            if (player_input == 'r' || player_input == 'p' || player_input == 's')
            {
                break;
            }
        }

        result = random_result();
        if (result == 0)
        {
            score++;
        }
        else if (result == 1)
        {
            score--;
        }

        printf("%s\n", RESULT[result]);
        printf("score: %d\n", score);
    }

    return 0;
}

int random_result()
{
    srand(time(NULL));
    int result = rand() % 3;

    return result;
}
