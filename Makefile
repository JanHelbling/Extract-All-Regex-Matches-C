# LGPL3+ - (C) 2015 by Jan Helbling <jan.helbling@mailbox.org>

DESTDIR	=	/usr/local
LIB	=	$(DESTDIR)/lib/
INCLUDE	=	$(DESTDIR)/include/

default: regexp.o libregexp.a

regexp.o:	regexp.c regexp.h
	gcc -c regexp.c

libregexp.a:	regexp.o
	ar -rcs libregexp.a regexp.o

example: example.c regexp.c regexp.h regexp.o
	gcc -c example.c
	gcc example.o regexp.o -o example

test: example
	./example

clean:
	rm -f *.o example libregexp.a

install:	default
	install -m 755 libregexp.a $(LIB)
	install -m 644 regexp.h $(INCLUDE)

uninstall:
	rm $(LIB)libregexp.a
	rm $(INCLUDE)regexp.h
