objfiles = myLex.o lex.yy.o
a.out : $(objfiles)
	c++ $(objfiles)
myLex.o : myLex.cpp y.tab.h
	c++ -c -Wall myLex.cpp
lex.yy.o : lex.yy.c
	c++ -c lex.yy.c
lex.yy.c: lex.l y.tab.h
	flex lex.l
clean : 
	rm a.out lex.yy.c $(objfiles)