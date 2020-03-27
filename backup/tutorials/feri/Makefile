TUTORIALS:=$(basename $(wildcard *.tex))

all: $(addsuffix .pdf, $(TUTORIALS))

%.pdf: %.tex
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make $?

clean:
	latexmk -CA
