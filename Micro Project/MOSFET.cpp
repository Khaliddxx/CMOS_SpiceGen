#include "MOSFET.h"
#include <iostream>

using namespace std;


// init
MOSFET::MOSFET(string Mname, string drain, string gate, string source)
{
    _Mname = Mname;
    _drain = drain;
    _gate = gate;
    _source = source;
}

bool MOSFET::calculate(string input)
{

// loop on characters
    
    // spaces not allowed => error handling
    
    // paranthesis not allowed (except with bonus)
    
    // single output symbol (except in bonus)
    
    // always vdd NET representing positive terminal of DC
}

string MOSFET::SPICE_output()
{
    // return string
}

void MOSFET::printout()
{
    cout << _Mname << _drain << _gate << _source << endl;
}
