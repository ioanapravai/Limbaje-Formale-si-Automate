//
// Created by ioana on 16.03.2019.
//
#ifndef TEMA1AFN_AFN_H
#define TEMA1AFN_AFN_H

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class AFN
{
private:
    int stareInitiala;
    vector<int> stariFinale;
    string alfabet;
    int numarStari;
    int nrTranzitii;
    vector< pair<int, char> > tranzitii[100];

public:
    AFN();

    bool verificaCuvant(string, int, bool&);

    friend ifstream& operator>> (ifstream&, AFN&);
};
//se initializeaza un AFN cu o singura stare
AFN::AFN()
{
    stareInitiala = 0;
    alfabet = "";
    numarStari = 1;
    nrTranzitii = 0;
}

bool AFN::verificaCuvant(string cuvant, int stare, bool& gasit)
{
    //Gasit este un parametru utilizat pentru oprirea celorlalte apeluri recursive atunci cand unul returneaza true
    if(gasit == true)
    {
        return true;
    }
    //Cazurile: cuvantul vid se afla in limbaj/ am ajuns la finalul cuvantului si starea curenta este si finala/ am ajuns la finalul cuvantului si starea curenta nu este finala
    if(cuvant.compare("") == 0)
    {
        for(int i = 0; i < stariFinale.size(); i++)
        {
            if(stare == stariFinale[i])
            {

                gasit = true;
                return true;
            }
        }
        return false;
    }

    char litera = cuvant[0]; //litera curenta
    for(int i = 0; i < tranzitii[stare].size(); i++)
    {
        if(tranzitii[stare][i].second == litera)//gasim tranzitie pentru litera curenta(acoprind si cazul in care litera nu e in alfabet)
        {
            verificaCuvant(cuvant.substr(1), tranzitii[stare][i].first, gasit); //continuam verificarea pentru restul cuvantului
        }
    }
    return gasit;

}
/*
 Supraincarcarea operatorului de citire:
 1. Numarul starilor
 2. Alfabetul de intrare
 3. Starea initiala a automatului
 4. Numarul de stari finale
 5. Starile finale
 6. Numarul tranzitiilor
 7. Tranzitiile: nodul de start, litera si destinatia.
 */
ifstream& operator>> (ifstream& in, AFN& afn)
{
    in >> afn.numarStari;
    in >> afn.alfabet;
    in >> afn.stareInitiala;

    int nrStariFinale;
    in >> nrStariFinale;
    for(int i = 0; i < nrStariFinale; i++)
    {
        int st;
        in >> st;
        afn.stariFinale.push_back(st);
    }
    //Lista de adiacenta
    in >> afn.nrTranzitii;
    for(int i = 0; i < afn.nrTranzitii; i++)
    {
        int start;
        char litera;
        int destinatie;
        in >> start >> litera >> destinatie;
        afn.tranzitii[start].push_back(make_pair(destinatie, litera));
    }

    return in;
};
#endif //TEMA1AFN_AFN_H
