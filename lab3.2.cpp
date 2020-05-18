#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

void SelectSort(double* a[], int n) {
	double* t;
	int k;
	for (int i = 0; i < n - 1; ++i) {
		k = i;
		for (int j = i + 1; j < n; ++j) {
			if (*a[j] < *a[k])
				k = j;
		}
		t = a[i];
		a[i] = a[k];
		a[k] = t;
	}
}

int main() {
	system("chcp 1251>nul");
	int n;
	cout << "Количество элементов в массиве: "; cin >> n; cout << endl;
	double *a = new double [n];
	double* *b = new double*[n];
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		a[i] = (double)rand()*(5)/RAND_MAX+1;
	for (int i = 0; i < n; ++i)
		b[i] = &a[i];
	cout << "Массив исходный: ";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
	cout << endl << "Адреса: ";
	for (int i = 0; i < n; ++i)
		cout << b[i] << " ";
	cout << endl;
	SelectSort(b,n);
	cout << endl << "Выкаканый массив: ";
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << endl << endl << "Мой дед с лупой перевел в человеческий: ";
	for (int i = 0; i < n; i++) {
		cout << *b[i] << " ";
	}
	cout << endl << endl;
	delete[] a;
	delete[] b;
	system("pause>nul");
	return 0;
}