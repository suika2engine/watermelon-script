# cflags
CFLAGS = -Wall -Werror -Wextra -Wundef -Wno-sign-compare

# default target
all: wms

# Linux CLI binary
wms: wms_parser.tab.c wms_lexer.yy.c wms_core.c main.c
	gcc -O0 -g3 $(CFLAGS) -o $@ $^

# Windows CLI binary
wms.exe: wms_parser.tab.c wms_lexer.yy.c wms_core.c main.c
	i686-w64-mingw32-gcc -O2 $(CFLAGS) -s -o $@ $^

# parser
wms_parser.tab.c: wms_parser.y
	bison -d -p wms_yy wms_parser.y

# lexer
wms_lexer.yy.c: wms_lexer.l
	flex -o wms_lexer.yy.c --prefix=wms_yy wms_lexer.l

# install
install: wms_parser.tab.c wms_parser.y wms_lexer.yy.c wms_lexer.l wms_core.c wms_core.h wms.h
	cp $^ ../suika2/src/

# cleanup
clean:
	rm -rf wms *.tab.c *.tab.h *.yy.c out *~ testcase/*~
