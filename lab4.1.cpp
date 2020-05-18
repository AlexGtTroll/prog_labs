#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;


void task1() {
	int m = 5, n, stl,str,k=0;
	cout << "Количество столбцов: "; cin >> n; cout << endl;
	int** b = new int* [m];
	for (int i = 0; i < m; ++i)
	{
		b[i] = new int[n];
	}
	int** c = new int* [m - 1];
	for (int i = 0; i < m - 1; ++i)
	{
		c[i] = new int[n - 1];
	}

	////////////////////////////////////////////KAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEM

	for (int i = 0; i < m; ++i) 
	{
		for (int j = 0; j < n; ++j)
		{
			b[i][j] = rand() % 20 + 1;
		}
	}

	//////////////////////////////////Заполнили/////////////////////////////////////////////////////////////////

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}
	int max = b[0][0];

	do {
		cout << endl;
		k++;
	} while (k < 3);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (b[i][j] > max) 
			{
				max = b[i][j];
				str = i;
				stl = j;
			}
		}
	}

	int ii = 0;

	for (int i = 0; i < m - 1; i++, ++ii)
	{
		if (str == ii)
			++ii;
		int jj = 0;
		for (int j = 0; j < n - 1; j++, ++jj)
		{
			if (jj == stl)
				++jj;
			c[i][j] = b[ii][jj];
		}
	}

	for (int i = 0; i < m-1; ++i) {
		for (int j = 0; j < n-1; ++j) {
			cout << c[i][j] << "\t";
		}
		cout << endl;
	}

	k = 0;

	do {
		cout << endl;
		k++;
	} while (k < 3);
	////////////////////////////////////////////ЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМ
	for (int i = 0; i < m; ++i)
	{
		delete [] b[i];
	}
	delete[] b;

	for (int i = 0; i < m-1; ++i)
	{
		delete [] c[i];
	}
	delete[] c;
}

void task2() {
	int m, n, dia=0, k=0;

	cout << "Количество строк: "; cin >> m; cout << endl;
	cout << "Количество столбцов: "; cin >> n; cout << endl;

	vector<int>colon(n);
	vector<int>rows(m);

	int** b = new int* [m];
	for (int i = 0; i < m; ++i)
	{
		b[i] = new int[n];
	}

	int** c = new int* [m + 1];
	for (int i = 0; i < m + 1; ++i)
	{
		c[i] = new int[n + 1];
	}
	////////////////////////////////////////////KAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEMKAKAEM
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			b[i][j] = rand() % 20 + 1;
		}
	}
	/////////////////////////////////Заполнили/////////////////////////////////////////////////////
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}

	do 
	{
		cout << endl;
		k++;
	} while (k < 3);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c[i][j] = b[i][j];
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dia += b[i][j];
		}
	}

	int counter1 = 0, counter2 = 0;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			rows[counter1] += b[i][j];                 //сумма по строкам
		}
		counter1++;
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			colon[counter2] += b[j][i];                 //сумма по столбам
		}
		counter2++;
	}

	/*for (int i = 0; i < counter1; ++i)
		cout << rows[i] << " ";
	cout << endl;*/

	/*for (int i = 0; i < counter2; ++i)
		cout << colon[i] << " ";
	cout << endl;*/

	for (int i = 0; i < m; ++i)
	{
		c[i][n] = rows[i];
	}

	for (int i = 0; i < n; ++i)
	{
		c[m][i] = colon[i];
	}

	c[m][n] = dia;

	for (int i = 0; i < m + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			cout << c[i][j] << "\t";
		}
		cout << endl;
	}



	////////////////////////////////////////////ЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМЧИСТИМ
	for (int i = 0; i < m; ++i)
	{
		delete[] b[i];
	}
	delete[] b;

	for (int i = 0; i < m + 1; ++i)
	{
		delete[] c[i];
	}
	delete[] c;
}



int main() {
	system("chcp 1251<nul");
	cout << "ДИСКЛЕЙМЕР:" << endl << "Данный код написан далеко не профи. Автор не хочет кого-либо оскорбить, задеть" << endl <<
		"чьи-либо чувства в какой-либо степени. Все совпадения случайны, а сам автор является умственно отсталым." << endl <<
		"Обижая автора, вы обижаете больного человека. Будьте бдительны и не допускайте подобного поведения." << endl;
	cout << endl << "Первая программа" << endl;
	task1();
	cout << endl << "Вторая программа" << endl;
	task2();
	system("pause<nul");
	return 0;
}

