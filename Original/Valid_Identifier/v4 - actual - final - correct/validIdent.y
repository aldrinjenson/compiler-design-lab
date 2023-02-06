%{
  #include<stdio.h>
  int isValid = 1;
%}

%token letter digit

%%
start : letter S
S     : letter S | digit S | ;
%%

int yyerror(char *msg){
  isValid = 0;
  // printf("%s", msg);
}

int main(){
  printf("Enter identifier: ");
  yyparse();
  if (isValid)
    printf("Valid identifier");
  else
    printf("inValid ");
  return 0;
}