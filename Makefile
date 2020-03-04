
isobel: isobel.o card.o
	g++ isobel.o card.o -o isobel

isobel.o: isobel.cpp
	g++ -c isobel.cpp

card.o: card.cpp card.h
	g++ -c card.cpp

clean:
	rm *.o isobel
