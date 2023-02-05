#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int isKeyword(char buf[])
{

  char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                           "do", "double", "else", "enum", "extern", "float", "for", "goto",
                           "if", "int", "long", "register", "return", "short", "signed",
                           "sizeof", "static", "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while"};

  for (int i = 0; i < 32; i++)
  {
    if (strcmp(keywords[i], buf) == 0)
      return 1;
  }
  return 0;
}

char operators[6] = "+-/%=*";

int main()
{
  FILE *fp = fopen("program.txt", "r");
  if (fp == NULL)
  {
    printf("Error in opening file\nExiting..");
    exit(0);
  }

  char c, buffer[30];
  int i = 0, bufferPtr = 0;

  while ((c = fgetc(fp)) != EOF)
  {
    for (i = 0; i < strlen(operators); i++)
    {
      if (c == operators[i])
        printf("%c is an operator\n", c);
    }

    if (isalnum(c))
      buffer[bufferPtr++] = c;

    else if ((c == ' ' || c == '\t' || c == '\n'))
    {
      buffer[bufferPtr] = '\0';
      bufferPtr = 0;

      if (strlen(buffer) == 0)
        continue;

      if (isKeyword(buffer))
        printf("%s is a keyword\n", buffer);
      else
        printf("%s is an identifier\n", buffer);
    }
  }
  fclose(fp);
  return 0;
}