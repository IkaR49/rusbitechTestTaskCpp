ifeq ($(OS),Windows_NT)
all :
	@echo "Сборка задания 3 не производится под Windows"
clean :
	@echo "Очистка задания 3 не производится под Windows"
else
all :
	latex solution.tex
	dvips -o solution.ps solution.dvi
	ps2pdf solution.ps

clean :
	rm -rf solution.aux solution.p* solution.dvi solution.log
endif

