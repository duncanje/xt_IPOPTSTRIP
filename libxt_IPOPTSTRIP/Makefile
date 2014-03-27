CFLAGS = -O2 -Wall
NAME = libxt_IPOPTSTRIP
INSTALL_DIR = /lib/xtables

${NAME}.so: ${NAME}.o
	gcc -shared -fPIC -o $@ $<;
${NAME}.o: ${NAME}.c
	gcc ${CFLAGS} -D_INIT=lib$*_init -fPIC -c -o $@ $<;
install: ${NAME}.so
	cp ${NAME}.so ${INSTALL_DIR}
uninstall:
	rm ${INSTALL_DIR}/${NAME}.so
clean:
	rm ${NAME}.so
	rm ${NAME}.o
