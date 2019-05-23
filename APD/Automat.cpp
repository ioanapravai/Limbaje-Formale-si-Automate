//
// Created by ioana on 23.05.2019.
//

#include "Automat.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

const char Automat::z0 = 'z';
const char Automat::lamda = 'l';

Tranzitie* Automat::getTranzitie(char litera, int stare)
{
    char vfStiva = stiva.top();
    for(Tranzitie* tranzitie : tranzitii)
    {
        if(tranzitie->getLitera() == litera && tranzitie->getStart() == stare && tranzitie->getStivaOut() == vfStiva)
        {
            return tranzitie;
        }
    }
    return NULL;
}

bool Automat::verificaCuvant(string cuvant)
{
    int stareCurenta = stareInitiala;
    for(char litera : cuvant)
    {
        Tranzitie* t = getTranzitie(litera, stareCurenta);
        if(t)
        {
            stareCurenta = t->getDestinatie();
            if(t->getStivaOut() != lamda)
                stiva.pop();
            for(char sIn : t->getStivaIn())
            {
                if (sIn != lamda)
                    stiva.push(sIn);
            }
        }
        else
        {
            return false;
        }
    }

    if(modAcceptare == "sv")
    {
        if (stiva.top() == z0)
            stiva.pop();
        else
            return false;
        if(stiva.empty())
            return true;
    }
    if(modAcceptare == "sf")
    {
        for(int stare : stariFinale)
        {
            if(stareCurenta == stare)
                return true;
        }
    }
    if(modAcceptare == "sv_sf")
    {
        if (stiva.top() == z0)
            stiva.pop();
        else
            return false;
        if(stiva.empty())
        {
            for(int stare : stariFinale)
            {
                if(stareCurenta == stare)
                    return true;
            }
        }
    }

    return false;


}


ifstream &operator>>(ifstream& in, Automat& automat)
{
    in >> automat.alfabet;
    int n, f;
    in >> n;
    for(int i = 0; i < n; i++)
    {
        int s, d;
        char l, so;
        string si;
        in >> s >> d >> l >> si >> so;
        automat.tranzitii.push_back(new Tranzitie(l, so, si,s, d));
    }

    in >> automat.stareInitiala;
    in >> n;
    for(int i = 0; i < n; i++)
    {
        in >> f;
        automat.stariFinale.push_back(f);
    }
    in >> automat.modAcceptare;

    automat.stiva.push(automat.z0);
}