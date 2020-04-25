#include "Connection.h"
#include "TCPServerSocket.h"
#include <iostream>
#include "Sserver.h"
#include "executer.h"
#include "MisError.h"
#include <stdlib.h>     /* calloc, exit, free */	
#define MAX 1514
using namespace std;

//Constructor: Call parent Thread Constructor 
Connection::Connection(TCPSocket * p_tcpSocket): Thread()
{
    tcpSocket = p_tcpSocket; // Set the TCP socket
    next_connection = NULL; // Set the next pointer to NULL
}

void * Connection::threadMainBody (void * arg)
{
    char *addr=NULL;

    Server *ser=new Server();
    
//------------------------------------------
    char*data;
    data=(char*)calloc(MAX,sizeof(char));

//------------------------------------------
	int *ip=new int();
    *(ip)=0;
    string* output= new string();
    *(output)= "";

    executer* Executer=new executer();


    while (true){
        cout<<"start reading..."<<endl;
        tcpSocket->readFromSocket(data,MAX);
        cout<<"stop reading..."<<endl;
        int x=ser->process(data);
        cout<<"x= "<<x<<endl;
        ser->print();
        if(x==1){cout<<"WOW"<<endl;break;}
	//if()brek;
    }

cout<<"ser->lines.size() "<<ser->lines.size()<<endl;
    Executer->lines=ser->lines;
    Executer->tcpSocket=tcpSocket;
    char*res;
    res=(char*)calloc(MAX,sizeof(char));
    memset(res,0,MAX);
    Executer->init();


    while(true){
	
	if(*ip==ser->lines.size())break;
        try{
            bool t = Executer->exe(ip,output);
            if(*(output)!=""){
                    cout<<"sending output... ";
                    res[0]='o';
  		    strcpy ((res+1), output->c_str());
		    tcpSocket->writeToSocket(res,MAX,output);
                    cout<<" ...output sent"<<endl;
            }
            if(*ip==ser->lines.size()-1||t){cout<<"end of the file"<<endl;break;}

        }
        catch(const MisError& msg){
            string text=msg.formattedError();
            res[0]='e';
            cout<<"ip "<<*(ip)<<endl;
            *(output)=to_string(*ip)+"    "+text+"\n";
	    strcpy ((res+1), output->c_str());

            cout<<"Conn sending ERR... ";
	    tcpSocket->writeToSocket(res,MAX,output);
            cout<<" ...ERR sent"<<endl;
            break;
        }
	//*output="";
    }


   
    cout<<"Good bye";
    
}
// A modifier that sets the pointer of the next connection
void Connection::setNextConnection(Connection * connection){next_connection = connection;}
// A Selectot that returned a pointer to the next connection
Connection * Connection::getNextConnection (){return next_connection;}
// Destructor: delete the TCP socket if set
Connection::~Connection(){if ( tcpSocket != NULL ) delete (tcpSocket);}
