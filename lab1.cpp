/*1.	Написать функцию возведения в степень y=xⁿ, где n – 
целое положительное или отрицательное число;
x –  вещественное число. Использовать цикл.*/

#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

void ochkozavr(int n, double x) {
	double ans1 = x;
	double ans2 = 1;
	if (n > 0) {
		for (int i = 1; i < n; ++i)
			ans1 *= x;
		cout << ans1 << endl;
	}
	else if (n < 0) {
		for (int i = 1; i < n; ++i)
			ans1 *= x;
		ans2 = ans2 / ans1;
		cout << ans2 << endl;
	}
	else if (n == 0)
		cout << 1 << endl;
}

int main() {
	system("chcp 1251>nul");
	cout << "Введите степень и число, спасибо благодарю" << endl;
	int n;
	double x;
	cin >> n >> x;
	ochkozavr(n, x);
	system("pause>nul");
	return 0;
}
