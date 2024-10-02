all: install

tests: clean tests/Makefile tests/tests.pro
	@cd ./tests; qmake
	@cd ./tests; make
	./tests/tests

install:
	@cd ./calc2; qmake6 calc2.pro -o Makefile
	@cd ./calc2; make install; make clean && echo "DONE"

uninstall:
	@cd ./calc2; make uninstall; make clean; rm -rf calc2.app; rm -rf calc2
	@echo "DONE"

dist:
	@mkdir dist
	@tar --totals -cvf ./dist/calc2.tar ./calc2/*

dvi:
	rm -rf docs
	mkdir docs
	doxygen Doxyfile
	@mv html latex docs
	open docs/html/index.html

clean:
	rm -rf tests/*.o
	rm -rf tests/*.out

