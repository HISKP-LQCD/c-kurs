CC := gcc -O3 -std=c99 -Wall -Wpedantic
LD := gcc -O3 -std=c99 -Wall -Wpedantic

SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)

PROGRAMS := heapsort

MODULES := $(patsubst %.c, %.o, $(SOURCES))

MODULES := $(filter-out $(addsuffix .o, $(PROGRAMS)), $(MODULES))

# define BT_DEBUG to get a lot more output
DEFS := -D_POSIX_C_SOURCE=199309L #-DBT_DEBUG

LIBS := -lm

all: echo $(PROGRAMS)

echo:
	@echo SOURCES=$(SOURCES)
	@echo HEADERS=$(HEADERS)
	@echo MODULES=$(MODULES)
	@echo PROGRAMS=$(PROGRAMS)
	@echo LIBS=$(LIBS)
	@echo DEFS=$(DEFS)
	@echo CC=$(CC)
	@echo LD=$(LD)


$(addsuffix .o, $(PROGRAMS)): % : $(addsuffix .c, $(PROGRAMS)) $(HEADERS) Makefile
	$(CC) -c $(patsubst %.o, %.c, $@)

%.o: %.c %.h Makefile
	$(CC) $(DEFS) -c $<

$(PROGRAMS): % : %.o $(MODULES) $(HEADERS) Makefile
	$(LD) -o $@ $< $(MODULES) $(LIBS)

.PHONY: clean
clean:
	rm -f $(MODULES) $(PROGRAMS) $(addsuffix .o, $(PROGRAMS))
