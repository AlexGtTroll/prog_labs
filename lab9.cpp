#include <iostream>
#include <string>
#include <ctime>

using namespace std;

typedef struct student // структура студентов с фамилиями оценками и указателем
{
    string name;
    int mark1, mark2, mark3, mark4;  
    struct student* prev;
    struct student* next;
} journal;

journal* create(void) // функция создания списка
{
    journal* p = NULL, * pred = NULL, * tail = NULL, * h = NULL;    /// pred - указатель на предыдущ. структуру, h - на первую структуру
    int N, counter = 0;
    cout << "Количество студентов: ";
    cin >> N;
    h = pred = new journal;     //выделение памяти для первой структуры
    int s = 0;
    cout << endl;
    pred->next = p;       /// ссылка из предыдущей на текущую
    string fam[10] = {"Aldinger", "Belonogov", "Stepanov", "Levkin", "Gulaya", "Shkuratov", "Petrov", "Kochev", "Fadin"};

    while (counter < N)  /// заполняем 
    {
        p = new journal;
        p->name = fam[rand() % 9];   /// рандомим фамилии, никакой уникальности в угоду бОльшему кол-ву студентов.
        p->mark1 = rand() % 4 + 2;  p->mark2 = rand() % 4 + 2;  p->mark3 = rand() % 4 + 2;  p->mark4 = rand() % 4 + 2;
        pred->next = p;
        p->prev = pred;
        pred = p;       //сохраняем адрес текущей структуры
        counter++;
    };
    cout << endl;
    pred->next = 0;
    p->next = NULL;
    return h;
}
void watch(journal* head) // функция просмотра списка
{
    journal* p;
    int s = 0;
    p = head->next;
    cout << endl
        << "Фамилия и четыре оценки: " << endl;
    while (p != NULL)   /// пока не конец списка - выводим.
    {
        cout << p->name << " " << p->mark1 << " " << p->mark2 << " " << p->mark3 << " " << p->mark4 << endl;
        p = p->next;
    }
}
void deletejo(journal* head) // освобождение памяти
{
    journal* p, * r;
    r = p = head;
    while (p != NULL)   // пока не конец списка - чистим. Вполне логично
    {
        p = r->next;
        r = NULL;
        delete r;
        r = p;
    }
    head = NULL;
}
journal* otsort(journal* head) // сортировка списка
{
    int s = 0;
    journal* p, * r, * t;
    p = head->next;
    while (p != NULL)
    {
        if (p->mark1 < 3 || p->mark2 < 3 || p->mark3 < 3 || p->mark4 < 3)           // циклично сравниваем каждую оценочку
        {
            if (p == head)
            {
                t = p;
                head = p->next;
                p = head;
                t = NULL;
                delete t;
            }
            if (p->next == 0)
            {
                t = p;
                p = p->prev;
                p->next = NULL;
                t = NULL;
                delete t;
                cout << "Видимо, хорошисты отсутствуют" << endl;
                exit(0);   /// Если не окажется хорошистов, то программа прекращает работу.
            }
            else
            {
                t = p;
                p = p->prev;
                p->next = t->next;
                p = p->next;
                p->prev = t->prev;
                t = NULL;
                delete t;
            }
        }
        else
            p = p->next;
    }
    return head;
}
int main()
{
    srand(time(NULL));
    system("chcp 1251<nul");
    journal* head;         ///Адрес головы списка
    head = create();
    cout << endl
        << "До сортировки: " << endl;
    watch(head);
    otsort(head);
    cout << endl
        << "После: " << endl;
    watch(head);
    deletejo(head);
    cout << endl;
    return 0;
    system("pause<nul");
}