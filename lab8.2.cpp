#include <cstdio>

#include <cstdlib>

#include <iostream>

#include <set>

#include <string>

using namespace std;

struct home {

int kom;

int pl;

string fk;

int neigh;

};

int main() {

system("chcp 1251<nul");

set <string> uniq;

int n;

cout << "Введите число комнат: " << endl;

cin >> n;

home ae;

home* a = new home[n];

for (int i = 0; i < n; i++) //цикл ввода данных о комнатах

{

cin.clear();

cin.get();

cout << "Введите номер комнаты: " << endl;

cin >> a[i].kom;

cin.ignore();

cout << "Введите площадь: " << endl;

cin >> a[i].pl;

cin.ignore();

cout << "Введите факультет: " << endl;

cin >> a[i].fk;

uniq.insert(a[i].fk);

cout << "Введите количество проживающих: " << endl;

cin >> a[i].neigh;

cin.ignore();

}

int x;

set <string> ::iterator it = uniq.begin();

x = uniq.size();

string* b = new string[x];

for (int i = 0; i < uniq.size(); ++i) {

b[i] = *it;

it++;

}

int y = 0,k=0;

double z = 0;

for (int i = 0; i < uniq.size(); i++){

y = 0;

z = 0;

k = 0;

cout << "факультет: " << b[i] << endl;

for (int j = 0; j < n; j++)

{

if (b[i] == a[j].fk) {

k++;

y += a[j].neigh;

z += a[j].pl;

}

}

cout << "количество комнат: " << k << endl;

cout << "студентов: " << y << endl;

cout << "%площадь на студента: " << z / y << endl;

}

delete[] a;

delete[] b;

system("pause<nul");

}