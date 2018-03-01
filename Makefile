all: programmierkurs_fpcu.pdf

programmierkurs_fpcu.pdf: *.tex graphics/*.pdf Makefile
	latexmk -pdf -pdflatex="xelatex --shell-escape --interaction=nonstopmode" -use-make programmierkurs_fpcu.tex

heapsort.pdf: heapsort.tex
	latexmk -bibtex -pdf -pdflatex="xelatex -interaction=nonstopmode" -use-make $<

publish: programmierkurs_fpcu.pdf
	cp programmierkurs_fpcu.pdf lecturenotes/publish/skript.pdf

.PHONY: clean
clean:
	latexmk -CA
	rm -rf *.tmp
	rm -f *.bbl *.blg *.aux *.end *.fls *.log *.out *.fdb_latexmk
