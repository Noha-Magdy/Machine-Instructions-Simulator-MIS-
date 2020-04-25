#ifndef MIS_H
#define MIS_H
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>
#include <iostream>
#include <fstream>
#include "VAR.h"
#include "NUMERIC.h"
#include "CHAR.h"
#include "STRING.h"
#include "REAL.h"
#include "OPERATION.h"
#include "ADD.h"
#include "MUL.h"
#include "SUB.h"
#include "DIV.h"
#include <typeinfo>
#include "MisError.h"
#include "SyntaxError.h"
#include <stdlib.h>
#include <ctype.h>
#include "undefined.h"
#include <sstream>
#include <string>
#include "Jump.h"
#include "JMPZ.h"
#include "JMPNZ.h"
#include "JMPGT.h"
#include "JMPGTE.h"
#include "JMPLTE.h"
#include "JMPLT.h"
#include <chrono>
#include <thread>
#include "ASSIGN.h"
#include "Locker.h"

using namespace std;


class MIS{
    public:
        MIS();
        ~MIS();
        string * split(string); // split the words on line
        void getLabel(); // getting a label
        void setFIles(string); // creating files
        void operatr(string,string _words[]);
        void jumper(string,string _words[]); // perform jump
        void varImplementer(string, string, string, string); // creating variables and add them to the map
        void writeErr(MisError,string _words[]); // writing on error file
        void writeOut(string*,string _words[]); // writing on output file
        bool exe(int *i, string* output, string _words[],int _parsNum); // executing process
        bool isThere(string); // checking if variable is on map
        void stringOP(string _words[]);
        double getVarINT(string);
        VAR* getVar(string);
        vector<string>lines;
        void getUnlock(string _words[]);
        void lockSYS(string _words[]);


    protected:

    private:
        string wordss[14];
        int parsNum=0;
        int* ip;
        Locker *currentLock;
        vector<Locker*> lockers;
        map<string,int>labels;
        map<string,VAR*>vars;
        map<string,OPERATION*> opes;
        map<string,VAR*> maker; // map of <variable type , pointer to a variable>
        map<string,int>whereToGo;
        map<string,Jump*>JMPs;

};

#endif // MIS_H
