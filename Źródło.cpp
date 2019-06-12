#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Funkcje.h"


using namespace std;

int main()
{
	srand(time(NULL));
	int Ilosc_Tablic = 1;
	int Elementy_Tablicy = 10;
	clock_t start, stop;
	double czas;
	double procent = 0;
	start = clock();
	for (int i = 0; i < Ilosc_Tablic; i++)
	{
		int *Tablica = new int[Elementy_Tablicy];
		Posortowana(Tablica, Elementy_Tablicy, procent);
		//Odwroc_Tablice(Tablica, Elementy_Tablicy);
		HybridIntroSort(Tablica, Elementy_Tablicy);
		//QuickSort(Tablica, 0, Elementy_Tablicy - 1);
		//MergeSort(Tablica, 0, Elementy_Tablicy - 1);
		delete[] Tablica;
	}

	stop = clock();
	czas = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "Sredni czas wynosi :" << czas / Ilosc_Tablic;

	system("pause");
	return 0;
}