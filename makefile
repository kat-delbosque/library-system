run: main.o patrons.o LibraryItems.o loans.o patron.o LibraryItem.o book.o cd.o dvd.o loan.o
	g++ main.o patrons.o LibraryItems.o loans.o patron.o LibraryItem.o book.o cd.o dvd.o loan.o -o run

main.o: main.cpp patron.h LibraryItem.h loan.h patrons.h LibraryItems.h loans.h
	g++ -c main.cpp

patrons.o: patrons.cpp patron.h patrons.h
	g++ -c patrons.cpp

LibraryItems.o: LibraryItems.cpp LibraryItem.h LibraryItems.h dvd.h cd.h book.h
	g++ -c LibraryItems.cpp

loans.o: loans.cpp loan.h loans.h LibraryItems.h
	g++ -c loans.cpp

patron.o: patron.cpp patron.h
	g++ -c patron.cpp

LibraryItem.o: LibraryItem.cpp LibraryItem.h
	g++ -c LibraryItem.cpp
	
book.o: book.cpp book.h LibraryItem.h
	g++ -c book.cpp
	
cd.o: cd.cpp cd.h LibraryItem.h
	g++ -c cd.cpp
	
dvd.o: dvd.cpp dvd.h LibraryItem.h
	g++ -c dvd.cpp

loan.o: loan.cpp loan.h
	g++ -c loan.cpp

clean:
	rm *.o run
