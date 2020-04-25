#ifndef EXECUTER_H
#define EXECUTER_H
#include "MIS.h"
#include "ThreadMIS.h"
#include "TCPServerSocket.h"

class executer
{
    public:
        executer();
        void split(string);
        bool exe(int *, string *);
        void newThread(int*,string*);
        void getThreadEnd();
		void init();
		
	
        virtual ~executer();
	vector<string>lines;
	TCPSocket * tcpSocket;

    protected:

    private:
        MIS *mis=new MIS();
        string words[14];
        int parsNum=0;
        int core_id=0;
        vector<ThreadMIS*>threads;


};

#endif // EXECUTER_H
