#include <iostream>
#include "Harmonogram.hpp"
#include <vector>

using namespace std;

Harmonogram::Harmonogram(){

}
// Konstruktor kopiujący, kopiuje już istniejący harmonogram do nowo utworzonego
Harmonogram::Harmonogram(const Harmonogram & h){

    if(!h.harmo.empty()){
        for(int i = 0; i < h.harmo.size(); ++i ){
            this->harmo.push_back(h.harmo[i]);
        }
    }

}
Harmonogram::~Harmonogram(){

}
// Metoda dodająca na stos harmonogramu nowy czas, nowe "wydarzenie"
void Harmonogram::DodajCzas(Czas c){
    this->harmo.push_back(c);
}
// Zwraca ilośc wydarzeń w harmonogramie
int Harmonogram::ileCzasow(){
    // zawsze staarmy się sprawdzić czy nasz harmonogram nie jest pusty
    if(!this->harmo.empty()) return this->harmo.size();
    else return 0;
}
// Wypisujemy cały zapisany harmonogram, o ile nie jest on pusty
void Harmonogram::wypisz(){
    if(!this->harmo.empty()){
        for(int i=0; i<this->harmo.size(); ++i){
            this->harmo[i].wypisz(); // korzystamy tu z metody klasy Czas, dla każdego obiektu czas zawartego w harmonogramie
            cout<<endl;
        }
    }
    else cout<<"Harmonogram jest pusty!\n";
}
// Zwracamyt konkretny czas w harmonogramie, konkretne "wydarzenie"
Czas Harmonogram::zwrocCzas(int i){
    if(!this->harmo.empty() && i<this->harmo.size()){
        return this->harmo[i];
    }
    else{
        cout<<"Harmonogram jest pusty, lub wyszedles poza zakres!\n";
        return 0;
    }

}
// Sumujemy cały czas zawarty w harmonogramie
Czas Harmonogram::sumaCzas(){
    int h = 0;
    int m = 0;
    int s = 0;
    if(!this->harmo.empty()){
        // Pobieramy godzinę, minute i sekundę z każdego czasu zawartego w harmonogramie
        // korzystając z getterów zawartych w klasie Czas
        for(int i=0;i<this->harmo.size(); ++i){
            h += this->harmo[i].getGodzina();
            m += this->harmo[i].getMinuta();
            s += this->harmo[i].getSekunda();
        }
        // Tworzymy nowy obiekt klasy Czas i zapisujemy do niego zsumowany czas
        Czas suma(0,0,0);
        s = h*3600 + m * 60 + s;
        suma.ustaw1(s); // ustawiamy go
        return suma; // i zwracamy 
    }
    else cout<<"Harmonogram jest pusty!\n";
    return 0;
}
// getter naszego całego harmonogramu zawierającegop elementy czasu
vector<Czas> Harmonogram::getharmo(){
    return this->harmo;
}
// kopiujemy n pierwszych czasów z jednego harmonogramu do drugiego
void Harmonogram::kopiuj_n(Harmonogram h, int n){
        
        if(!h.harmo.empty() && n<h.harmo.size()){
            for(int i=0;i<n;++i){
                //  zwracamy czas z i-tej pozycji i zapisujemy go dso naszego harmonogramu
                this->harmo.push_back(h.zwrocCzas(i));
            }
        }
        else cout<<"Harmonogram z którego chciałeś skopiować jest pusty lub chciałeś skopiwować więcej czasów niż ich jest\n";
}
// Dzisiaj
void Harmonogram::kopiuj_do_suma(Harmonogram h, Czas c){
        
        Czas sum;
        if(!h.harmo.empty()){
            for(int i =0; i < h.harmo.size(); ++i){
                sum.suma(sum,h.zwrocCzas(i));
                if(c.porownanie(sum)){
                    this->harmo.push_back(h.zwrocCzas(i));
                }
                else return;
                
            }
        }
        else cout<<"Harmonogram z którego chciałeś skopiować jest pusty lub chciałeś skopiwować więcej czasów niż ich jest\n";

}
void Harmonogram::usun_harmo(){
    this->harmo.clear();
}

void Harmonogram::dodaj_sekundy(int i, int n){
    Czas pom;
    pom = this->harmo[i];
    pom.dodajsek(n);
    this->harmo[i] = pom;
}
