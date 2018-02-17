all: 
	g++ -std=c++17 sunflowerlane.cpp -lsfml-graphics -lsfml-window -lsfml-system -o sunflowerlane.o
	./sunflowerlane.o