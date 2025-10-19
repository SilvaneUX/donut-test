#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int getRandomNumber();

char compChoice(int n);

void checkLogic(char, int *, char, int *);

void startGame(char name[]);

void rules();

int main()
{
    char *name;
    name = (char *)malloc(20 * sizeof(char));
    char ch = 'y';
    while (ch == 'y')
    {
        printf("\n....Welcome to Rock - Paper - Scissors game.....\n");

        printf("Enter your name: ");
        fgets(name, 20, stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove trailing newline character
        srand(time(NULL));
        
        startGame(name);

        printf("\nDo you want to play again?[y/n]: ");
        scanf_s("%c", &ch);
        getchar();
        ch = tolower(ch);
        if (ch != 'y')
        {
            printf("\nThank you for playing ");
            free(name);
            exit(0);
        }
    }

    free(name);
    return 0;
}

int getRandomNumber()
{
    return (rand() % 3);
}

char compChoice(int n)
{
    switch (n)
    {
    case 0: printf("Rock"); return ('r');break;
    case 1: printf("Paper"); return ('p');break;
    case 2: printf("Scissor"); return ('s');break;
    default: return ('r'); // Default case to avoid undefined behavior
    }
}

void rules()
{
    printf("\nEnter 'r' for Rock\n");
    printf("Enter 'p' for Paper\n");
    printf("Enter 's' for Scissor\n");
    return;
}

void startGame(char name[])
{
    int noOfGame, compTurn;
    int userChoice;
    int winingPoints; 
    char myChoice;
    char computerChoice;
    int myPoint = 0, computerPoint = 0;

    printf("\n...Which way do you want to play...\n\n");
    printf("1. Limit the no of games\n");
    printf("2. Limit the winning point\n");
    printf("Enter your choice: ");
    scanf_s("%d", &userChoice);
    if (userChoice < 1 || userChoice > 2)
    {
        printf("I hope you know what to enter");
        exit(2);
    }

    switch (userChoice)
    {
    case 1:
    again:
        printf("How many times do you want to play the game: ");
        scanf_s("%d", &noOfGame);
        getchar(); // Clear the newline character left by scanf_s

        rules();

        // check if the user enter a valid input for game or not
        if (noOfGame > 0)
        {

            // continues the game till end
            while (noOfGame != 0)
            {
                printf("\n%s's turn: ", name);
                scanf_s("%c", &myChoice);
                getchar();

                compTurn = getRandomNumber();
                printf("Computer Turn: ");
                computerChoice = compChoice(compTurn);
                checkLogic(myChoice, &myPoint, computerChoice, &computerPoint);
                printf("\n%s's Score: %d\t", name, myPoint);
                printf("Computer Score: %d\n", computerPoint);
                noOfGame = noOfGame - 1;
            }

            if (myPoint > computerPoint)
            {
                printf("%s wins this game\n", name);
            }
            else if (computerPoint > myPoint)
            {
                printf("Computer wins this game\n");
            }

            else if (myPoint == computerPoint)
            {
                printf("This is a tie\n");
            }
        }

        else if (noOfGame < 0)
        {
            printf("Please enter a valid input\n");
            goto again;
        }
        break;

    case 2:
        myPoint = 0, computerPoint = 0;
        printf("Enter the winning points: ");
        scanf_s("%d", &winingPoints);
        getchar(); // Clear the newline character left by scanf_s

        rules();
        // check if the user enter a valid input for game or not
        if (winingPoints > 0)
        {
            // continues the game till end
            while (1)
            {
                if (myPoint == winingPoints || computerPoint == winingPoints)
                {

                    if (myPoint > computerPoint)
                    {
                        printf("Congratulations %s you win this game\n", name);
                        break;
                    }
                    else if (computerPoint > myPoint)
                    {
                        printf("Computer wins this game\n");
                        break;
                    }
                }
                printf("\n%s's turn: ", name);
                scanf_s("%c", &myChoice);
                getchar();
                compTurn = getRandomNumber();
                printf("Computer Turn: ");
                computerChoice = compChoice(compTurn);
                checkLogic(myChoice, &myPoint, computerChoice, &computerPoint);
                printf("\n%s's Score: %d\t", name, myPoint);
                printf("Computer Score: %d\n", computerPoint);
            }
        }

        else if (noOfGame < 0)
        {
            printf("Please enter a valid input\n");
            goto again;
        }
        break;
    default:
        printf("!! I hope you knew what to enter !!");
        exit(3);
        break;
    }
}

void checkLogic(char myChoice, int *myPoint, char computerChoice, int *computerPoint)
{
    if (myChoice == 'r' || myChoice == 'p' || myChoice == 's')
    {
        // implementing the logic
        if (myChoice == computerChoice)
        {
            printf("\nIt's a tie!\n");
        }
        else if (myChoice == 'r')
        {
            if (computerChoice == 'p')
            {
                printf("\nComputer wins this round!\n");
                (*computerPoint)++;
            }
            else if (computerChoice == 's')
            {
                printf("\nYou win this round!\n");
                (*myPoint)++;
            }
        }

        else if (myChoice == 'p')
        {
            if (computerChoice == 'r')
            {
                printf("\nYou win this round!\n");
                (*myPoint)++;
            }
            else if (computerChoice == 's')
            {
                printf("\nComputer wins this round!\n");
                (*computerPoint)++;
            }
        }

        else if (myChoice == 's')
        {
            if (computerChoice == 'r')
            {
                printf("\nComputer wins this round!\n");
                (*computerPoint)++;
            }
            else if (computerChoice == 'p')
            {
                printf("\nYou win this round!\n");
                (*myPoint)++;
            }
        }
    }
    else
    {
        printf("\nI hope you know the rules....\n");
        // exit(1);
    }

    return;
}
