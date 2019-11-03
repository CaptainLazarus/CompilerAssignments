# objfiles = myLex.o lex.yy.o
# a.out : $(objfiles)
# 	c++ $(objfiles)
# myLex.o : myLex.cpp y.tab.h
# 	c++ -c -Wall myLex.cpp
# lex.yy.o : lex.yy.c
# 	c++ -c lex.yy.c
# lex.yy.c: lex.l y.tab.h
# 	flex lex.l
# clean : 
# 	rm a.out lex.yy.c $(objfiles)

src = 17009
objfiles = $(src).tab.o lex.yy.o
myparser : $(objfiles)
	c++ $(objfiles) -o myparser
$(src).tab.c++ : $(src).y++
	bison -d $(src).y++
lex.yy.c : $(src).l 17009.tab.h++
	flex $(src).l
$(src).tab.o: $(src).tab.c++ 17009.tab.h++
	c++ -Wall -c $(src).tab.c++
lex.yy.o : lex.yy.c
	c++ -Wall -c lex.yy.c
clean :
	rm myparser $(src).tab.c++ $(src).tab.h++ lex.yy.c $(objfiles)
