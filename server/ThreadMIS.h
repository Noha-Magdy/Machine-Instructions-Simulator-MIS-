#pragma once
#include "Thread.h"
#include "MIS.h"
#include "TCPServerSocket.h"
class ThreadMIS : public Thread{
public:
	ThreadMIS(MIS* pmyMIS, int* pip, string* pOutput,TCPSocket*);
	~ThreadMIS();
	virtual void* threadMainBody(void* arg);
	void split(string x);
private:
	vector<string> lines;
	int* ip= new int;
	MIS * myMIS;
	string* output= new string;
 	string words[14];
        int parsNum=0;
	TCPSocket* tcpSocket;
};
