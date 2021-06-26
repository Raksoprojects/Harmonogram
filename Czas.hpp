#include <iostream>

using namespace std;

class Czas 
{
private:
    int sekunda;
    int minuta;
    int godzina;
    void setGodzina(int l);
    void setMinuta(int l);
    void setSekunda(int l);


public:

    //void podajCzas(int h, int m, int s);
    void ustawCzas(int h , int m, int s);
    //Konstruktor
    Czas();
    Czas(int);
    Czas(int ,int );
    Czas(int , int , int );  
    ~Czas();
    void wypisz();
    int getGodzina();
    int getMinuta();
    int getSekunda();
    void ustaw1(int s);
    void ustaw2(int s, int m);
    void ustaw3(int s, int m, int h);
    void suma(Czas c1, Czas c2);
    void dodajsek(int l);
    bool porownanie(Czas c);


};