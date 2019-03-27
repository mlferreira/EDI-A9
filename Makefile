nome = a9

all:
	g++ -o $(nome) -g src/main.cpp src/gerador.h src/TLista.h src/TLista.cpp

clean:
	-rm -f *.o *~

run:
	./$(nome)
