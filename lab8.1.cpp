#include <cstdlib>

#include <iostream>

#include <cstdio>

using namespace std;

struct school

{

int number;

int graduate;

int entered;

};

void IndexSort(school a[], int n, int* B)

{

int i, j, t = 0;

for (i = 0; i < n; i++)

{

B[i] = i;

}

for (i = 0; i < n - 1; i++)

{

for (j = i + 1; j < n; j++)

{

if ((a[B[i]].entered * 100) / a[B[i]].graduate < (a[B[j]].entered * 100) / a[B[j]].graduate)

{

t = B[i];

B[i] = B[j];

B[j] = t;

}

}

}

}

int main()

{

system("chcp 1251<nul");

int i, n;

cin >> n;

float x;

school numb;

school* a = new school[n];

int* b = new int[n];

for (i = 0; i < n; i++)

{

cout << "введите номер, окончивших, поступивших:";

cin >> a[i].number >> a[i].graduate >> a[i].entered;

}

IndexSort(a, n, b);

for (i = 0; i < n; i++)

{

x = (a[b[i]].entered * 100) / a[b[i]].graduate;

cout << a[b[i]].number << " выпустившихся: " << a[b[i]].graduate << endl << "процент поступивших: " << x << endl;

}

delete[] a;

delete[] b;

system("system<pause");

}