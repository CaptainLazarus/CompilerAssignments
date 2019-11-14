%{
#include<stdio.h>
#define OK 1
#define ERR 0
#define UNDEF -1

int S();
int E();
int F();
int H();

int token = UNDEF;

%}

%option noyywrap

FC [0-9]*\.[0-9]+

%%
"\n"    {return (int)'\n' ; }
"+"     {return (int)'+'; }
"*"     {return (int)'*'; }
{FC}    {return FC; }
[ \t]   {;}
.       {return ERR; }

%%