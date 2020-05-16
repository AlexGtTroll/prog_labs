#include <ctime>

#include <cstdio>

#include <vector>

#include <cstdlib>

#include <iostream>

#include <algorithm>

using namespace std;

const int N1 = 100, N2 = 1000;

int print(vector<int> a1, vector<int> a2) {

cout << "Массив на одну сотню: ";

for (int i = 0; i < N1; ++i)

cout << a1[i] << " ";

cout << endl << endl << endl;

cout << "Массив на тысячу: ";

for (int i = 0; i < N2; ++i)

cout << a2[i] << " ";

cout << endl << endl << endl;

return 5051;

}

void sumup(int** b, int m, int n, vector<int>&sum) {

int counter = 0;

for (int i = 0; i < m; ++i)

{

counter = 0;

for (int j=0; j < n; ++j)

{

counter += b[i][j];

}

sum.push_back(counter);

}

}

void randomizer(int** &b, int &m, int &n)

{

for (int i = 0; i < m; ++i)

{

for (int j = 0; j < n; ++j)

{

b[i][j] = rand() % 20 + 1;

}

}

}

int task2(int** &b, int &m, int &n) {

for (int i = 0; i < m; ++i)

{

b[i][n] = 0;

}

vector<int>sum;

sumup(b,m,n, sum);

for (int i = 0; i < m; ++i)

{

b[i][n] = b[i][0];

}

for (int i = 0; i < m; ++i)

{

b[i][0] = sum[i];

}

return 0;

}

int beach(vector<int> &a1, vector<int> &a2)

{

int temp = 0;

for (int i = 0; i < N1-1; ++i)

{

for (int j = i + 1; j < N1; ++j)

{

if (a1[i] < a1[j])

{

temp = a1[i];

a1[i] = a1[j];

a1[j] = temp;

}

}

}

for (int i = 0; i < N2 - 1; ++i)

{

for (int j = i + 1; j < N2; ++j)

{

if (a2[i] < a2[j])

{

temp = a2[i];

a2[i] = a2[j];

a2[j] = temp;

}

}

}

return 0;

}

int binpos(vector<int> &a1, vector<int> &a2)

{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool yes = false;

int sr1 = 0, sr2 = 0, x;

int l = 0, r = N1 - 1, mid;

cout << "Ключ: ";

cin >> x;

while ((l <= r) && (yes != true)) {

mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

sr1++;

if (a1[mid] == x) { //проверяем ключ со серединным элементом

yes = true;

}

sr1++;

if (a1[mid] < x) { // проверяем, какую часть нужно отбросить

r = mid - 1;

}

else l = mid + 1;

}

if (yes) cout << "Индекс элемента " << x << " в массиве равен: " << mid;

else cout << "Соре, я вообще такого не нашел, зато ответ всегда знаю: пошел ты";

//////////////////////////////////////////////////////////////////////////////////////////////////////////

cout << endl << endl << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////

x = 0; l = 0; r = N2 - 1; mid = 0;

yes = false;

cout << "Ключ: ";

cin >> x;

while ((l <= r) && (yes != true)) {

mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

sr2++;

if (a2[mid] == x) { //проверяем ключ со серединным элементом

yes = true;

}

sr2++;

if (a2[mid] < x) { // проверяем, какую часть нужно отбросить

r = mid - 1;

}

else l = mid + 1;

}

if (yes) cout << "Индекс элемента " << x << " в массиве равен: " << mid;

else cout << "Соре, я вообще такого не нашел, зато ответ всегда знаю: пошел ты";

//////////////////////////////////////////////////////////////////////////////////////////////////////////

cout << endl << endl << endl << endl;

cout << "Количество сравнений в первом массиве: " << sr1 << endl;

cout << "Количество сравнений во втором массиве: " << sr2 << endl;

return 0;

}

int pos(vector<int> a1, vector<int> a2)

{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int fd = 0, x, ans1[N1], ans2[N2], sr1 = 0, sr2 = 0;;

cout << "Что хотите найти в первом массиве? ";

cin >> x;

for (int i = 0; i < N1; i++) {

sr1++;

if (a1[i] == x) { // проверяем равен ли a1[i] ключу

ans1[fd++] = i;

}

}

sr1++;

if (fd != 0) { // проверяем были ли совпадения

for (int i = 0; i < fd; i++) {

cout << "Ключ " << x << " находится в ячейке " << ans1[i] << endl; //выводим все индексы

}

}

else {

cout << "Мы не нашли ключ " << x << " в массиве";

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

cout << endl << endl << endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

fd = 0,x=0;

cout << "Что хотите найти во втором массиве? ";

cin >> x;

for (int i = 0; i < N2; i++) {

sr2++;

if (a2[i] == x) { // проверяем равен ли a2[i] ключу

ans2[fd++] = i;

}

}

sr2++;

if (fd != 0) { // проверяем были ли совпадения

for (int i = 0; i < fd; i++) {

cout << "Ключ " << x << " находится в ячейке " << ans2[i] << endl; //выводим все индексы

}

}

else {

cout << "Мы не нашли ключ " << x << " в массиве" << endl;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

cout << endl << endl << endl << endl;

cout << "Количество сравнений в первом массиве: " << sr1 << endl;

cout << "Количество сравнений во втором массиве: " << sr2 << endl;

return 0;

}

int main()

{

int m, n;

system("chcp 1251<nul");

srand(time(NULL));

vector<int>a1(N1); vector<int>a2(N2);

for (int i = 0; i < N1; ++i)

{

a1[i] = rand()%100;

}

for (int i = 0; i < N2; ++i)

{

a2[i] = rand() % 1000;

}

int x;

beach(a1, a2);

print(a1, a2);

pos(a1, a2);

binpos(a1, a2);

cout << "Теперь приступим ко второму заданию. Для этого введите количество строк и столбцов: " << endl;

cin >> m >> n;

int** b = new int* [m];

for (int i = 0; i < m; ++i)

{

b[i] = new int[n+1];

}

randomizer(b, m, n);

task2(b,m,n);

for (int i = 0; i < m; ++i)

{

for (int j = 0; j < n+1; ++j)

{

cout << b[i][j] << "\t";

}

cout << endl;

}

delete[] b;

cout << endl;

system("pause<nul");

return 0;

}