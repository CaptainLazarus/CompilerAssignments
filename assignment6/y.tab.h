#ifndef _Y_TAB_H
#define _Y_TAB_H
#define IF 300
#define ELSE 301
#define WHILE 302
#define READ 303
#define INT 304
#define ID 305
#define NUM 306
#define STRNG 307
#define BIN_OP 308
#define UN_OP 309
#define FLOAT 310
#define DO 311
#define NOP 312
#define PRINT 313
#define REAL 314
#define THEN 315

int yylex(void);

typedef union {
    char *string;
    int integer;
    float fraction;
} yylType;

#endif