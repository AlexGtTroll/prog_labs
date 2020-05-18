#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	system("chcp 1251>nul");
	int n;
	cout << "Введите предел вашей жизни: "; cin >> n; cout << endl;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	for (int i = 2; i < n; ++i)
	{
		if (a[i] != 0)
		{
			cout << a[i] << " ";
			for (int j = i * i; j < n; j += i)
			{
				a[j] = 0;
			}
		}
	}
	delete[] a;
	system("pause>nul");
	return 0;
}