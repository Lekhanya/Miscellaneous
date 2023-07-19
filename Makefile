
#all: 8-pazzel.o

8-puzzel.o: main.cpp
	g++ main.cpp -o 8-puzzel

clean:
	rm 8-puzzel
