all: datos.dat graficas.png 

%.png: %.dat graficas.png 
	python3 ploteo.py

%.dat: a.out
	./a.out

a.out: correr.cpp
	g++ correr.cpp 

clean:
	rm -rf *.x *.dat *.png

