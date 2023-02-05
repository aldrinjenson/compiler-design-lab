#include <stdio.h>
#include <string.h>

char result[20][20], copy[3], states[20][20];

void add_state(char a[3], int i)
{
    strcpy(result[i], a);
}

void display(int n, char *currState)
{
    int k = 0;
    printf("\nEpsilon closure of %s = {", currState);
    while (k < n)
    {
        printf(" %s", result[k++]);
    }
    printf(" } \n");
}

int main()
{
    FILE *INPUT;
    INPUT = fopen("input.txt", "r");
    char currState[3];
    int end, i = 0, n, k = 0;
    char state1[3], input[3], state2[3];
    printf("\nEnter the no of states: ");
    scanf("%d", &n);
    printf("\nEnter the states:");
    for (k = 0; k < 3; k++)
        scanf("%s", states[k]);

    for (k = 0; k < n; k++)
    {
        i = 0;
        strcpy(currState, states[k]);
        add_state(currState, i++);
        while ((end = fscanf(INPUT, "%s%s%s", state1, input, state2)) != EOF)
        {
            printf("currState = %s; state2=%s\n", currState, state2);
            if (strcmp(currState, state1) == 0)
            {
                printf("Inside\n");
                if (strcmp(input, "e") == 0)
                {
                    add_state(state2, i++);
                    strcpy(currState, state2);
                }
            }
        }
        display(i, currState);
        rewind(INPUT);
    }
    return 0;
}