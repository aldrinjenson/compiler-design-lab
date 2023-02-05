%{
  #include<stdio.h>
  int isValid = 1;
%}

%token DIGIT

%%
start: E { printf("Result = %d\n", $1); }
;
E : E '+' T  {$$ = $1 + $3;}
  | E '-' T  {$$ = $1 - $3;}
  | T        {$$ = $1;}
;

T : T '*' F {$$ = $1 * $3;}
  | T '/' F { if ($3) $$ = $1 / $3; else printf("Division by zero error!"); return 0;} 
  | F       {$$ = $1;}

F : '(' F ')' {$$ = $2;}
  | '-' F     {$$ = -$2;}
  | DIGIT     {$$ = $1;}
%%


int yyerror(char *msg){
  isValid = 0;
  printf("Error: %s", msg);
}

int main(){
  printf("Enter expression: ");
  yyparse();
  if (isValid);
    // printf("valid expression");
  else 
    printf("invalid");
}