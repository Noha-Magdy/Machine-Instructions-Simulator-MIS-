misvm: TCPclintSocket.o TCPSocket.o ClientMain.o
	g++ -std=c++17 -pthread *.cpp  -o client_misvm

ASSIGN.o: TCPclintSocket.cpp TCPclintSocket.h
	g++ -std=c++17 -c TCPclintSocket.cpp -o TCPclintSocket.o

ASSIGN.o: TCPSocket.cpp TCPSocket.h
	g++ -std=c++17 -c TCPSocket.cpp -o TCPSocket.o

ClientMain.o: ClientMain.cpp
	g++ -std=c++17 -c ClientMain.cpp -o ClientMain.o

clean:
	rm *.o output

ciient:
	./ciient


