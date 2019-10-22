flex lex.l
c++ -c lex.yy.c
c++ -c myLex.cpp
c++ myLex.o lex.yy.o
./a.out