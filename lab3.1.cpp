#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	system("chcp 1251>nul");
	srand(time(NULL));
		int n, neg = 0, pos = 0;
		int* b;
		cout << "Размер массива: ";
		cin >> n;
		b = (int*)malloc(n * sizeof(int));
		if (b == NULL) {
			cout << "задница: ";
			return 1;
		}
		for (int i = 0; i < n; i++) {
			b[i] = rand() % 100 - 50;
			if (b[i] < 0) {
				neg++;
			}
			else {
				pos++;
			}
		}
		int* c = (int*)malloc(pos * sizeof(int));
		int* d = (int*)malloc(neg * sizeof(int));
		for (int i = 0, m = 0, k = 0; i < n; i++) {
			if (b[i] < 0) {
				d[k] = b[i];
				k++;
			}
			else {
				c[m] = b[i];
				m++;
			}
		}
		cout << "a["<<n<<"]: ";
		for (int i = 0; i < n; i++) {
			cout << b[i] << ' ';
		}
		cout << endl;
		cout << "позитивы: ";
		for (int i = 0; i < pos; i++) {
			cout << c[i] << "  ";
		}
		cout << endl;
		cout << "негативы: ";
		for (int i = 0; i < neg; i++) {
			cout << d[i] << "  ";
		}
		cout << endl;
		delete[] c;
		c = NULL;
		delete c;
		delete[] d;
		d = NULL;
		delete d;
		delete[] b;
		b = NULL;
		delete b;
		system("pause>nul");
		return 0;
	}