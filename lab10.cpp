#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	system("chcp 1251");
	int n, j, i = 0, k = 0;
	cout << "Количество строк:";
	string str; 
	cin >> n; 
	ofstream fout; // потоки для файлов
	ofstream xout;
	fout.open((char*)"stock.txt", ios_base::out);// открываем файлы
	xout.open((char*)"reverse.txt", ios_base::out);
	cout << "Напишите строку по-английски:" << endl; // вводим строку
	while (i < n) // идем пока количество строк не кончится
	{
		cin >> str;
		fout << str << endl; //записываемм в главный файл
		j = str.size() - 1; // берем последний не нулевой элемент 
		while (0 <= j) // идем с конца в начало
		{
			xout << str[j]; // сразу записываем элемент
			j--;
		}
		xout << endl;
		i++;
	}
	fout.close(); // закрываем файлы
	xout.close();
	system("pause");
	return 0;
}
