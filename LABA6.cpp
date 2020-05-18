#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

int fac(int num)
{
	if (num == 1)
		return 1;
	else
		return num == 0 ? 1 : num * fac(num - 1);
}

int f1(double* a, double* b, double *c) {
	double P = 0, S=0,p;
	if ((*a < *b + *c) && (*b < *c + *a) && (*c < *b + *a)) {
		P = *a + *b + *c;
		p = P / 2;
		S = sqrt(p * (p - *a) * (p - *b) * (p - *c));
		cout << "Периметр: " << P << " Площадь: " << S << endl;
		return 1;
	}
	else
		return 0;
	return 0;
}

int f2(int m,int n, float &pm, float &pd) {
	long double c;
	double p = 0.45, q = 1 - p;
	c = fac(n) / (fac(m) * fac(n - m));
	pd = c * pow(p, m) * pow(q, n - m);
	pm = c * pow(q, m) * pow(p, n - m);

	cout << "Из стольких людей: " << n << " Детей будет: " << m << " девочки\\мальчики: " << pd << "\\" << pm << endl;
	return 0;
}



int main() {
	system("chcp 1251<nul");
///////////////////////////////////////

	double a, b, c;
	cin >> a >> b >> c;
	f1(&a, &b, &c);

////////////////////////////////////////

	float pm, pd;
	int n,m;
	cin >> m >> n;
	f2(m, n, pm, pd);

	system("pause<nul");
	return 0;
}