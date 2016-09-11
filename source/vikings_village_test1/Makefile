#makefile for vikings village test

test: main.o Item.o Inventory.o Human.o TypeObjects.o Building.o
	g++ main.o Item.o Inventory.o Human.o TypeObjects.o Building.o -o test_village -std="c++11"

main.o: main.cpp
	g++ -c main.cpp -o main.o -std="c++11"

Item.o: Item.cpp
	g++ -c Item.cpp -o Item.o -std="c++11"

Inventory.o: Inventory.cpp
	g++ -c Inventory.cpp -o Inventory.o -std="c++11"

Human.o: Human.cpp
	g++ -c Human.cpp -o Human.o -std="c++11"

TypeObjects.o: TypeObjects.cpp
	g++ -c TypeObjects.cpp -o TypeObjects.o -std="c++11"

Building.o: Building.cpp
	g++ -c Building.cpp -o Building.o -std="c++11"

clean:
	rm -f *.o
