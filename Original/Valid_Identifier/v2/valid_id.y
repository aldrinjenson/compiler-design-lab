%{
  #include<stdio.h>
  int isValid=1;
%}

%token letter digit

%%
start: letter s
s    : letter s | digit s | ;
%%

int yyerror(char *msg){
  isValid=0;
  printf("%s\n", msg);
  return 0;
}

int main(){
  printf("Enter name to be tested for identifier names\n");
  yyparse();
  if(isValid==1){
   printf("Valid identifier");
  }else{
   printf("Invalid identifier");
  }
  return 0;
}