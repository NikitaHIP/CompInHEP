all: CompInHEPex1.pdf

CompInHEPex1.pdf: CompInHEPex1.tex
		pdflatex CompInHEPex1
		bibtex CompInHEPex1
