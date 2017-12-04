all: programmierkurs_fpcu.pdf

all_tex = ersteschritte.tex definitions.tex intro.tex kontrollstrukturen.tex pointersarrays.tex programmierkurs_fpcu.tex variablen.tex endprojekt.tex einfuegesortieren.tex dynamischespeicherverwaltung.tex complexdatatypen.tex dateinverarbeitung.tex stapelspeicher.tex funktionen.tex standartbibliothek.tex

programmierkurs_fpcu.pdf: $(all_tex) Makefile
	latex programmierkurs_fpcu.tex
	latex programmierkurs_fpcu.tex
	dvips programmierkurs_fpcu.dvi
	ps2pdf programmierkurs_fpcu.ps

heapsort.pdf: heapsort.tex
	latexmk -bibtex -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make $<

all_aux := $(all_tex:%.tex=%.aux)
scrap_aux := $(filter $(wildcard *.aux), $(all_aux))
scrap_main := $(filter $(wildcard programmierkurs_fpcu.*), $(addprefix programmierkurs_fpcu., dvi log pdf ps toc))

publish: programmierkurs_fpcu.pdf
	cp programmierkurs_fpcu.pdf lecturenotes/publish/skript.pdf

.PHONY: clean
clean:
	rm -f -- $(scrap_aux) $(scrap_main)
