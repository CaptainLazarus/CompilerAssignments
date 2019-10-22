//#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "y.tab.h"
extern yylType yylval;
// FILE *yyin;
int  main() // myLex.c++
{
     int s;
     freopen("input", "r", stdin);
     // yyin = fopen("input.c", "r");
     while((s=yylex()))
     switch(s) {
          case '\n': cout << "\n";
                    break;
          case '(' : cout << "<(> ";
                    break;
          case ')' : cout << "<)> ";
                    break;
          case '{' : cout << "<{> ";
                    break;
          case '}' : cout << "<}> ";
                    break;
          case ';' : cout << "<;> ";
                    break;
          case ',' : cout << "<,> ";
                    break;
          case '=' : cout << "<=> ";
                    break;
          case '<' : cout << "<<> ";
                    break;
          case UN_OP : cout << "<UN_OP," << (char) yylval.integer << "> "; 
                    break;
          case BIN_OP : cout << "<BIN_OP," << (char) yylval.integer << "> "; 
                    break;
          case IF  : cout << "<if> ";
                    break; 
          case ELSE : cout << "<else> ";
                    break;
          case WHILE : cout << "<while> "; 
                    break;
          case INT : cout << "<int> ";
                    break;
          case REAL :    cout << "<real> ";
                    break;
          case DO :    cout << "<do> ";
                    break;
          case ID  : cout << "<ID," << yylval.string << "> ";
                    free (yylval.string);
                    break;
          case FLOAT  : cout << "<FLOAT," << yylval.fraction << "> ";
                    break;
          case NUM : cout << "<NUM," << yylval.integer << "> ";
                    break;
          case STRNG : cout << "<STRNG," << yylval.string << "> ";
                    free (yylval.string) ;
                    break;
          default:  ;
     }
     return 0;
}
