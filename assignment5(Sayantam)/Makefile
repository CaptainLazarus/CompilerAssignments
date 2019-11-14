objfiles = main.o parser.o lex.o stack.o

a.out: $(objfiles)
	gcc $(objfiles)
main.o: main.c
	gcc -c -Wall main.c
parser.o: parser.c
	gcc -c -Wall parser.c
lex.o: lex.c
	gcc -Wall -c lex.c
stack.o: stack.c
	gcc -Wall -c stack.c
clean :
	rm a.out $(objfiles)