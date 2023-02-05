%{

%}

%%
".q" {printf ("Quitting..\n"); return 0;}
abc {printf("ABC");}
%%


int main(){
  yylex();
}

int yywrap(){
  printf("exiting..");
  return 1;
}