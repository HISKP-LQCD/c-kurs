SOURCES := $(wildcard *.tex)

all: $(SOURCES:tex=pdf)

%.pdf: %.tex Makefile uebungszettel.cls
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make $<

clean:
	latexmk -CA
