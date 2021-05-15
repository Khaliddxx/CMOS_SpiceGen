#pragma once
#include <string>
#include <vector>
#include <stack>
using namespace std;



class MOSFET
{
public:

    // init
    MOSFET(string Mname, string drain, string gate, string source);
    
    bool check_priority(char& operator1, char& operator2);
    vector <string> calculate_priority(string& input_exp);
    // string calculate(string input);

    void printout();


private:

    string _Mname;
    string _drain;
    string _gate;
    string _source;
    enum bodyType {PMOS, NMOS};

};
