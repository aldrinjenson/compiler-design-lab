%{
  #include<stdio.h>
  int isValid = 1;
%}

%token letter digit

%%
start  : letter s
s      : letter s | digit s | ;
%%

int yyerror(char *msg){
  isValid = 0;
  printf("%s", msg);
  return 0;
}

int main(){
  printf("Enter identifier: ");
  yyparse();
  if(isValid){
    printf("is valid");
  }else{
    printf("invalid");
  }
  return 0;
}