#include "ThreadMIS.h"
#include <string>
#define MAX 15
void* ThreadMIS::threadMainBody(void* arg) {
	*ip+=1;
	char * res;
	res=(char*)calloc(MAX,sizeof(char));
    	memset(res,0,MAX);
	while (!(words[0]=="END")) {
		try{
			split(myMIS->lines[*ip]);
			cout<<"ip: "<<*ip<<" pars: "<<parsNum<<" words[0]: "<<words[0]<<(words[0]=="END")<<endl;
			if(words[0]=="END") {cout<<"done with the thread 1";}
			myMIS->exe(ip,output,words,parsNum);
			cout<<"TH output"<<*(output)<<endl;
			if(*(output)!=""){
		            cout<<"TH sending output... ";
		            res[0]='o';
	  		    strcpy ((res+1), output->c_str());
			    tcpSocket->writeToSocket(res,MAX,output);
		            cout<<" ...output sent TH"<<endl;
			}
            	}
		catch(const MisError& msg){
		    string text=msg.formattedError();
		    res[0]='e';
		    cout<<"ip "<<*(ip)<<endl;
		    *(output)=to_string(*ip)+"    "+text+"\n";
		    strcpy ((res+1), output->c_str());

		    cout<<"TH sending ERR... ";
		    tcpSocket->writeToSocket(res,MAX,output);
		    cout<<" ...ERR sent TH"<<endl;
		    break;
        	}

	}
	cout<<"done with the thread";
}
ThreadMIS::ThreadMIS(MIS* pmyMIS, int* pip, string* pOutput,TCPSocket* _tcpSocket) {
	myMIS = pmyMIS;
	output = pOutput;
	cout<<*output<<output;
	ip = pip;
        tcpSocket = _tcpSocket; // Set the TCP socket
}

void ThreadMIS::split(string x){
    int conter = 0;
    int n=0;
    int limit=0;
    x+=" ";
    for(int i=0;i<14;i++)words[i]=""; // looping by index by max 14 word ..
    for(int n=0;n<x.length();n++){
       char test =x[n];
       if(test == ' ' || test == ','){ // splitting when seeing a space or a ,
            conter++;
            limit++;
            continue;
        }

        words[conter] += x[n];
        if(limit==13)break;

    }

    parsNum=limit; // passed parameters numbers to be set as limit for looping*/


}
ThreadMIS::~ThreadMIS(){if ( tcpSocket != NULL ) delete (tcpSocket);}

