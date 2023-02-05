%{
  isValid = 1;
  #include<stdio.h>
%}

%token digit
%%
start: E { printf("Valid"); }
;
E: E '+' T 
| E '-' T 
|T
;
T: T '*' F 
| T '/' F
|F
;
F: '(' E ')' 
| digit
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