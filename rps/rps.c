#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>


int random_rps();


int main(void)
{
    int score = 0;
    char rps[] = {'r', 'p', 's'};
    char computer_input = rps[random_rps()];
    char player_input;
    char *result = NULL;
    
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

        computer_input = rps[random_rps()];
        
        printf("%c vs %c\n", player_input, computer_input);
        
        switch (player_input)
        {
            case 'r':
                switch (computer_input)
                {   
                    case 'p':
                        result = "lose";
                        score--;
                        break;

                    case 's':
                        result = "win";
                        score++;
                        break;

                    default:
                        result = "draw";
                        break;
                }
                break;
            
            case 'p':
                switch (computer_input)
                {
                    case 'r':
                        result = "win";
                        score++;
                        break;

                    case 's':
                        result = "lose";
                        score--;
                        break;

                    default:
                        result = "draw";
                        break;
                }
                break;

            case 's':
                switch (computer_input)
                {
                    case 'r':
                        result = "lose";
                        score--;
                        break;

                    case 'p':
                        result = "win";
                        score++;
                        break;

                    default:
                        result = "draw";
                        break;
                }
                break;
        }

        printf("%s\n", result);
        printf("score: %d\n", score);
    }

    return 0;
}

int random_rps()
{
    srand(time(NULL));
    int result = rand() % 3;

    return result;
}
