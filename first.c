#include <stdio.h>
#include <string.h>

char baseRules[10][10] = {
		"E->aE+T|T",
		"T->T*F|F",
		"F->(E)|id",
};

char *terminals = "a+*()i";
char *nonTerminals = "ETF";
char newProductionRules[10][10];
int numNewProductions;

void printProductions(char rules[10][10], int length)
{
	for (int i = 0; i < length; i++)
		printf("%s\n", rules[i]);
}

int isTerminal(char ch)
{
	for (int i = 0; i < strlen(terminals); i++)
	{
		if (terminals[i] == ch)
			return 1;
	}
	return 0;
}

void printTerminal(char ch)
{
	if (ch == 'i')
		printf("id");
	else
		printf("%c,", ch);
}

void getFirst(char nt)
{
	for (int i = 0; i < numNewProductions; i++)
	{
		char *rule = newProductionRules[i];
		if (rule[0] != nt)
			continue;
		for (int j = 3; j < strlen(rule); j++)
		{
			char ch = rule[j];

			if (!isTerminal(ch) && strlen(rule) - 1 != j)
				break;

			if (isTerminal(ch))
			{
				printTerminal(ch);
				break;
			}
			else
			{
				getFirst(ch);
			}
		}
	}
}

char startSymbol = 'E';

void getFollow(char nt)
{
	if (newProductionRules[0][0] == nt) // start symbol
	{
		printf("$");
	}
	for (int i = 0; i < numNewProductions; i++)
	{
		char *rule = newProductionRules[i];

		for (int j = 3; j < strlen(rule); j++)
		{
			char ch = rule[j];
			if (ch != nt)
				continue;
			{
				if (j == strlen(rule) - 1 && !isTerminal(ch)) // reaches epsilon
				{
					getFollow(rule[0]);
				}
				else
				{
					if (isTerminal(rule[j + 1]))
					{
						printTerminal(rule[j + 1]);
					}
					else
					{
						if (rule[j + 1] != startSymbol)
							getFirst(rule[j + 1]);
					}
				}
			}
		}
	}
}

void splitProductions()
{
	numNewProductions = 0;
	for (int i = 0; i < 3; i++, numNewProductions++)
	{
		char *rule = baseRules[i];
		char *newRule = "";
		int newProductionKaLengthCounter = 0;
		for (int j = 0; j < strlen(rule); j++)
		{
			char ch = rule[j];
			if (ch == '|')
			{
				numNewProductions++;
				newProductionRules[numNewProductions][0] = rule[0];
				newProductionRules[numNewProductions][1] = '-';
				newProductionRules[numNewProductions][2] = '>';
				newProductionKaLengthCounter = 3;
				continue;
			}
			newProductionRules[numNewProductions][newProductionKaLengthCounter++] = ch;
		}
	}
}

int main()
{
	printf("\nThe production rules are:\n");
	printProductions(baseRules, 3);
	printf("\nSplitting production rules..\n");
	splitProductions();
	printf("\nModified production rules:\n");
	printProductions(newProductionRules, numNewProductions);
	printf("\nCalculating Firsts\n");
	for (int i = 0; i < 3; i++)
	{
		char nt = nonTerminals[i];
		printf("First(%c) = { ", nt);
		getFirst(nt);
		printf(" }\n");
	}

	printf("\nCalculating Follow\n");
	for (int i = 0; i < 3; i++)
	{
		char nt = nonTerminals[i];
		printf("Follow(%c) = { ", nt);
		getFollow(nt);
		printf(" }\n");
	}
}
