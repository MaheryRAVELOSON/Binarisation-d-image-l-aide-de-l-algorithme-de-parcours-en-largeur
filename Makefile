Main_O = obj/main.o
Graphe_O = obj/graphe.o
Pixel_O = obj/pixel.o
Main_OUT = bin/main.out

Pixel = src/pixel
Graphe = src/graphe
Main = src/main

all: $(Main_OUT)

$(Main_OUT): $(Pixel_O) $(Graphe_O) $(Main_O)
	g++ -Wall -g $(Pixel_O) $(Graphe_O) $(Main_O) -o $(Main_OUT)

$(Pixel_O): $(Pixel).h $(Pixel).cpp
	g++ -Wall -g -c $(Pixel).cpp -o $(Pixel_O)

$(Graphe_O): $(Graphe).h $(Graphe).cpp
	g++ -Wall -g -c $(Graphe).cpp -o $(Graphe_O)

$(Main_O): $(Graphe).h $(Pixel).h $(Main).cpp
	g++ -Wall -g -c $(Main).cpp -o $(Main_O)

clean:
	rm obj/*.o bin/*.out data/La_Notre.pgm