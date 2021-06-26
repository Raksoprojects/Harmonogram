#include <iostream>
#include "Czas.hpp"
#include <vector>

using namespace std;


class Harmonogram
{
    private:
    vector<Czas> harmo;

    public:
    Harmonogram();
    Harmonogram(const Harmonogram & h);
    ~Harmonogram();
    void DodajCzas(Czas c);
    Czas zwrocCzas(int i=0);
    Czas sumaCzas();
    int ileCzasow();
    void wypisz();
    void kopiuj_n(Harmonogram h, int n);
    // Dzisiejsze zajęcia
    void kopiuj_do_suma(Harmonogram h, Czas c);
    vector<Czas> getharmo();
    void usun_harmo();
    void dodaj_sekundy(int i, int n);

};