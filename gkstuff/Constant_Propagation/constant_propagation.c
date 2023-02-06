#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void input();
void output();
void change(int p, char *result);
void constant();

struct expr
{
    char operator[2], operand1[5], operand2[5], result[5];
    int flag;
} arr[10];

int n;

void main()
{
    input();
    constant();
    output();
    getchar();
}

void input()
{
    int i;
    printf("Enter the maximum number of expressions : ");
    scanf("%d", &n);
    printf("\nEnter the input : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i].operator);
        scanf("%s", arr[i].operand1);
        scanf("%s", arr[i].operand2);
        scanf("%s", arr[i].result);
        arr[i].flag = 0;
    }
}

void constant()
{
    int i;
    int operand1, operand2, result;
    char operator, res1[5];
    for (i = 0; i < n; i++)
    {
        if (isdigit(arr[i].operand1[0]) && isdigit(arr[i].operand2[0]) || strcmp(arr[i].operator, "=") == 0) /*if both digits,
            store them in variables*/
        {
            operand1 = atoi(arr[i].operand1);
            operand2 = atoi(arr[i].operand2);
            operator= arr[i].operator[0];
            switch (operator)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '=':
                result = operand1;
                break;
            }
            sprintf(res1, "%d", result);
            arr[i].flag = 1; /*eliminate expr and replace any operand below that uses result of this expr */
            change(i, res1);
        }
    }
}

void output()
{
    int i = 0;
    printf("\nOptimized code is : ");
    for (i = 0; i < n; i++)
    {
        if (!arr[i].flag)
        {
            printf("\n%s %s %s %s", arr[i].operator, arr[i].operand1, arr[i].operand2, arr[i].result);
        }
    }
}

void change(int p, char *result)
{
    for (int i = p + 1; i < n; i++)
    {
        if (strcmp(arr[p].result, arr[i].operand1) == 0)
            strcpy(arr[i].operand1, result);
        else if (strcmp(arr[p].result, arr[i].operand2) == 0)
            strcpy(arr[i].operand2, result);
    }
}