#pragma once
/*
PSS lab1 Pawel Smieja
Kod klasy SISO i jej funkcji
Model ARX
*/
#include <vector>
#include <algorithm>
using namespace std;

class SISO {
	friend class Regulator;

public:			//czesc dostepna dla wszystkich
	SISO(); //konstruktor

	int n_pocz;
	vector<double> wej; //wektor wejsc
	vector<double> wyj; //wektor wyjsc
	int ustawStopnie(int ndA, int ndB, int nk); //wstawienie nowych wartosci stopni
	void zaktualizujWej(double wejscie); //wpisanie nowej wartosci wejscia z klawiatury do tablicy
	double symuluj(); //Obliczanie wyjscia modelu ostatniej iteracji
	//~SISO(); //destruktor

protected:		//czesc dostepna dla klas pochodnych
	int dA, dB, k;

private:		//czesc dostepna tylko dla klasy
	double *paramA, *paramB; //wartosci wspolczynnikow parametrow

};


SISO::SISO()
{
	paramA = new double[dA];
	paramB = new double[dB + k];
	*paramA = (1.0, 0.5);
	*paramB = (-0.5);

	n_pocz = max(dB+k, dA); //liczba poczatkowych wartosci wektorow ma byc rowna '0'
	//Wpisanie poczatkowych wartosci wejsc i wyjsc
	for (int i=0; i<n_pocz; i++) 
	{ 
		wej.at(i) = 0.0;
		wyj.at(i) = 0.0;
	}


	//Chwilowe wpisanie automatyczne wartosci wejsc, zeby sprawdzic, czy bedzie dzialac
	/* 
	wej.at(0) = 0.0; wej.at(1) = 0.0; wej.at(2) = 1.0; wej.at(3) = 3.0; wej.at(4) = 2.0;
	wej.at(5) = 1.0; wej.at(6) = 2.0; wej.at(7) = 1.0; wej.at(8) = 2.0; wej.at(9) = 3.0;
	*/
	}


void SISO::zaktualizujWej(double wejscie)
{
	wej.push_back(wejscie);
}


//Do wykorzystania w przyszlosci jak bedzie sie wprowadzac stopnie przez klawiature
int SISO::ustawStopnie(int ndA, int ndB, int nk) 
{
	dA = ndA; //stopien mianownika
	dB = ndB; //stopien licznika
	k = nk; //opoznienie
	return 0;
}


double SISO::symuluj()
{
	// y(i) = -0.5*u(i-1) - 0.5*y(i-1)
	double wyjscie = 0.0, u1 = 0.0, y1 = 0.0;
	//wyjscie = -0.5*wej.at(wej.end - 1) - 0.5*wyj.at(wyj.end); // wersja 1 - ma problemy
	//wyjscie = -0.5*wej[wej.end - 1] - 0.5*wyj[wyj.end]; // wersja 2 - ma problemy
	//wyjscie = -0.5 * wej[1] - 0.5 * wyj[1]; // wersja 3 - zbuildowalo sie! Ale iteratory sa niepraktyczne
	
	u1 = *wej.end; //tu ma problem
	y1 = wyj.end; //tu ma problem
	wyjscie = -0.5 * wej[u1 - 1] - 0.5 * wyj[y1 - 1]; // wersja 4
	
	wyj.push_back(wyjscie);

	return wyjscie;
}
