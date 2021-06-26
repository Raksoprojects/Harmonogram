#include "Harmonogram.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;


int main() {

	Czas czas1(0,5,0);
    Czas czas2(0,10,0);
	Czas czas3(0,15,0);
	Czas czas4(0,20,0);
	Czas czas5(0,30,0);
	Harmonogram h1;
	h1.DodajCzas(czas1);
	h1.DodajCzas(czas2);
	h1.DodajCzas(czas3);
	h1.DodajCzas(czas4);
	h1.DodajCzas(czas5);
	
	vector<Harmonogram> harmonogramy;
	harmonogramy.push_back(h1);
	char input;
	bool koniec = false;
	int ktory = 0;
	int n =0;
	int godzina;
	int minuta;
	int sekunda;
	int wydarzenie = 0;
	int wybor = 0;
	Harmonogram harmo_pom;
	Czas czas_pom;

	while(!koniec){
		system("CLS");
		cout<<"Wybrany zostal harmonogram "<<ktory+1<<" zawierajacy "<<harmonogramy[ktory].ileCzasow()<<" wydarzen" <<endl;
		cout<<"Mamy utworzone "<< harmonogramy.size() << " harmonogramy\n";
		cout<<"1 - Kopia harmonogramu do n-tego elementu\n";
		cout<<"2 - Kopia harmonogramu do zadanego czasu\n";
		cout<<"3 - Wybierz wydarzenie do dodania sekund\n";
		cout<<"4 - Wybierz harmonogram\n";
		cout<<"5 - Wypisz harmonogram\n";
		cout<<"6 - Dodaj wydarzenie do wybranego harmongramu\n";
		cout<<"7 - Zakoncz\n";
		cout<<"Wprowadz input: ";
		cin>>input;
		switch(input)
		{
			case '1': //Kopia harmonogramu do n'tego elementu
				cout<<"Podaj ile wydarzen skopiowac do nowego harmonogramu: ";
				cin>>n;
				// Sprawdzamy czy tyle czasów mamy, takie pętlę też w resczie miejsc można pododawać
				while(int(n)>=harmonogramy[ktory].ileCzasow()){
					cout<<"Error! Bledny input! Sprobuj ponownie\n";
					cout<<"Podaj ile wydarzen skopiowac do nowego harmonogramu: ";
					cin>>n;
				}
				harmo_pom.kopiuj_n(harmonogramy[ktory], n);
				harmonogramy.push_back(harmo_pom);
				harmo_pom.usun_harmo();
				break;
			case '2': // Kopia harmonogramu do zadanego czasu
				cout<<"Podaj godzine: ";
				cin>>godzina;
				// Takie pętlę pododawać w reszcie punktó, sprawdzają czy użytkownik podał liczbę
				while (cin.fail())
				{	
					cin.clear();
					cin.ignore(256,'\n');
					cout<<"Podaj godzine: ";
					cin>>godzina;
				} 
				
				cout<<"Podaj minute: ";
				cin>>minuta;
				while (cin.fail())
				{	
					cin.clear();
					cin.ignore(256,'\n');
					cout<<"Podaj minute: ";
					cin>>minuta;
				} 
				cout<<"Podaj sekunda: ";
				cin>>sekunda;
				while (cin.fail())
				{	
					cin.clear();
					cin.ignore(256,'\n');
					cout<<"Podaj sekunde: ";
					cin>>sekunda;
				} 
				czas_pom.ustaw3(sekunda,minuta,godzina);
				harmo_pom.kopiuj_do_suma(harmonogramy[ktory], czas_pom);
				if(!harmo_pom.getharmo().empty()) harmonogramy.push_back(harmo_pom);
				harmo_pom.usun_harmo();
				break;	
			case '3': // Wybierz czas do dodania sekund
				cout<<"Podaj do ktorego wydarzenia mamy dodac sekundy: ";
				cin>>wydarzenie;
				while(harmonogramy[ktory].ileCzasow()>wydarzenie-1 || cin.fail()){
					cin.clear();
					cin.ignore(256,'\n');
					cout<<"Podaj do ktorego wydarzenia mamy dodac sekundy: ";
					cin>>wydarzenie;
				}
				//tu dodac
				cout<<"Podaj ile sekund dodac: ";
				cin>>sekunda;
				while (cin.fail())
				{	
					cin.clear();
					cin.ignore(256,'\n');
					cout<<"Podaj godzine: ";
					cin>>sekunda;
				} 
				harmonogramy[ktory].dodaj_sekundy(wydarzenie-1,sekunda);
				break;
			case '4': // Wybierz harmonogram
				cout<<"Wybierz harmonogram (1-"<<harmonogramy.size()<<"): ";
				cin>>wybor;
				ktory = wybor-1;
				break;
			case '5': // Wypisz harmonogram
				harmonogramy[ktory].wypisz();
				system("pause");
				break;
			case '6': // Dodaj wydarzenie
				cout<<"Podaj godzine: ";
				cin>>godzina;
				cout<<"Podaj minute: ";
				cin>>minuta;
				cout<<"Podaj sekunda: ";
				cin>>sekunda;
				czas_pom.ustaw3(sekunda,minuta,godzina);
				harmonogramy[ktory].DodajCzas(czas_pom);
				break;		
			case '7': //Zakończ
				koniec = true;
				break;
			default:
				koniec = true;
				cout<<"Error: Wproawdzono błędny input!\n";
				break;	
		}
	}


	return 0;
}