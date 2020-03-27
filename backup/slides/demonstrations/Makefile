SOURCES := $(filter-out verrueckter_funktionsbaum.c, $(wildcard *.c))
LIBS := -lm

all: $(basename $(SOURCES))

verrueckter_funktionsbaum.c: make_crazy_functions.sh
	bash make_crazy_functions.sh

verrueckter_funktionsbaum: verrueckter_funktionsbaum.c
	gcc -Wall -Wpedantic -std=c99 -o $@ $<

$(basename $(SOURCES)): % : %.c Makefile
	gcc -g -ggdb -Wall -Wpedantic -std=c99 -o $@ $< ${LIBS}

.PHONY: clean
clean:
	rm -f $(basename $(SOURCES))
	rm verrueckter_funktionsbaum*
