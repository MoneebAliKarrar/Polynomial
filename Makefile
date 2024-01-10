testPoly: testPoly.o Poly.o
	g++ -g $^ -o $@

Poly.o: Poly.cpp Poly.h
	g++ -g -c -Wall -pedantic $< -o $@

testPoly.o: testPoly.cpp Poly.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm Poly.o testPoly.o testPoly