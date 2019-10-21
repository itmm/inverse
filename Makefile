.PHONY: test

test: inverse
	./inverse

inverse: inverse.cpp

inverse.cpp: index.md
	hx
