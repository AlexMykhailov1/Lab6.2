// Lab6.2.cpp
// Михайлов Олександр
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 24*

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <time.h>

using namespace std;

void CreateIter(int mas[], const int n, const int Min, const int Max) {
	for (int i = 0; i < n; i++) {
		mas[i] = Min + rand() % (Max - Min + 1);
	}
}

void PrintIter(int mas[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << mas[i] << "  ";
	}
	cout << endl << endl;
}

void SortIter(int mas[], const int n) {
	for (int i = 0; i < n - 1; i++) {
		int maxElem = mas[i];
		int indexMaxElem = i;
		for (int j = i + 1; j < n; j++) {
			if (mas[j] > maxElem) {
				maxElem = mas[j];
				indexMaxElem = j;
			}
		}
		mas[indexMaxElem] = mas[i];
		mas[i] = maxElem;
	}
}

void CreateRekurs(int mas[], const int n, const int Min, const int Max, int i)
{
	mas[i] = Min + rand() % (Max - Min + 1);
	if (i < n - 1)
		CreateRekurs(mas, n, Min, Max, i + 1);
}

void PrintRekurs(int mas[], const int n, int i)
{
	cout << mas[i] << "  ";
	if (i < n - 1)
		PrintRekurs(mas, n, i + 1);
	else
		cout << endl << endl;
}

void FindMaxRekurs(int mas[], const int n, int i, int& maxElem,int& indexMaxElem , int j) {
	if (mas[j] > maxElem) {
		maxElem = mas[j];
		indexMaxElem = j;
	}
	if (j < n - 1)
		FindMaxRekurs(mas, n, i, maxElem, indexMaxElem, j + 1);
}

void SortRekurs(int mas[], const int n, int i) {
	int maxElem = mas[i];
	int indexMaxElem = i;

	FindMaxRekurs(mas, n, i, maxElem, indexMaxElem, i + 1);

	mas[indexMaxElem] = mas[i];
	mas[i] = maxElem;
	if (i < n - 2) {
		SortRekurs(mas, n, i + 1);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int Min, Max;
	int n;
	cout << "Введіть мінімальне можливе значення у масиві: "; cin >> Min;
	cout << "Введіть максимальне можливе значення у масиві: "; cin >> Max;
	cout << "Введіть кількість елементів масива: "; cin >> n;
	cout << endl;

	
	int* a = new int[n];

	// Ітераційний 1) Create 2) Print 3) Sort 4) Print
	cout << "Ітераційний спосіб:" << endl << endl;
	CreateIter(a, n, Min, Max);
	PrintIter(a, n);
	SortIter(a, n);
	PrintIter(a, n);

	// Рекурсивний 1) Create 2) Print 3) Sort 3.1) FindMax 4) Print
	cout << "Рекурсивний спосіб:" << endl << endl;
	CreateRekurs(a, n, Min, Max,0);
	PrintRekurs(a, n, 0);
	SortRekurs(a, n, 0);
	PrintRekurs(a, n, 0);

	cin.get();
	delete[]a;
	return 0;
}