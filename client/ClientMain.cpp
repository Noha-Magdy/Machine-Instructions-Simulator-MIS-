
#include "TCPclintSocket.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>     /* calloc, exit, free */
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

#define MAX 1514

void sendLines(string fileName,vector<string>* finalVector) {


	ifstream pFile;
	string line;
	pFile.open(fileName);
	//char *buffer;
	string buffer="";
	char c;
	//buffer=(char*)calloc(MAX,sizeof(char));
	int i=0;
	if (!pFile) cout<<("Error opening file");
	else
	{

		 while (pFile.get(c))
		{
			
			//memset(buffer,0,MAX);
			if(i!=MAX-1){buffer+=c;i++;cout<<""<<buffer;}
			else{
				buffer+=c;
				i=0;
				//string line (buffer,MAX);
				finalVector->push_back(buffer);cout<<line<<endl;
				buffer="";

			}
		
		}
		if(i!=0&&i<MAX){finalVector->push_back(buffer);cout<<line<<endl;cout<<"buffer= \""<<buffer<<"\""<<endl;}
		pFile.close();
	}



}

void writeErr(char*err,string name) { 
	ofstream stream;
	stream.open(name);
	if (!stream)cout << "cold not creat file";
	for (int i = 1; i < MAX; i++)stream << err[i];
	cout << "err DONE!" << endl;
}
void writeOut(char*out, string name) {
	ofstream stream;
	stream.open(name);
	if (!stream)cout << "cold not creat file";
	for (int i = 1; i < MAX; i++)stream << out[i];
	stream << '\n';
	cout << "err DONE!" << endl;
}
int main(int argc, char** argv){
	cout << "hi there"<<endl;
	int ii=0;string name;
        while(argv[3][ii]!='\0')
        {
		name+= argv[3][ii]; 
		ii++;
        }        

	char *addr=NULL;
	cout << argv[0]<<endl;
	TCPclintSocket* x=new TCPclintSocket (argv[1], atoi(argv[2]));
        TCPSocket*getServed=x->makeConnection(MAX,MAX);

        std::cout<<"File name: "<<name+".mis"<< endl;
	vector<string> readFile;
	sendLines( name+".mis",&readFile);
	std::cout << readFile[0] << endl;
	char*data;
	data = (char*)calloc(MAX, sizeof(char));
	cout << "data done" << endl;
	std::cout << argv[1] << endl<<endl;
	int i = 0;
	int j = 0;
	
	
	while (j < readFile.size()) {
		cout << readFile[j] << endl;
		for (; i < readFile[0].length(); i++)data[i] = readFile[j][i];
		for (; i<MAX; i++)data[i] = ' ';
		i = 0;
		cout << "setting data done" << endl;
		std::cout << getServed->writeToSocket(data, MAX) << endl;
		cout << "write to socket done" << endl;
		j++;
	}
	cout << "in read" << endl;
		
	char * data2;
    data2 = (char*)calloc(MAX, sizeof(char));
	
	while (true) {
		getServed->readFromSocket(data2, MAX);
		if (data2[0] == 'o') { 
			cout << "out " << data2[1] << endl;
			writeOut(data2,  name+".out");
		}
		else if (data2[0] == 'e') {
			cout << "err " << endl; 
			writeErr(data2, name+".err"); 
			break;

		}
		else break;
	}
	cout << "out read" << endl;

	
	/*b
	UDPServerSocket *serve=new UDPServerSocket();

    serve->initialize(addr,9000);
    std::cout<<serve->readFromSocketWithBlock(data2,MAX);
    //std::cout<<"ya rab "<<serve->isEnabled()<<std::endl;
    for(int i=0;i<MAX;i++)std::cout<<data2[i];
*/

}
