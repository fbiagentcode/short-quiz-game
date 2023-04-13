#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int *questions()
{
    int *array = malloc(3*sizeof(int));
    int count = 3;
    int index = 0;
    while(count > 0)
    {
        bool exists = false;
        int qno = rand() % 3;
        for (int i = 0; i < 3; i++)
        {
            if (array[i] == qno)
            {
                exists = true;
                break;
            }
        }
        if(!exists)
        {
            array[index] = qno;
            index++;
            count--;
        }

    }
    return array;
}

int main()
{
    int correct;
    char option, playAgain;
    bool reward;
    srand(time(NULL));
    
    int *qORDER = questions();
    printf("\t\tQUIZ GAME\t\t\n\t\tANSWER ALL THREE RIGHT TO WIN A FREE COOKIE!");
    while(true)
    {
        reward = false;
        correct = 0;
        for(int i = 1; i<=3; i++, qORDER++)
        {
        if(*qORDER == 0)
            {
        
                printf("\n\nWhat is Obama\'s last name?");
                printf("\nA) joe mama\tB) dookie");
                printf("\nC) dookie\tD) nick\n");
                scanf(" %c", &option);
                
                    if (toupper(option) == 'A')
                    {
                        correct++;
                        printf("\nCORRECT.");
                    }
                    else printf("\nINCORRECT. The answer was A) joe mama");
            }
        

        if(*qORDER == 1)
            {
            printf("\n\nWho was in Paris?");
            printf("\nA) Brothas\tB) Partnas");
            printf("\nC) Fellas\tD) Distinguished gentlemen of african descent\n");
            scanf(" %c", &option);
            
                if (toupper(option) == 'D')
                {
                    printf("CORRECT.");
                    correct++;
                }
                else printf("\nINCORRECT. The answer was D)  Distinguished gentlemen of african descent");
            }
        

        if(*qORDER == 2)
            {
            printf("\n\nMitochondria is");
            printf("\nA) a type of food\tB) place in Paris");
            printf("\nC) the powerhouse of the cell\t D) a disease\n");
            scanf(" %c", &option);
                if (toupper(option) == 'C')
                {
                    printf("\nCORRECT.");
                    correct++;
                }
                else 
                {
                    printf("\nINCORRECT. The answer was");
                    printf("\nC) the powerhouse of the cell");
                }
            }
    }
    if (correct == 3) reward = true;
    printf("\n****************************************");
    printf("\n\tEND OF QUIZ.");
    printf("\n\tGUESSED CORRECT - %d", correct);
    if (reward) printf("\nCONGRATS YOU GET A FREE COOKIE!");
    printf("\n\tPlay Again? Enter Y for YES, N for NO.\n");
    scanf(" %c", &playAgain);
    if (toupper(playAgain) == 'N')
    break;
    else qORDER = questions();

    }
    printf("Thanks for playing.");
    
}
