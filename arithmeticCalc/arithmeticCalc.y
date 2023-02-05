%{
  isValid = 1;
  #include<stdio.h>
%}

%token digit
%%
start: E { printf("%d\n", $1); }
;
E: E '+' T { $$ = $1 + $3; }
| E '-' T { $$ = $1 - $3; }
|T
;
T: T '*' F { $$ = $1 * $3; }
| T '/' F{ if($3) $$ = $1 / $3;
            else return yyerror("Divide by zero"); }
|F
;
F: '(' E ')' { $$ = $2; }
| digit { $$ = $1; }
;
%%

int yyerror(char *msg){
  isValid = 0;
  printf("Error: %s\n", msg);
}

int main(){
  printf("enter expression: ");
  yyparse();
  if(isValid){
    printf("valid expression");
  }else{
    printf("invalid");
  }
}