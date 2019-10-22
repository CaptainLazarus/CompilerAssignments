/* A scanner for a toy language: 
   ./lex_yacc/lex.l 
*/

%{ // Copied verbatim

#include <string.h>
#include <stdlib.h>
#include "y.tab.h"  // tokens are defined 
int line_count = 0; 
yylType yylval;     
 
%}

%option noyywrap
%x CMNT INSTR            

DELIM      ([ \t])
WHITESPACES ({DELIM}+)
POSI_DECI   ([1-9])
DECI    (0|{POSI_DECI})
DECIMAL    (0|{POSI_DECI}{DECI}*)
LOWER      ([a-z])
LETTER     ({LOWER}|[:upper:]|_)
IDENTIFIER ({LETTER}({LETTER}|{DECI})*)

/*Defined Separately*/
FRACTION ({DECIMAL}[\.]{DECIMAL}*)
NEGDEC (-{DECIMAL})
NEGFRAC (-{FRACTION})

%%

"//"          {BEGIN CMNT;}
<CMNT>.       {;}
<CMNT>\n      {
                ++line_count;
                BEGIN INITIAL;
              }
\n            {
                ++line_count; 
                return (int)'\n';
              }
"\"".*"\""    {
                yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
                strncpy(yylval.string, yytext+1, yyleng-2);
                yylval.string[yyleng-2]='\0';
                return STRNG; 
              }
{WHITESPACES} { ; }
if            {return IF;}
else          {return ELSE; }
while         { return WHILE; }
int           { return INT; }
read          { return READ; }
print         { return PRINT; }
real          { return REAL; }
then          { return THEN; }
do            { return DO; }
nop           { return NOP; }

\(            { return (int)'('; }
\)            { return (int)')'; }
\{            { return (int)'{'; }
\}            { return (int)'}'; }
;             { return (int)';'; }
,             { return (int)','; }
"+"           { 
                yylval.integer = (int)'+'; 
                return BIN_OP;
              }
"*"           { 
                yylval.integer = (int)'*'; 
                return BIN_OP;
              }
"/"           { 
                yylval.integer = (int)'/'; 
                return BIN_OP;
              }
"=="          {
                yylval.integer = 1;
                return BIN_OP;
              }
"&"           {
                yylval.integer = (int)'&';
                return UN_OP;
              }
"|"           {
                yylval.integer = (int)'|';
                return UN_OP;
              }
"~"           {
                yylval.integer = (int)'~';
                return UN_OP;
              }
=             { return (int)'='; }
"<"           { return (int)'<'; }
">"           { return (int)'>'; }
{IDENTIFIER}  {
                yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
                strncpy(yylval.string, yytext, yyleng + 1);
                return ID; 
              }
{NEGFRAC}     {
                yylval.fraction = atof(yytext); 
                return FLOAT;
              }
{FRACTION}    {
                yylval.fraction = atof(yytext); 
                return FLOAT;
              }
{NEGDEC}      {
                yylval.fraction = atof(yytext); 
                return NUM;
              }
{DECIMAL}     { 
                yylval.integer = atoi(yytext); 
                return NUM; 
              }
"-"           { 
                yylval.integer = (int)'-'; 
                return BIN_OP;
              }

%%
/* The function yywrap()  */
//int yywrap(){return 1;}
