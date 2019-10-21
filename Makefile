# LGPL3+ - (C) 2015 by Jan Helbling <jan.helbling@mailbox.org>

DESTDIR	=	/usr/local
LIB	=	$(DESTDIR)/lib/
INCLUDE	=	$(DESTDIR)/include/

default: myregexp.o libmyregexp.a

regexp.o:	myregexp.c myregexp.h
	gcc -c myregexp.c

libmyregexp.a:	myregexp.o
	ar -rcs libmyregexp.a myregexp.o

example: example.c myregexp.c myregexp.h myregexp.o
	gcc -c example.c
	gcc example.o myregexp.o -o example

test: example
	./example

clean:
	rm -f *.o example libmyregexp.a

install:	default
	install -m 755 libmyregexp.a $(LIB)
	install -m 644 myregexp.h $(INCLUDE)

uninstall:
	rm $(LIB)libmyregexp.a
	rm $(INCLUDE)myregexp.h
