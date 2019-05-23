//
// Created by ioana on 23.05.2019.
//

#ifndef APD_TRANZITIE_H
#define APD_TRANZITIE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Tranzitie {
protected:
    char litera, stivaOut;
    string stivaIn;
    int start, destinatie;
public:
    Tranzitie(char litera, char stivaOut, string stivaIn, int start, int destinatie);

    Tranzitie();

    char getLitera() const;

    void setLitera(char litera);

    char getStivaOut() const;

    void setStivaOut(char stivaOut);

    string getStivaIn() const;

    void setStivaIn(string stivaIn);

    int getStart() const;

    void setStart(int start);

    int getDestinatie() const;

    void setDestinatie(int destinatie);
};


#endif //APD_TRANZITIE_H
