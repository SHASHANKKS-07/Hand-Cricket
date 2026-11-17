#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
int valid_runs()
{
    int runs;
    printf(CYAN "Enter runs (1-6):\n" RESET);
    while (scanf("%d", &runs) != 1 || runs < 1 || runs > 6)
    {
        printf(BOLD CYAN "Enter runs between 1 and 6: " RESET);
        while (getchar() != '\n')
            ;
    }
    return runs;
}
int final_result(int score, int comp_score)
{
    if (score > comp_score)
    {
        printf(BOLD GREEN "        YOU WON!\n" RESET);
    }
    else if (comp_score > score)
    {
        printf(BOLD RED "        COMPUTER WON!\n" RESET);
    }
    else
    {
        printf(BOLD YELLOW "        MATCH DRAW!\n" RESET);
    }
    printf(BOLD MAGENTA "+============================+\n" RESET);
    printf(BOLD CYAN "        SCORE BOARD           \n" RESET);
    printf(BOLD MAGENTA "+============================+\n" RESET);
    printf(BOLD BLUE "   ME       |  COMPUTER\n" RESET);
    printf(BOLD YELLOW "   %d       |     %d\n" RESET, score, comp_score);
    printf(BOLD MAGENTA "+============================+\n\n" RESET);
}
int main()
{
    srand(time(NULL));
    printf(RED "+================================================================+\n" RESET);
    printf(BOLD GREEN "                       Hand Cricket\n" RESET);
    printf(RED "+================================================================+\n\n" RESET);
    int choice;
    printf(YELLOW "IIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n" RESET);
    printf(BOLD MAGENTA "          TOSS TIME          \n" RESET);
    printf(YELLOW "IIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n\n" RESET);
    printf(CYAN "Enter your choice (1. EVEN or 2. ODD):\n" RESET);
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        printf(BOLD CYAN "Enter 1 for EVEN or 2 for ODD: " RESET);
        while (getchar() != '\n')
            ;
    }
    if (choice == 1)
    {
        printf(GREEN "Your choice is EVEN\n" RESET);
        printf("\n");
        printf(BLUE "Computer choice is ODD\n" RESET);
    }
    else
    {
        printf(GREEN "Your choice is ODD\n" RESET);
        printf("\n");
        printf(BLUE "Computer choice is EVEN\n" RESET);
    }
    int user;
    printf(BOLD CYAN "==>> FOR USER <<==\n" RESET);
    printf(CYAN "Enter a number within range (1-6): " RESET);
    while (scanf("%d", &user) != 1 || user > 6 || user < 1)
    {
        printf(BOLD CYAN "Enter a number within range (1-6): " RESET);
        while (getchar() != '\n')
            ;
    }
    printf(BOLD BLUE "==>> FOR COMPUTER <<==\n" RESET);
    int min = 1;
    int max = 6;
    int comp = (rand() % (max - min + 1)) + min;
    printf(BLUE "Computer number: %d\n" RESET, comp);
    int num = user + comp;
    printf("\n");
    if ((choice == 1 && num % 2 == 0) || (choice == 2 && num % 2 != 0))
    {
        int choice1;
        printf(BOLD GREEN "You won the toss!\n" RESET);
        printf(BOLD MAGENTA "===>> What you choose: <<===\n" RESET);
        printf(YELLOW "    _________\n");
        printf("1. | Batting |\n");
        printf("    _________\n");
        printf("2. | Bowling |\n" RESET);
        while (scanf("%d", &choice1) != 1 || (choice1 != 1 && choice1 != 2))
        {
            printf(BOLD CYAN "Enter 1 for Batting or 2 for Bowling: " RESET);
            while (getchar() != '\n')
                ;
        }
        if (choice1 == 1)
        {
            int score = 0, runs, comp_runs;
            printf(BOLD MAGENTA "FIRST INNINGS: USER BATTING\n" RESET);
            do
            {
                runs = valid_runs();

                comp_runs = (rand() % (max - min + 1)) + min;

                printf(BLUE "Computer runs: %d\n" RESET, comp_runs);

                if (runs != comp_runs)
                {
                    score = score + runs;
                }
                else
                {
                    printf(BOLD RED "OUT!\n" RESET);
                }

            } while (runs != comp_runs);
            printf(BOLD YELLOW "==========================\n" RESET);
            printf(BOLD YELLOW "Your score is %d\n" RESET, score);
            printf(BOLD YELLOW "==========================\n\n" RESET);
            printf(BLUE "Computer is bowling\n" RESET);
            int comp_score = 0;
            printf(BOLD MAGENTA "SECOND INNINGS: COMPUTER BATTING\n" RESET);
            do
            {
                comp_runs = (rand() % (max - min + 1)) + min;
                printf(BLUE "Computer runs: %d\n" RESET, comp_runs);
                runs = valid_runs();
                if (runs != comp_runs)
                {
                    comp_score = comp_score + comp_runs;

                    if (comp_score > score)
                        break;
                }
                else
                {
                    printf(BOLD RED "OUT!\n" RESET);
                }

            } while (runs != comp_runs && comp_score <= score);
            printf(BOLD YELLOW "==========================\n" RESET);
            printf(BOLD YELLOW "Computer score is %d\n" RESET, comp_score);
            printf(BOLD YELLOW "==========================\n\n" RESET);
            final_result(score, comp_score);
        }

        else if (choice1 == 2)
        {
            int comp_score = 0, runs, comp_runs;
            printf(BOLD MAGENTA "FIRST INNINGS: COMPUTER BATTING\n" RESET);
            do
            {
                comp_runs = (rand() % (max - min + 1)) + min;
                printf(BLUE "Computer runs: %d\n" RESET, comp_runs);
                printf(CYAN "Enter runs (1-6):\n" RESET);
                runs = valid_runs();
                if (runs != comp_runs)
                {
                    comp_score = comp_score + comp_runs;
                }
                else
                {
                    printf(BOLD RED "OUT!\n" RESET);
                }

            } while (runs != comp_runs);
            printf(BOLD YELLOW "==========================\n" RESET);
            printf(BOLD YELLOW "Computer score is %d\n" RESET, comp_score);
            printf(BOLD YELLOW "==========================\n\n" RESET);
            printf(BLUE "User is bowling:\n\n" RESET);
            int score = 0;
            printf(BOLD MAGENTA "SECOND INNINGS: USER BATTING\n" RESET);
            do
            {
                runs = valid_runs();

                comp_runs = (rand() % (max - min + 1)) + min;

                printf(BLUE "Computer runs: %d\n" RESET, comp_runs);

                if (runs != comp_runs)
                {
                    score = score + runs;
                    if (score > comp_score)
                        break;
                }
                else
                {
                    printf(BOLD RED "OUT!\n" RESET);
                }

            } while (runs != comp_runs && score <= comp_score);

            printf(BOLD YELLOW "==========================\n" RESET);
            printf(BOLD YELLOW "Your score is %d\n" RESET, score);
            printf(BOLD YELLOW "==========================\n\n" RESET);
            final_result(score, comp_score);
        }
    }
    else
    {
        int choice1;
        printf(BOLD RED "Computer won the toss!\n" RESET);
        choice1 = (rand() % 2) + 1;
        if (choice1 == 1)
        {
            printf(BLUE "Computer chooses Batting\n" RESET);
            int comp_score = 0, runs, comp_runs;
            printf(BOLD MAGENTA "FIRST INNINGS: COMPUTER IS BATTING\n" RESET);
            do
            {
                comp_runs = (rand() % (max - min + 1)) + min;

                printf(BLUE "Computer runs: %d\n" RESET, comp_runs);
                printf(CYAN "Enter runs (1-6):\n" RESET);
                runs = valid_runs();
                if (runs != comp_runs)
                {
                    comp_score = comp_score + comp_runs;
                }
                else
                {
                    printf(BOLD RED "OUT!\n" RESET);
                }

            } while (runs != comp_runs);
            printf(BOLD YELLOW "==========================\n" RESET);
            printf(BOLD YELLOW "Computer score is %d\n" RESET, comp_score);
            printf(BOLD YELLOW "==========================\n\n" RESET);
            printf(BLUE "User is bowling:\n\n" RESET);
            int score = 0;
            printf(BOLD MAGENTA "SECOND INNINGS: USER BATTING\n" RESET);
            do
            {
                runs = valid_runs();
                comp_runs = (rand() % (max - min + 1)) + min;
                printf(BLUE "Computer runs: %d\n" RESET, comp_runs);
                if (runs != comp_runs)
                {
                    score = score + runs;
                    if (score > comp_score)
                        break;
                }
                else
                {
                    printf(BOLD RED "OUT!\n" RESET);
                }

            } while (runs != comp_runs && score <= comp_score);
            printf(BOLD YELLOW "==========================\n" RESET);
            printf(BOLD YELLOW "Your score is %d\n" RESET, score);
            printf(BOLD YELLOW "==========================\n\n" RESET);
            final_result(score, comp_score);
        }
        else if (choice1 == 2)
        {
            printf(BLUE "Computer chooses Bowling\n" RESET);
            int score = 0, runs, comp_runs;
            printf(BOLD MAGENTA "FIRST INNINGS: USER BATTING\n" RESET);
            do
            {
                runs = valid_runs();
                comp_runs = (rand() % (max - min + 1)) + min;
                printf(BLUE "Computer runs: %d\n" RESET, comp_runs);
                if (runs != comp_runs)
                {
                    score = score + runs;
                }
                else
                {
                    printf(BOLD RED "OUT!\n" RESET);
                }

            } while (runs != comp_runs);
            printf(BOLD YELLOW "==========================\n" RESET);
            printf(BOLD YELLOW "Your score is %d\n" RESET, score);
            printf(BOLD YELLOW "==========================\n\n" RESET);
            printf(BLUE "Computer is batting:\n\n" RESET);
            int comp_score = 0;
            printf(BOLD MAGENTA "SECOND INNINGS: COMPUTER IS BATTING\n" RESET);
            do
            {
                comp_runs = (rand() % (max - min + 1)) + min;
                printf(BLUE "Computer runs: %d\n" RESET, comp_runs);
                runs = valid_runs();
                if (runs != comp_runs)
                {
                    comp_score = comp_score + comp_runs;
                    if (comp_score > score)
                        break;
                }
                else
                {
                    printf(BOLD RED "OUT!\n" RESET);
                }
            } while (runs != comp_runs && comp_score <= score);
            printf(BOLD YELLOW "==========================\n" RESET);
            printf(BOLD YELLOW "Computer score is %d\n" RESET, comp_score);
            printf(BOLD YELLOW "==========================\n\n" RESET);
            final_result(score, comp_score);
        }
    }
    return 0;
}
