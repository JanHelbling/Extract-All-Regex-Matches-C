# LGPL3+ - (C) 2015 by Jan Helbling <jan.helbling@gmail.com>

default: regexp library

regexp:	regexp.c regexp.h
	gcc -c regexp.c

library:
	ar -rvs libregexp.a regexp.o

example: example.c regexp.c regexp.h
	gcc -c example.c regexp.c
	gcc example.o regexp.o -o example

test: example
	./example

clean:
	rm -f *.o example libregexp.a
