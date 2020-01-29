%{
    #include<iostream>
    #include<cstdlib>
    #include<cstdio>
    #include "bison.tab.h++"
    using namespace std;
%}
%option noyywrap
%option yylineno

%%
\/\/.                                  ;
[ \t\n]                                ;
[0-9]+                                 {yylval.ic = atoi(yytext); return ic_token;}
[0-9]*\.[0-9]+|[0-9]+\.[0-9]*          {yylval.fc = atof(yytext); return fc_token;}
\"[a-zA-Z0-9]+\"                       {yylval.str = strdup(yytext); return str_token;}

"if"                    {return if_token;}
"then"                  {return then_token;}
"else"                  {return else_token;}
"int"                   {return int_token;}
"real"                  {return real_token;}
"do"                    {return do_token;}
"print"                 {return print_token;}
"read"                  {return read_token;}
"while"                 {return while_token;}

[a-zA-Z][a-zA-Z0-9]*    {yylval.str = strdup(yytext); return id_token;}

"+"                     {return (int)'+';}
"-"                     {return minus_token;}
"*"                     {return mult_token;}
"/"                     {return div_token;}
"=="                    {return eq_token;}
"("                     {return lbrac_token;}
")"                     {return rbrac_token;}
"<"                     {return less_token;}
">"                     {return greater_token;}
"="                     {return assign_token;}
";"                     {return semicolon_token;}
":"                     {return colon_token;}
"&"                     {return and_token;}
"|"                     {return or_token;}
"~"                     {return not_token;}
%%

