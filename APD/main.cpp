#include <iostream>
#include <fstream>
#include "Automat.h"
using namespace std;

int main()
{
    ifstream in("C:/Users/ioana/Desktop/LFA3/APD/apd.in");
    Automat automat;
    in >> automat;
    cout << automat.verificaCuvant("01c10");
    return 0;
}