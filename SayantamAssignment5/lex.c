#include "lex.h"

token_t token;

void getNextToken()
{	char ch;
    if((ch = getc(stdin)) != EOF)
    {	if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
            getNextToken();
		else if('0' <= ch && ch <= '9')
        {	int num = ch - '0';
            while((ch = getc(stdin)) != EOF && '0' <= ch && ch <= '9')
            {	num *= 10;
                num += (ch - '0');
            }
            ungetc(ch, stdin);
            token.tokenClass = NUM;
            token.val = num;
        }
        else if( (('A' <= ch && ch <= 'Z') || ( 'a' <= ch && ch <= 'z' )) && ch != 'r' )
        {
            token.tokenClass = ID;
            token.val = (int)ch;
        }
        else
        {	token.tokenClass = ch;
            token.val = -1;
        }
    }
    else
    {	
        token.tokenClass = END;
        token.val = -1;
    }
}