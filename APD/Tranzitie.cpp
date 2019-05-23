//
// Created by ioana on 23.05.2019.
//

#include "Tranzitie.h"

Tranzitie::Tranzitie(char litera, char stivaOut, string stivaIn, int start, int destinatie) : litera(litera),
                                                                                            stivaOut(stivaOut),
                                                                                            stivaIn(stivaIn),
                                                                                            start(start),
                                                                                            destinatie(destinatie) {}

Tranzitie::Tranzitie() {}

char Tranzitie::getLitera() const {
    return litera;
}

void Tranzitie::setLitera(char litera) {
    Tranzitie::litera = litera;
}

char Tranzitie::getStivaOut() const {
    return stivaOut;
}

void Tranzitie::setStivaOut(char stivaOut) {
    Tranzitie::stivaOut = stivaOut;
}

string Tranzitie::getStivaIn() const {
    return stivaIn;
}

void Tranzitie::setStivaIn(string stivaIn) {
    Tranzitie::stivaIn = stivaIn;
}

int Tranzitie::getStart() const {
    return start;
}

void Tranzitie::setStart(int start) {
    Tranzitie::start = start;
}

int Tranzitie::getDestinatie() const {
    return destinatie;
}

void Tranzitie::setDestinatie(int destinatie) {
    Tranzitie::destinatie = destinatie;
}
