#
# Makefile for building xthreads library on i386
#
# Maintain the following definition:
#	HFILES	all header files (*.h) programmer created
#	SFILES	all C source files (*.c) programmer created
#	OFILES	all object files (*.o) required to load program
#
# Use the following make targets:
#	depend	to update header file dependencies

.DEFAULT:
	co -q $@

HFILES = proc.h 
CFILES = create.c yield.c resched.c main.c exit.c join.c
SFILES = ctxsw.s 
OFILES = create.o ctxsw.o yield.o resched.o main.o exit.o join.o
XTLIB  = ./libxt.a
APP_CFILES = xmain.c
APP_OFILES = xmain.o

IFLAGS = -g -I. 
CFLAGS =   ${IFLAGS}
DEPFLAGS = ${IFLAGS}
CC     = gcc -m32
AS     = as -32

RCS     = Makefile ${HFILES} ${CFILES}

a.out: ${XTLIB} ${APP_OFILES}
	${CC} ${CFLAGS} ${APP_OFILES} ${XTLIB} 

${XTLIB}: ${OFILES}
	ar cr ${XTLIB} ${OFILES}

ci:
	ci -u ${RCS}

clean:
	rm -f ${OFILES}	${APP_OFILES}

depend:
	makedepend ${DEPFLAGS} ${CFILES} ${SFILES}
# DO NOT DELETE THIS LINE - maketd DEPENDS ON IT

create.o: /usr/include/stdio.h /usr/include/features.h
create.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
create.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
create.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
create.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
create.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
create.o: ./proc.h /usr/include/stdlib.h /usr/include/sys/types.h
create.o: /usr/include/time.h /usr/include/endian.h
create.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
create.o: /usr/include/bits/byteswap-16.h /usr/include/sys/select.h
create.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
create.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
create.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
create.o: /usr/include/bits/stdlib-float.h
yield.o: /usr/include/stdio.h /usr/include/features.h
yield.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
yield.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
yield.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
yield.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
yield.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
yield.o: ./proc.h /usr/include/stdlib.h /usr/include/sys/types.h
yield.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
yield.o: /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h
yield.o: /usr/include/sys/select.h /usr/include/bits/select.h
yield.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
yield.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
yield.o: /usr/include/alloca.h /usr/include/bits/stdlib-float.h
resched.o: /usr/include/stdio.h /usr/include/features.h
resched.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
resched.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
resched.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
resched.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
resched.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
resched.o: ./proc.h /usr/include/stdlib.h /usr/include/sys/types.h
resched.o: /usr/include/time.h /usr/include/endian.h
resched.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
resched.o: /usr/include/bits/byteswap-16.h /usr/include/sys/select.h
resched.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
resched.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
resched.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
resched.o: /usr/include/bits/stdlib-float.h
main.o: /usr/include/stdio.h /usr/include/features.h
main.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
main.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
main.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
main.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
main.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
main.o: ./proc.h /usr/include/stdlib.h /usr/include/sys/types.h
main.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
main.o: /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h
main.o: /usr/include/sys/select.h /usr/include/bits/select.h
main.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
main.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
main.o: /usr/include/alloca.h /usr/include/bits/stdlib-float.h

