#pragma once
#include <string>
using namespace std;



class MOSFET
{
public:

    // init
    MOSFET(string Mname, string drain, string gate, string source);
    
    
    bool checkInput();
    string calculate();

    void printout();


private:

    string _Mname;
    string _drain;
    string _gate
    string _source;
    enum bodyType {PMOS, NMOS};

};
