nothing =
tmpdir = tmp

ifeq ($(OS),Windows_NT)
	suf := $(nothing).exe
else
	suf := $(nothing)
endif


.PHONY : all pro mk compile clean

all : pro mk compile

pro : $(tmpdir)
ifeq ($(OS),Windows_NT)
	cd src && qmake -project -o ../$(tmpdir)/task2.pro
else
	qmake -project -o $(tmpdir)/task2.pro
endif
mk : pro
	qmake -makefile -o $(tmpdir)/Makefile-qt $(tmpdir)/task2.pro
compile : mk
	make -C $(tmpdir) -f Makefile-qt && cp tmp/task2$(suf) task2$(suf)

clean :
	rm -rf $(tmpdir)
	rm -f $(wildcard task2*)
$(tmpdir) :
	mkdir $@

