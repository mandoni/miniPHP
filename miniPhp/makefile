myscanner: myscanner.c myscanner.h lex.yy.c
	cc myscanner.c lex.yy.c -ll -o myscanner 
	./miniPHP <config.ini

lex.yy.c: myscanner.l
	lex myscanner.l

clean:
	rm myscanner
	rm lex.yy.c