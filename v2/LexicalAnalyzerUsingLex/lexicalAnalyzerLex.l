%{
int isComment = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%
#.* printf("%s, is a preprocessor\n", yytext);
int|struct|break|continue|float|do|if|else {printf("%s is a keyword\n", yytext);}
"/*" {isComment = 1;}{ printf("%s is a comment\n", yytext);}
"*/" {isComment = 0;}{ printf("%s is comment ending\n", yytext);}
{identifier}\( {if (!isComment) printf("%s is a \nFunction \n", yytext);}
{identifier} {if (!isComment) printf("%s is an identifier \n", yytext);}
= printf("= is Assignment operator\n");
\<=|\>=|==|"<"|">" printf("%s is a RELATIONAL operator\n", yytext);

[0-9]+ printf("%s is a number\n", yytext);

"{" printf("%s Block begins\n", yytext);
"}" printf("%s Block ends\n", yytext);
.|\n {printf("");}

%%

int main(){
  printf("Hey there\n");
  FILE *fp = fopen("program.txt", "r");
  if (!fp){
    printf("Error in opening file..");
    exit(0);
  }

  yyin=fp;
  yylex();

  printf("\n");
  return 0;
}

int yywrap(){
  return 1;
}



