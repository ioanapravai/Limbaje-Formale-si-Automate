#include <iostream>
#include <fstream>
#include "automat.h"
using namespace std;
int main() {
    ifstream in;
    in.open("C:/Users/ioana/Desktop/LFA/AFN-AFD/Auto");
    automat x;
    in >> x;
    x.transformare();
    cout << x;
    return 0;
}