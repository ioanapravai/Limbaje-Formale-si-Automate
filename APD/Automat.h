//
// Created by ioana on 23.05.2019.
//

#ifndef APD_AUTOMAT_H
#define APD_AUTOMAT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include "Tranzitie.h"

using namespace std;

class Automat {
private:

    vector<Tranzitie*> tranzitii;
    stack<char> stiva;
    string alfabet;
    int stareInitiala;
    vector<int> stariFinale;
    static const char lamda;
    static const char z0;
    string modAcceptare;

public:

    Tranzitie* getTranzitie(char litera, int stare);

    bool verificaCuvant(string cuvant);

    friend ifstream &operator>>(ifstream& in, Automat& automat);


};


#endif //APD_AUTOMAT_H
