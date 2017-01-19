
LIBS = -lm

OBJS = main.o Stack.o BalanceSymbol.o PostFixSymbol.o

CFLAGS = -Wall

main: ${OBJS}

	gcc -o $@  ${OBJS} ${LIBS}

clean:
	
	rm -f main ${OBJS}
