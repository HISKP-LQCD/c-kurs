SOURCES := $(wildcard *.c)

all: $(basename $(SOURCES))

$(basename $(SOURCES)): % : %.c Makefile
	gcc -std=c99 -Wall -Wpedantic -o $@ $<

clean:
	rm -f $(basename $(SOURCES))
