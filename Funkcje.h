#pragma once
#ifndef Funkcje_h
#define Funkcje_h
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

void Generuj_Tablice(int * tablica, int elem);
void Pokaz_Tablice(int * tablica, int elem);
void Odwroc_Tablice(int * tablica, int elem);
void Posortowana(int * tablica, int elem, int procent);
void Merge(int * tablica, int pierwszy, int srodek, int elem);
void MergeSort(int * tablica, int pierwszy, int elem);
//int Partition(int * tablica, int pierwszy, int ostatni);
void QuickSort(int* tablica, int pierwszy, int elem);
void MaxHeapify(int* tablica, int wkopca, int wskaznik);
void HeapSort(int* tablica, int elem);
void InsertionSort(int* tablica, int elem);
int Partition(int *tablica, int pierwszy, int elem);
void MedianOfThree(int *tablica, int &pierwszy, int &elem);
void Zamien(int *Tablica, int i, int j);
void IntroSort(int *Tablica, int N, int M);
void HybridIntroSort(int *Array, int N);
#endif
