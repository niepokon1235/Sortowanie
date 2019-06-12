#include "Funkcje.h"

//Tworzy tabilce losowych elementow
void Generuj_Tablice(int *tablica, int elem)
{
	int zmienne = 2 * elem;
	for (int i = 0; i < elem; i++)
	{
		tablica[i] = rand() % zmienne;
	}
}

//Wyswietla tablice
void Pokaz_Tablice(int *tablica, int elem)
{
	for (int i = 0; i < elem; i++)
	{
		cout << tablica[i] << endl;
	}
}

//Od Najwiêkszego do najmniejszego
void Odwroc_Tablice(int *tablica, int elem)
{
	int j = 0;
	for (int i = elem - 1; i >= 0; i--)
	{
		
		tablica[j++] = i;
	}
}

//Przydziela kolejne wartosci okreslonemu procentowi tablicy 
void Posortowana(int *tablica, int elem, int procent)
{
	int pomocnik = (elem * procent) / 100;

	for (int i = 0; i < pomocnik; i++)
	{
		tablica[i] = i;
	}

	for (int i = pomocnik; i < elem; i++)
	{
		tablica[i] = (rand() % 500000 + pomocnik);
	}
}
//Zamienia elementy miejscami
void Zamien(int *Tablica, int i, int j)
{
	int temp;
	temp = Tablica[i];
	Tablica[i] = Tablica[j];
	Tablica[j] = temp;
}


//Scalanie, tworzy nowa tablice wzglednie ja sortujac.
void Merge(int * tablica, int pierwszy, int srodek, int elem)        
{
	int *pom_tab = new int[elem + 1]; //Tworzy nowa tablice, +1 bo sort -1    

	for (int i = pierwszy; i <= elem; i++) pom_tab[i] = tablica[i]; //Uzupelnia o elementy sortowanej

	int i = pierwszy; //poczatek nowej tablicy
	int j = srodek + 1; //srodek nowej tablicy
	int k = pierwszy; //poczatek sortowanej tablicy

	while (i <= srodek && j <= elem) //petla porownuje element poczatkowy i srodkowy nowej tablicy
	{                                //uzupelnia stara tablice 
		if (pom_tab[i] < pom_tab[j]) 
		{
			tablica[k] = pom_tab[i];
			i++;
			k++;
		}
		else
		{
			tablica[k] = pom_tab[j];
			j++;
			k++;
		}
	}

	while (i <= srodek) //Uzupelnia tablice nieprzydzielonymi wartosciami z poczatku nowej tablicy
	{
		tablica[k] = pom_tab[i];
		i++;
		k++;
	}

	while (j <= elem) // Uzupelnia tablice nieprzydzielonymi wartosciami ze srodka nowej tablicy
	{
		tablica[k] = pom_tab[j];
		j++;
		k++;
	}

	delete[] pom_tab;
}

//Sortowanie przez scalanie, dzieli tablice na dwie mniejsze wzgledem srodka, nastepnie je scalajac
void MergeSort(int * tablica, int pierwszy, int elem)
{
	if (pierwszy < elem) 
	{
		int srodek = (elem + pierwszy) / 2;
		MergeSort(tablica, pierwszy, srodek); //Dzielenie lewej
		MergeSort(tablica, srodek + 1, elem); //Dzielenie prawej
		Merge(tablica, pierwszy, srodek, elem); //Scalanie lewej i prawej
	}
}

//Zamienia elementy miejscami w ten sposob ze elementy mniejsze ida na lewa strone tablicy
//A	wieksze na praw¹, takie same zostaja w tym samym miejscu, nastepnie stosuje rekurencje
void QuickSort(int* tablica, int pierwszy, int elem)
{
	int srodek = tablica[(pierwszy + elem) / 2]; //punkt odniesienia
	int i = pierwszy;
	int j = elem;
	int pomocnik; // do zmiany elementu

	while (i <= j)
	{
		while (tablica[i] < srodek) i++; // indeks mniejszego od odniesienia
		while (tablica[j] > srodek) j--; // indeks wiekszego od odniesienia
		if (i <= j)
		{
			pomocnik = tablica[i]; //Zamiana miejscami
			tablica[i] = tablica[j];
			tablica[j] = pomocnik;
			i++;
			j--;
		}
	}
	// rekurencja do momentu uzyskania jednoelementowych tablic
	if (j > pierwszy) QuickSort(tablica, pierwszy, j);
	if (i < elem) QuickSort(tablica, i, elem);
}

//Podzia³ tablicy na dwie czêœci, w której jedna jest mniejsza od wybranej wartosci
//A druga wieksza
/*
int Partition(int * tablica, int pierwszy, int elem)
{
	int odniesienie = tablica[elem]; //Element wzglêdem którego dzielimy tablice na dwie czesci
	int i = pierwszy; 

	for (int j = pierwszy; j < elem; ++j) //Zmienna badajaca po kolei wszystkie wartosci
	{
		if (tablica[j] <= odniesienie) //Jezeli wartosc w tablicy jest mniejsza rowna wzgledem odniesienia
		{                              //To zamienia miejscami porownywana (i) z j sprawdzajaca wszystkie po kolei
			int pomocnik = tablica[j];
			tablica[j] = tablica[i];
			tablica[i] = pomocnik;
			i++;
		}
	}

	tablica[elem] = tablica[i]; //Wklada odniesienie w odpowiednie miejsce w tablicy
	tablica[i] = odniesienie;
	return i; //Zwraca punkt odniesienia
}
*/
// Najwiekszy element kopca, polega na porownaniu trzech elementow, w ktorym dwa sa
// odlamami (lewy i prawy), glownego na ktorym jest indeks 
void MaxHeapify(int* tablica, int wkopca, int wskaznik) 
{
	int lewy = (wskaznik + 1) * 2 - 1;
	int prawy = (wskaznik + 1) * 2;
	int najwiekszy = 0;

	if (lewy < wkopca && tablica[lewy] > tablica[wskaznik]) //Sprawdza czy lewy jest wiekszy od tego 
		najwiekszy = lewy;                                  //wartosci na wskazniku
	else
		najwiekszy = wskaznik;

	if (prawy < wkopca && tablica[prawy] > tablica[najwiekszy]) //Sprawdza czy prawy element jest najwiekszy
		najwiekszy = prawy;                                     //z 3

	if (najwiekszy != wskaznik) //Jezeli najwiekszy nie znajdzuje sie na wskazniku to zamienia 
	{                            //miejscami najwiekszy i wskaznik
		int temp = tablica[wskaznik];
		tablica[wskaznik] = tablica[najwiekszy];
		tablica[najwiekszy] = temp;

		MaxHeapify(tablica, wkopca, najwiekszy); //stosuje rekurencje w celu stworzenia kopca
	}
}

//Kopcowanie, buduje kopiec przestawiajac tablice
//wyciaga pojedynczo elementy z kopca
//przenosi obecny korzen na koniec
//wywoluje Max heapify na zredukowanym kopcu
void HeapSort(int* tablica, int elem)
{
	int wkopca = elem;

	for (int i = (wkopca - 1) / 2; i >= 0; --i) //Petla ostatniego elementu do korzenia, tworzy kopiec binarny
		MaxHeapify(tablica, wkopca, i);

	for (int j = elem - 1; j > 0; --j) // od ostatniego elementu do korzenia zamienia elementy miejscami 
	{                                  //najwiekszy daje na koniec tablicy i redukuje kopiec o 1 element
		int pomocnik = tablica[j];     //nastepnie rekurencja
		tablica[j] = tablica[0];
		tablica[0] = pomocnik;

		--wkopca;
		MaxHeapify(tablica, wkopca, 0);
	}
}

//Sortowanie przez wstawianie polega na porownywaniu kolejnych elementow z wszystkimi
//poprzednimi i wstawieniu go w odpowiednie pole
void InsertionSort(int* tablica, int elem) 
{
	int pomocnik; // w celu zamiany miejscami

	for (int i = 1; i < elem; ++i)
	{
		int j = i; 

		while (j > 0) // Tak dlugo az nie dojdzie do 1 elementu tablicy
		{
			if (tablica[j - 1] > tablica[j]) //miedzy obecna a poprzednia
			{
				pomocnik = tablica[j - 1]; //Zamienia miejscami po kolei elementy
				tablica[j-1] = tablica[j];
				tablica[j] = pomocnik;

				j--;
			}
			else
			{
				break;
			}
		}
	}
}

// Obsluguje najgorszy przypadek quicksorta, tak aby zapewnic logarytmiczno-liniowa zlozonosc obliczeniowa.
// Bada glebokosc rekurencji, glebokosc - maksymalna dozwolona glebokosc rekurencji z poziomu na ktorym sie
// obecnie znajdujemy. Glebokosc = 0, konczona rekurencja i wywo³uje Heapsort. Dla Glebokosc > 0 wywoluje
// partition ktory dziala podobnie jak quicksort, dzieli tablice na dwie czesci w ktorej sa wieksze i mniejsze
//elementy od wybranej wartosci, nastepnie rekurencyjnie introsort z paramtrem glebokosci pomniejszonym o 1.
//Dzieki temu dla najgorszego przypadku sie zatrzymuje i wywoluje heapsorta
void IntroSort(int *tablica, int elem, int glebokosc)
{
	int i;
	if (glebokosc <= 0)
	{
		HeapSort(tablica, elem-1);
		return;
	}
	i = Partition(tablica, 0, elem);
	if (i > 9)
		IntroSort(tablica, i, glebokosc - 1);
	if (elem - 1 - i > 9)
		IntroSort(tablica + i + 1, elem - 1 - i, glebokosc - 1);
}
//okresla maksymalna glebokosc wywolan rekurencyjnych
void HybridIntroSort(int *tablica, int elem)
{
	IntroSort(tablica, elem, floor(2 * log(elem) / 0.693147)); //0.693 - maksymalna glebokosc dla tego algorytmu
	InsertionSort(tablica, elem);
}

//Dziala jak quicksort, przenosi na lewo i prawo wzgledem punktu odniesienia
int Partition(int *tablica, int pierwszy, int elem)
{
	int i, j;
	if (elem >= 3)
		MedianOfThree(tablica, pierwszy, elem); //Tworzy punkty odniesienia
	for (i = pierwszy, j = elem - 2; ; )
	{
		for (; tablica[i] < tablica[elem - 1]; ++i); //Je¿eli skrajnie lewa jest mniejsza od prawej to zwiêksz indeks lewej
		for (; j >= pierwszy && tablica[j] > tablica[elem - 1]; --j); //porównuje koncowe elementy tablicy i zmniejsza indeks
		if (i < j)                                                 //je¿eli ostatni jest wiekszy od przedostatniego                                  
			Zamien(tablica, i++, j--); //zamienia miejscami "i" i "j"
		else break;
	}
	Zamien(tablica, i, elem - 1); //wklada odniesienie w odpowiednie miejsce
	return i; //Zwraca punkt odniesienia
}
//Funkcja ktora wzglêdnie tworzy punkty odniesienia w tablicy
void MedianOfThree(int *tablica, int &pierwszy, int &elem)
{
	if (tablica[++pierwszy - 1] > tablica[--elem]) //Porównuje 1 i ostatni element (pierwszy tablicy 0)
		Zamien(tablica, pierwszy - 1, elem);
	if (tablica[pierwszy - 1] > tablica[elem / 2]) //Porównuje 1 i œrodkowy element
		Zamien(tablica, pierwszy - 1, elem / 2);
	if (tablica[elem / 2] > tablica[elem]) //Porównuje œrodkowy i ostatni 
		Zamien(tablica, elem / 2, elem);
	Zamien(tablica, elem / 2, elem - 1); //Zamienia œrodkowy z przedostatnim
}
