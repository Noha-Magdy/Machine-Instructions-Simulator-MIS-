#include "executer.h"
#include <string>
#include <iostream>
using namespace std;
executer::executer(){}

bool executer::exe(int *_ip,string* _output){
cout<<"split start on ip: "<<*_ip<<"and line data is: "<<lines[*_ip]<<endl;

    split(lines[*_ip]);
    //if(*_ip>=lines.size()-1)return 1;// || (words[0]=="\\" && words[1]=="o")
	
    if(words[0]=="THREAD"){cout<<"new thread "<<*_ip<<endl;newThread(_ip,_output);return 0;}
    else if(words[0]=="BARRIER"){cout<<"size() "<<threads.size()<<endl; for(int i=0;i<threads.size();i++) (void) pthread_join(threads[i]->pthread,NULL);*_ip+=1;return 0;}
    else{return mis->exe(_ip,_output,words,parsNum);}
}
void executer::newThread(int*_ip,string*_output){

    int * ip = new int();
    *ip=*_ip;

    string * output = new string();
    *output=*_output;

    ThreadMIS *threadMis=new ThreadMIS(mis, ip, output, tcpSocket);
    threads.push_back(threadMis);
    //threadMis->start();
    threadMis->setToCore(core_id);

    core_id++;// Increment core id for the next thread
	 //If core_id is equal to the number of available cores/cpus, the reset it to 0
	if(core_id==threadMis->getCoreCount() )core_id=0;
    threadMis->start();

    for(;;){
        split(lines[*_ip]);
	//cout<<"s 2";
        if(words[0]=="END"){*(_ip)+=1;break;}
        *(_ip)+=1;
    }

}
void executer::init(){mis->lines=lines;mis->getLabel();}
void executer::split(string x){
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


executer::~executer()
{
	cout<<"get the hell out of her threads"<<threads.size();
	for(int i=0;i<threads.size();i++) delete (threads[i]);
}
