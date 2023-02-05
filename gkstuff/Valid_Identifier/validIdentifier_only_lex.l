
%{
  #include<stdio.h>
%}

identifier [a-zA-Z_][a-zA-Z0-9]* 

%%
{identifier} {printf("%s is a valid identifier\n", yytext);}
.* {printf("%s invalid identifier\n", yytext);}
%%

int main(){
  yylex();
  return 0;
}

int yywrap(){
  return 1;
}