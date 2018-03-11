SOURCES := $(wildcard *.c)

# die erste Regel ist die Standardregel
all: $(basename $(SOURCES))

$(basename $(SOURCES)): % : %.c Makefile
	gcc -g -ggdb -Wall -Wpedantic -std=c99 -o $@ $<

.PHONY: clean all
clean:
	rm $(basename $(SOURCES))
