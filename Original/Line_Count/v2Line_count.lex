%{
int numLines=0, numChars = 0, numWords=0;
%}

%%
\n {numLines++;numWords++;}
\t|" " numWords++;
. numChars++;
".q" {printf("quitting\nNumLines=%d,numWords=%d,numChars=%d\n", numLines, numWords, numChars);return 0;}
%%

int main(){
  printf("Line, word and character counter\n");
  yylex();
  printf("\n");
  return 0;
}

int yywrap(){
  return 1;
}

