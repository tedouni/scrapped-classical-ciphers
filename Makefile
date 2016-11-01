all:	cipher

cipher:	cipher.o Playfair.o Caesar.o Vigenere.o Monoalphabetic.o Railfence.o
	g++ -std=c++11 cipher.o Playfair.o Caesar.o Vigenere.o Monoalphabetic.o Railfence.o -o cipher

cipher.o:	cipher.cpp
	g++ -std=c++11 -g -c cipher.cpp 

Playfair.o:	Playfair.cpp Playfair.h 
	g++ -std=c++11 -g -c Playfair.cpp
	
Caesar.o: Caesar.cpp Caesar.h 
	g++ -std=c++11 -g -c Caesar.cpp
	
Vigenere.o: Vigenere.cpp Vigenere.h 
	g++ -std=c++11 -g -c Vigenere.cpp
	
Monoalphabetic.o: Monoalphabetic.cpp Monoalphabetic.h 
	g++ -std=c++11 -g -c Monoalphabetic.cpp

Railfence.o: Railfence.cpp Railfence.h
	g++ -std=c++11 -g -c Railfence.cpp
	

# Uncomment this code once you add the appropriate files
#RowTransposition.o:	RowTransposition.cpp RowTransposition.h
#	g++ -g -c RowTransposition.cpp


clean:
	rm -rf *.o cipher