#include<iostream>
#include "MOSFET.h"
using namespace std;


int main() {

    MOSFET M1("M", "D", "G", "S");
    M1.printout();


    return 0;
}
