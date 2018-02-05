all: programmierkurs_fpcu.pdf

programmierkurs_fpcu.pdf: ersteschritte.tex definitions.tex intro.tex kontrollstrukturen.tex pointers.tex programmierkurs_fpcu.tex variablen.tex endprojekt.tex einfuegesortieren.tex dynamischespeicherverwaltung.tex complexdatatypen.tex dateinverarbeitung.tex stapelspeicher.tex funktionen.tex standartbibliothek.tex arrays.tex Makefile
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make programmierkurs_fpcu.tex

heapsort.pdf: heapsort.tex
	latexmk -bibtex -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make $<

publish: programmierkurs_fpcu.pdf
	cp programmierkurs_fpcu.pdf lecturenotes/publish/skript.pdf

.PHONY: clean
clean:
	rm -f -- $(scrap_aux) $(scrap_main)
