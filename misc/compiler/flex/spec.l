%{
    int numChars = 0, numWords = 0 , numLines = 0;
%}

%%

[0-9]* {printf("digits %s\n",yytext);}
\n  {numLines++; numChars++;}
[^ \t\n]+   {numWords++; numChars += yyleng;
                printf("%s \n",yytext);        
}

%%
    
int main(){
    yylex();
    printf("%d\t%d\t%d\n",numChars,numWords,numLines);
}
