/*2.	Написать функцию вычисления cosinus с помощью ряда Тейлора
cosinus(x) =1 - x2/2! + x4/4! … + ((-1)n *x2n)/(2n!)  с точностью до eps=0.0001.
В качестве параметра передать x.
Сравнить полученное значение со значением стандартной функции cos(x)*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void cosisinus(double x) {
	int n = 2;
	double ans = ' ';
	double a = -1, s = 1, d = 2, fak = 2, epsilon = 0.0001;;
	double step = x * x;
	do {
		s += a * step / fak;
		d += 2; // 2
		step *= x*x;
		a *= (-1);
		fak *= (d - 1) * d;
	} while (epsilon <= abs(step / fak));
	ans = s;
	cout << "Через Тейлора, но который МакЛорен: " << ans << endl;
}

double cosin(double x) {
	double a = 1.0, b = 1.0;
	 int i = 2;
	while (fabs(b) > 0.0001) {
		b *= (-1) * x*x;
		b = b / (i * (i - 1));
		a += b;
		i += 2;
		
	}
	return a;
}

int main() {
	system("chcp 1251>nul");
	double x = 0;
	cout << "Введите значение аргументА: ";
	cin >> x;
	cout << endl;
	cosisinus(x);
	cout <<"Не моя "<< cosin(x) << endl;
	cout << "Через миллионы лет эволюции языка Сци: " << cos(x) << endl;
	system("pause>nul");
return 0;
}