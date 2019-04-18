#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "AFN.h"

int main() {
    AFN x;
    ifstream in;
    in.open("C:/Users/ioana/Desktop/LFA/Tema1AFN/Read.in");
    in >> x;
    bool gasit = false;
    if (x.verificaCuvant("", 0, gasit))
        cout << "Merge!!";
    else
        cout << "Cuvantul nu este acceptat";

    return 0;
}