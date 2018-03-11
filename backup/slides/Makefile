COMMONDEPS := bibliography.bib Makefile $(wildcard algos/*.tex)
SLIDEDEPS := slidespreamble.tex
LECTUREDEPS := $(wildcard vorlesung?.tex) preamble.tex

all: Vorlesungsnotizen.pdf Vorlesungsnotizen-student.pdf slides.pdf

Vorlesungsnotizen.pdf: Vorlesungsnotizen.tex $(COMMONDEPS) $(LECTUREDEPS)
	latexmk -bibtex -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make Vorlesungsnotizen.tex

Vorlesungsnotizen-student.tex: Vorlesungsnotizen.tex $(COMMONDEPS) $(LECTUREDEPS)
	sed 's/lecturertrue/lecturerfalse/g' Vorlesungsnotizen.tex > Vorlesungsnotizen-student.tex

Vorlesungsnotizen-student.pdf: Vorlesungsnotizen-student.tex $(COMMONDEPS) $(LECTUREDEPS)
	latexmk -bibtex -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make Vorlesungsnotizen-student.tex

slides.pdf: slides.tex $(COMMONDEPS) $(SLIDEDEPS)
	latexmk -f -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make slides.tex

clean:
	latexmk -CA
	rm Vorlesungsnotizen-student.tex
	rm slides.nav slides.snm slides.vrb

publish: publish/c-kurs-2017-Folien.pdf tutorials
	
tutorials: $(wildcard ../tutorials/selected-tutorials/*.pdf )
	echo $^
	cp $^ publish/


publish/c-kurs-2017-Folien.pdf: slides.pdf
	mkdir -p publish
	cp slides.pdf publish/c-kurs-2017-Folien.pdf

.PHONY: clean tutorials
