//
// Created by ioana on 13.04.2019.
//

#ifndef AFN_AFD_AUTOMAT_H
#define AFN_AFD_AUTOMAT_H

#include <unordered_map>
#include <fstream>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class automat {
private:
    //Matrice[i][j] = a inseamna ca din starea i se ajunge in starea j citind litera a
    //Observatie: Starile sunt citite drept caractere, apoi convertite la int, astfel incat corespondenta este
    // a -> 0, b -> 1, etc.
    char** matrice;
    //cheile reprezinta starile din afd, valorile sunt vectori care tin la pozitia i starea compusa
    // in care se ajunge cu al i-lea caracter din alfabet; Daca tranzitia nu este definita, stringul este "*"
    unordered_map<string, vector<string>> afd;
    int nrstari;
    vector<char> starifinale;
    string alfabet;
public:
    automat();
    ~automat();
    void transformare();
    friend ostream& operator<<(ostream&, automat&);
    friend ifstream& operator>>(ifstream&, automat&);

};


automat::automat()
{
    nrstari = 0;
    matrice = new char*[15];
    for(int i = 0; i < 15; i++)
    {
        matrice[i] = new char[15];
        for(int j = 0; j < 15; j++)
        {
            matrice[i][j] = '*';
        }
    }

}

automat::~automat()
{
    for(int i = 0; i < 15; i++)
    {
        delete[] matrice[i];
    }
    delete[] matrice;

}

void automat::transformare()
{
    //Se considera starea a ca fiind stare initiala
    queue<string> coada;
    coada.push("a");
    afd["a"] = *(new vector<string>); //initializam lista starii a cu un vector gol
    while(!coada.empty())
    {
        string stare = coada.front();
        coada.pop();
        //Pentru fiecare litera din alfabet
        for(int l = 0; l < alfabet.size(); l++) {
            string stareNoua = "";
            //Pentru fiecare stare din starea compusa curenta
            for(int j = 0; j < stare.size(); j++)
            {
                //Pentru fiecare stare existenta
                for (int i = 0; i < nrstari; i++)
                {
                    //Verificam daca exista tranzitie intre acestea cu litera curenta
                    if (matrice[stare[j] - 'a'][i] == alfabet[l])
                    {
                        //Pastram unicitatea starilor din noua stare compusa
                        if (stareNoua.find(i + 'a') == -1)
                            stareNoua += i + 'a';
                    }

                }
            }
            cout << stare << endl;
            //Sortam pentru ca ab <=> ba
            sort(stareNoua.begin(), stareNoua.end());
            if(!stareNoua.empty())
            {
                if(afd.find(stareNoua) == afd.end())
                {
                    vector<string>* v = new vector<string>;
                    afd[stareNoua] = *v;
                    coada.push(stareNoua);
                    afd[stare].push_back(stareNoua);
                    //cout << afd[stare][afd[stare].size() - 1] << "     MAP" << endl;
                }
            }
            else
            {
                afd[stare].push_back("*");
            }

        }

    }

}

ifstream& operator>>(ifstream& in, automat& x)
{
    in >> x.nrstari >> x.alfabet;
    int nrStariFinale;
    in >> nrStariFinale;
    for(int i = 0; i < nrStariFinale; i++)
    {

        char stare;
        in >> stare;
        x.starifinale.push_back(stare);
    }
    int nrTranzitii;
    char start, destinatie;
    char litera;
    in >> nrTranzitii;
    for(int i = 0; i < nrTranzitii; i++)
    {
       in >> start >> litera >> destinatie;
        x.matrice[start - 'a'][destinatie - 'a'] = litera;
    }


}

ostream& operator<<(ostream& out, automat& x)
{
    if(x.afd.empty())
    {
        return out;
    }
    for(auto& it: x.afd)
    {
        out << "starea: " << it.first;
        for(int i = 0; i <= it.second.size(); i++)
        {
            if(it.second[i][0] != '*')
            {
                out << "  cu caracterul ";
                out << x.alfabet[i] << "-> " << it.second[i] << endl;
            }
        }

    }
}


#endif //AFN_AFD_AUTOMAT_H
