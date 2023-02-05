%{
  #include"y.tab.h"
%}

%%
[a-zA-Z_] return letter;
[0-9] return digit;
\n return 0;
. return yytext[0];
%%


int yywrap(){
  return 1;
}