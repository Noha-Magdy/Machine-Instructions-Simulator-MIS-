misvm: Locker.o JMPNZ.o JMPLTE.o JMPGTEError.o JMPZError.o DoubleJump.o NotDeclared.o JMPGT.o JMPGTError.o JMPLTEError.o JMPNZError.o Jump.o SingleJump.o SyntaxError.o ZeroDiv.o JMPGTE.o JMPLT.o JMPLTError.o JMPZ.o nonNumeric.o MisError.o undefined.o ASSIGN.o Connection.o GarbageCollector.o TCPServerSocket.o Thread.o MIS.o server.o DIV.o MUL.o SUB.o ADD.o OPERATION.o VAR.o STRING.o NUMERIC.o REAL.o CHAR.o executer.o ThreadMIS.o
	g++ -std=c++17 -pthread *.cpp  -o misvm

ASSIGN.o: ASSIGN.cpp ASSIGN.h
	g++ -std=c++17 -c ASSIGN.cpp -o ASSIGN.o

undefined.o: undefined.cpp undefined.h
	g++ -std=c++17 -c undefined.cpp -o undefined.o

MisError.o: MisError.cpp MisError.h
	g++ -std=c++17 -c MisError.cpp -o MisError.o

nonNumeric.o: nonNumeric.cpp nonNumeric.h
	g++ -std=c++17 -c nonNumeric.cpp -o nonNumeric.o

JMPZ.o: JMPZ.cpp JMPZ.h
	g++ -std=c++17 -c JMPZ.cpp -o JMPZ.o

JMPLTError.o: JMPLTError.cpp JMPLTError.h
	g++ -std=c++17 -c JMPLTError.cpp -o JMPLTError.o

JMPLT.o: JMPLT.cpp JMPLT.h
	g++ -std=c++17 -c JMPLT.cpp -o JMPLT.o

JMPGTE.o: JMPGTE.cpp JMPGTE.h
	g++ -std=c++17 -c JMPGTE.cpp -o JMPGTE.o

ZeroDiv.o: ZeroDiv.cpp ZeroDiv.h
	g++ -std=c++17 -c ZeroDiv.cpp -o ZeroDiv.o

SyntaxError.o: SyntaxError.cpp SyntaxError.h
	g++ -std=c++17 -c SyntaxError.cpp -o SyntaxError.o

SingleJump.o: SingleJump.cpp SingleJump.h
	g++ -std=c++17 -c SingleJump.cpp -o SingleJump.o

Jump.o: Jump.cpp Jump.h
	g++ -std=c++17 -c Jump.cpp -o Jump.o

JMPNZError.o: JMPNZError.cpp JMPNZError.h
	g++ -std=c++17 -c JMPNZError.cpp -o JMPNZError.o

JMPLTEError.o: JMPLTEError.cpp JMPLTEError.h
	g++ -std=c++17 -c JMPLTEError.cpp -o JMPLTEError.o

JMPGTError.o: JMPGTError.cpp JMPGTError.h
	g++ -std=c++17 -c JMPGTError.cpp -o JMPGTError.o

JMPGT.o: JMPGT.cpp JMPGT.h
	g++ -std=c++17 -c JMPGT.cpp -o JMPGT.o

NotDeclared.o: NotDeclared.cpp NotDeclared.h
	g++ -std=c++17 -c NotDeclared.cpp -o NotDeclared.o

DoubleJump.o: DoubleJump.cpp DoubleJump.h
	g++ -std=c++17 -c DoubleJump.cpp -o DoubleJump.o

JMPZError.o: JMPZError.cpp JMPZError.h
	g++ -std=c++17 -c JMPZError.cpp -o JMPZError.o

JMPGTEError.o: JMPGTEError.cpp JMPGTEError.h
	g++ -std=c++17 -c JMPGTEError.cpp -o JMPGTEError.o

JMPLTE.o: JMPLTE.cpp JMPLTE.h
	g++ -std=c++17 -c JMPLTE.cpp -o JMPLTE.o

JMPNZ.o: JMPNZ.cpp JMPNZ.h
	g++ -std=c++17 -c JMPNZ.cpp -o JMPNZ.o

ADD.o: ADD.cpp ADD.h
	g++ -std=c++17 -c ADD.cpp -o ADD.o

SUB.o: SUB.cpp SUB.h
	g++ -std=c++17 -c SUB.cpp -o SUB.o

MUL.o: MUL.cpp MUL.h
	g++ -std=c++17 -c MUL.cpp -o MUL.o

DIV.o: DIV.cpp DIV.h
	g++ -std=c++17 -c DIV.cpp -o DIV.o

VAR.o: VAR.cpp VAR.h
	g++ -std=c++17 -c VAR.cpp -o VAR.o

NUMERIC.o: NUMERIC.cpp NUMERIC.h
	g++ -std=c++17 -c NUMERIC.cpp -o NUMERIC.o

REAL.o: REAL.cpp REAL.h
	g++ -std=c++17 -c REAL.cpp -o REAL.o

STRING.o: STRING.cpp STRING.h
	g++ -std=c++17 -c STRING.cpp -o STRING.o

CHAR.o: CHAR.cpp CHAR.h
	g++ -std=c++17 -c CHAR.cpp -o CHAR.o

CHAR.o: Sserver.cpp Sserver.h
	g++ -std=c++17 -c Sserver.cpp -o Sserver.o

MIS.o: MIS.cpp MIS.h
	g++ -std=c++17 -c MIS.cpp -o MIS.o

Server.o: server.cpp
	g++ -std=c++17 -c server.cpp -o server.o

TCPServerSocket.o: TCPServerSocket.cpp TCPServerSocket.h
	g++ -std=c++17 -c TCPServerSocket.cpp -o TCPServerSocket.

Thread.o: Thread.cpp Thread.h
	g++ -std=c++17 -c Thread.cpp -o Thread.o

Connection.o: Connection.cpp Connection.h
	g++ -std=c++17 -c Connection.cpp -o Connection.o

ThreadMIS.o: ThreadMIS.cpp ThreadMIS.h
	g++ -std=c++17 -c ThreadMIS.cpp -o ThreadMIS.o

executer.o: executer.cpp executer.h
	g++ -std=c++17 -c executer.cpp -o executer.o

Locker.o: Locker.cpp Locker.h
	g++ -std=c++17 -c Locker.cpp -o Locker.o

GarbageCollector.o: GarbageCollector.cpp GarbageCollector.h
	g++ -std=c++17 -c GarbageCollector.cpp -o GarbageCollector.o

clean:
	rm *.o misvm server

server:
	./server
