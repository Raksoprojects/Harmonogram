#include <iostream>
#include "Czas.hpp"

using namespace std;


    // Setter, ustawić ograniczniki
    void Czas::setGodzina(int l) {
        if (l < 0)  cout << "Blad ,nie ma takiej godziny,zobacz nizej" << endl;
        else this->godzina = l;
    }
    // ustawiamy minute i sekunde
    void Czas::setMinuta(int l) {
        if (l < 0) cout << "Blad ,nie ma takiej minuty,zobacz nizej" << endl;
        if (l >= 60){
            l = l % 60;
            this->minuta = l;
        }
        else this->minuta = l;
    }
    // ustawiamy tylko sekunde
    void Czas::setSekunda(int l) {
        if (l < 0) cout << "Blad ,nie ma takiej sekundy,zobacz nizej" << endl;
        else if (l >= 60) {                           //ile sekund nam zostaje
            l = l % 60;
            this->sekunda = l;
        }
        else this->sekunda = l;
    }
    
    // Podstawowy konstruktor ustawiający godzinę
    Czas::Czas(int s, int m, int g) : godzina(0), minuta(0), sekunda(0){
        // this->setGodzina(g);
        // this->setMinuta(m);
        // this->setSekunda(s);
        this->ustaw3(s,m,g);
    }
    Czas::Czas(int s, int m) : godzina(0), minuta(0), sekunda(0){
        // this->setGodzina(g);
        // this->setMinuta(m);
        // this->setSekunda(s);
        this->ustaw2(s,m);
    }
    Czas::Czas(int s) : godzina(0), minuta(0), sekunda(0){
        // this->setGodzina(g);
        // this->setMinuta(m);
        // this->setSekunda(s);
        this->ustaw1(s);
    }
    Czas::Czas() : godzina(0), minuta(0), sekunda(0){
        // this->setGodzina(g);
        // this->setMinuta(m);
        // this->setSekunda(s);
        // this->ustaw3(0,0,0);
    }

    Czas::~Czas(){}
    // Wypisujemy Czas zapisany w obiekcie
    
    
    void Czas::wypisz(){
        cout<<"Czas: "<<this->godzina<<":"<<this->minuta<<":"<<this->sekunda;
    }
    // Getter, pobieramy godzinę, minutę lub sekundę z obiektu
    int Czas::getGodzina() {
        return this->godzina;
    }
    int Czas::getMinuta() {
        return this->minuta;
    }
    int Czas::getSekunda() {
        return this->sekunda;
    }
    // Pierwsze ustawianie, podajemy tylko sekundy
    void Czas::ustaw1(int s){

        // Zerujemy czas obiektu
        this->godzina = 0;
        this->minuta = 0;
        this->sekunda = 0;
        // Następnie ustawiamy godzinę, najpierw sekundę, potem minutę i potem godzinę, jeśli trzeba
        this->setSekunda(s);
        s = s/60; // Dzielimy na minuty
        if(s>0) this->setMinuta(s);
        s = s/60; // Dzielimy na godziny
        if(s>0) this->setGodzina(s);
        
    }
    // Drugie ustawianie, ustawiamy zarówno minuty jak i sekundy, tym razem sekundy muszą być od 0 do 59 
    void Czas::ustaw2(int s, int m){

        // Zerujemy czas obiektu
        this->godzina = 0;
        this->minuta = 0;
        this->sekunda = 0;
        // Ustawiamy sekundy tylko jeśli są od 0 do 59
        if(s>=60){
            cout<<"Błędna wartośc sekund!\n";
            return;
        }
        // Jeśli udało się ustawić sekundy to przechodzimy do ustawiania minut i godzin
        else{
            this->setSekunda(s);
            this->setMinuta(m);
            m = m/60;
            if(m>0) this->setGodzina(m); 
        }
    }
    // Trzecie ustawianie, ustawiamy pełny czas
    void Czas::ustaw3(int s, int m, int h){

        // Zerujemy czasz obiektu
        this->godzina=0;
        this->minuta = 0;
        this->sekunda = 0;
        // Sprawdzamy sekundy, od 0 do 59
        if(s>=60){
            cout<<"Błędna wartośc sekund!\n";
            return;
        }
        // Jeśli dobre były sekundy to sprawdzamy minuty
        else if(m>=60){
            cout<<"Błędna wartośc minut!\n";
            return;
        }
        // Ustawiamy czas
        else{
            this->setGodzina(h);
            this->setMinuta(m);
            this->setSekunda(s);

        }
    }
    // Sumowanie dwóch czasów
    void Czas::suma(Czas c1, Czas c2){

        // Pobranie godziny z jednego czasu
        int h1 = c1.getGodzina();
        int m1 = c1.getMinuta();
        int s1 = c1.getSekunda();
        // Pobranie godziny z drugiego czasu
        int h2 = c2.getGodzina();
        int m2 = c2.getMinuta();
        int s2 = c2.getSekunda();

        // Zerujemy czas obiektu
        this->godzina=0;
        this->minuta = 0;
        this->sekunda = 0;

        int s3 = s1+s2; // zsumowanie sekund
        int m3 = 0; // inicjalizacja minut
        int h3 = 0; // inicjalizacja godzin

        if(s3>=60){ // Jeżeli zsumowane sekundy są większe niż 60 to dodajemy minutę
            m3 = m1+m2+1;
            s3 = s3%60; // I bierzemy reszte z dzielenia przez 60, pobieramy liczbę sekund
            if(m3>=60){ //Jeżeli zsumowane minuty są większe od 60 to do godzin dodajemy 1
                h3 = h1+h2+1;
                m3 = m3%60; // No i bierzemy pozostałośc minut

            }
            else{
                h3 = h1+h2; // Sumujemy liczbę godzin
            }
        }
        else{ // Natomiast jeżeli zsumowane sekundy nie są większe od 60 

            m3 = m1+m2; // to po prostu dodajemy minuty
            if(m3>=60){
                h3 = h1+h2+1; // to samo co wyżej
                m3 = m3%60;

            }
            else{
                h3 = h1+h2;
            }
        }
        // no i na koniec ustawiamy nowy czas
        this->ustaw3(s3,m3,h3);

    }
    // Metoda dodająca sekundy do czasu
    void Czas::dodajsek(int l){
        //Pobieramy godzinę
        int h = this->getGodzina();
        int m = this->getMinuta();
        int s = this->getSekunda();
        // Dodajemy sekundy do sekund obiektu
        s = s+l;
        int sek = h*3600 + m * 60 + s; // i wyliczamy nową liczę sekund do ustawienia
        this->ustaw1(sek);

    }

    // Porównujemy czasy, obiektu i podany
    bool Czas::porownanie(Czas c){
        // Pobranie czasu z drugiego obiektu
        int h1 = c.getGodzina();
        int m1 = c.getMinuta();
        int s1 = c.getSekunda();
        
        cout<<endl;
        // Wypisanie który jest większy
        int h = this->getGodzina();
        int m = this->getMinuta();
        int s = this->getSekunda();
        if(h*3600+m*60+s > h1*3600+m1*60+s1) return true;
        else if(h*3600+m*60+s == h1*3600+m1*60+s1) return true;
        else return false;

    }
