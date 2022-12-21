# cflags
CFLAGS = -O0 -g3 -Wall -Werror -Wextra -Wundef -Wconversion

# testing binary
wms: wms_parser.tab.c wms_lexer.yy.c wms_core.c main.c
	gcc -O0 -g3 -o $@ $(CFLAGS) $^

# testing binary for Windows
wms.exe: wms_parser.tab.c wms_lexer.yy.c wms_core.c main.c
	i686-w64-mingw32-gcc -Os -o $@ $^

# parser
wms_parser.tab.c: wms_parser.y
	bison -d -p wms_yy wms_parser.y

# lexer
wms_lexer.yy.c: wms_lexer.l
	flex -o wms_lexer.yy.c --prefix=wms_yy wms_lexer.l

# cleanup
clean:
	rm -rf wms *.tab.c *.tab.h *.yy.c out *~ testcase/*~
