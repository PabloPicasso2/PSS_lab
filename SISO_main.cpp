/*
PSS lab1 Pawel Smieja
Stworzyc obiekt ARX, zasymulowac SISO
*/

#include "klasa_SISO.h"
#include <iostream>

using namespace std;



int main()
{
	int ndA = 2, ndB = 0, k = 1;
	double wejscie1 = 0.0, wyjscie1 = 0.0;
	SISO arx1;

	cout << "Program do symulacji modelu ARX" << endl;
	cout << "Wprowadz stopnie wielomianow" << endl << "ndA: ";
	cin >> ndA;
	cout << endl << "ndB: ";
	cin >> ndB;
	cout << endl << "k: ";
	cin >> k;
	arx1.ustawStopnie(ndA, ndB, k);

	cout << endl << endl << "Wpisz wejscie (typu double): ";
	cin >> wejscie1;

	arx1.zaktualizujWej(wejscie1); //przekazanie nowego wejscia do wektora wejsc
	wyjscie1 = arx1.symuluj();
	cout << endl << "Wyjscie: " << wyjscie1;
	
	getchar(); //lepszy zamiennik system("pause");
	return 0;
}