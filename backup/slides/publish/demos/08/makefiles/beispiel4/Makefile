# Compiler
CC=gcc -std=c99 -Wall -Wpedantic

# Linker
LD=gcc -std=c99 -Wall -Wpedantic

# all unsere Quelltextdateien und Headerdateien werden in Variablen gespeichert
# dazu wird im momentanen Verzeichnis nach allen .c und .h Dateien gesucht
SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)

# für alle .c-Dateien wird eine Variable erstellt, wo alle .c durch .o ersetzt
# wurden, dies sind unsere Module
MODULES := $(patsubst %.c, %.o, $(SOURCES))

# die ausführbaren Programme, die unser Projekt beinhalten wird (hier ist es nur eins)
PROGRAMS := teilchen

# Objektdateien für Main-module werden separat behandelt
# sie müssen also aus der $(MODULES)-Variable rausgefiltert werden
# dazu nutzen wir filter-out
# die Syntax ist: $(filter-out "zu filternde Objekte", "Objekte aus denen gefiltert werden soll")
MODULES := $(filter-out $(addsuffix .o, $(PROGRAMS)), $(MODULES))

# benötigte Bibliotheken
LIBS := -lm -lgsl -lgslcblas

# unser Standardtarget
# wir nutzen es als Gelegenheit, den Inhalt aller Variablen ausgeben zu lassen
all: echo $(PROGRAMS)

# das '@' unterdrückt hierbei eine Ausgabezeile, in der die Eingabezeile
# wiederholt wird
echo:
	@echo SOURCES=$(SOURCES)
	@echo HEADERS=$(HEADERS)
	@echo MODULES=$(MODULES)
	@echo PROGRAMS=$(PROGRAMS)
	@echo LIBS=$(LIBS)

# Regel zum Kompilieren der Objekdateien in denen die Mainfunktion(en)
# unsere[r,s] Programme sind
# Das/die main-Modul(e) ha[t,ben] keine Headerdateien, haengen aber
# of von (fast) allen anderen Headerdateien ab
# kleines Problem hier: jedes Main-modul hängt von allen C-Dateien der Main-module ab
# da kann man leider nicht viel machen ausser weniger generische Makefiles
# zu schreiben
$(addsuffix .o, $(PROGRAMS)): % : $(addsuffix .c, $(PROGRAMS)) $(HEADERS) Makefile
	$(CC) -c $(patsubst %.o, %.c, $@)

# Regel zum kompilieren unserer Module
# Jedes Modul hat eine Headerdatei
%.o: %.c %.h Makefile
	$(CC) -c $<

$(PROGRAMS): % : %.o $(MODULES) Makefile
	$(LD) -o $@ $< $(MODULES) $(LIBS)

.PHONY: clean
clean:
	rm -f $(MODULES) $(PROGRAMS) $(addsuffix .o, $(PROGRAMS))
